/**
* Programme cree une liste de jeux et affiche les informations de chaques jeux
* \file   main.cpp
* \author Édourard Allaire et Aliou Banire Diallo
* \date	  25 février 2026
* Créé le 13 février 2026
*/
#include <iostream>
#include <fstream>
#include <ostream>
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
using namespace std;


//TODO: Vos surcharges d'opérateur <<
ostream& operator<<(ostream& os, const Concepteur& concepteur) {
	os << "\t" << concepteur.getNom() << ", " << concepteur.getAnneeNaissance() << ", " << concepteur.getPays()
		<< endl;
	return os;
}

ostream& operator<< (ostream& os, const Jeu& jeu) {
	os << "Titre : " << "\033[94m" << jeu.getTitre() << "\033[0m" << endl
		<< "Parution : " << "\033[94m" << jeu.getAnneeSortie() << "\033[0m"
		<< endl
		<< "Développeur :  " << "\033[94m" << jeu.getDeveloppeur() << "\033[0m"
		<< endl
		<< "Concepteurs du jeu :" << "\033[94m";

	const ListeConcepteurs& liste = jeu.getListeConcepteur();
	for (unsigned i = 0; i < liste.size(); i++) {
		os << *liste[i];
	}
	return os;
}

ostream& operator<<(ostream& os, const ListeJeux& listeJeux) {
	static const string ligneSeparation =  "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	for (unsigned i = 0; i < listeJeux.size(); i++) {
		os << ligneSeparation;
		os << *listeJeux[i];
	}
	os << ligneSeparation;
	return os;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi(); 
	#pragma endregion
	
	ListeJeux listeJeux = creerListeJeux("jeux.bin");
	static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	//TODO: L'affichage de listeJeux et l'écriture dans le fichier devraient fonctionner.
	cout << listeJeux << ligneSeparation;

	ofstream fichier("ListeJeux.txt");
	if (fichier.is_open()) {
		fichier << listeJeux << ligneSeparation;
		fichier.close();
	}


	//TODO: Compléter le main avec les tests demandés.
	Jeu copieJeu = *listeJeux[2];
	copieJeu.getListeConcepteur()[2] = copieJeu.getListeConcepteur()[0];
	listeJeux[2]->afficher();
	copieJeu.afficher();
	cout << &listeJeux[2]->getListeConcepteur()[0];
	cout << &copieJeu.getListeConcepteur()[0];

	string lire("Aliou");
	
	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.
}