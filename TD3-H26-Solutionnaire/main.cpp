#include <iostream>
#include <fstream>
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
using namespace std;

//TODO: Vos surcharges d'opérateur <<
ostream& operator<< (ostream& os, const Concepteur& c) // Principalement copié de TD2 afficherDesigner
{
	return os << c.getNom() << ", " << c.getAnneeNaissance() << ", " << c.getPays();
}

ostream& operator<< (ostream& os, const Liste<Concepteur>& concepteurs)
{
	for (auto& c : concepteurs.enSpan())
		os << "\t" << *c << endl;
	return os;
}

ostream& operator<< (ostream& os, const Jeu& j)
{
	return os << "Titre : " << j.getTitre() << "\n" << "Parution : " << j.getAnneeSortie()
		<< "\n" << "Développeur : " << j.getDeveloppeur() << "\n"
		<< "Concepteurs : \n" << j.getConcepteurs();
}

ostream& operator<<(ostream& os, const Liste<Jeu>& jeux)
{
	static const string ligneSeparation = "\n\033[94m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";
	for (auto& j : jeux.enSpan())
		os << *j << ligneSeparation;

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

	{ // Test simple optionnel.
	Liste<int> t;
	t.ajouter(make_shared<int>(4));
	t.ajouter(make_shared<int>(7));
	assert(t.size() == 2);
	assert(*t[0] == 4 && *t[1] == 7);
	}

	ListeJeux listeJeux = creerListeJeux("jeux.bin");
	static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	assert(listeJeux.size() == 17);
	assert(listeJeux.getCapacite() == 32);
	assert(listeJeux[2]->getTitre() == "Secret of Mana");
	assert(listeJeux[2]->getConcepteurs()[1]->getNom() == "Hiromichi Tanaka");

	//TODO: L'affichage de listeJeux et l'écriture dans le fichier devraient fonctionner.

	cout << listeJeux << ligneSeparation;
	ofstream("sortie.txt") << listeJeux;

	//TODO: Compléter le main avec les tests demandés.
	auto yoshinori1 = listeJeux[0]->trouverConcepteur([](auto& c){ return c.getNom() == "Yoshinori Kitase";});
	auto yoshinori2 = listeJeux[1]->trouverConcepteur([](auto& c){ return c.getNom() == "Yoshinori Kitase";});
	assert(yoshinori1 == yoshinori2);
	assert(yoshinori1->getAnneeNaissance() == 1966);

	Jeu copieJeu = *listeJeux[2];
	copieJeu.getConcepteurs()[1] = listeJeux[0]->getConcepteurs()[0];
	assert(copieJeu.getConcepteurs()[0] == listeJeux[2]->getConcepteurs()[0]);
	assert(copieJeu.getConcepteurs()[1] != listeJeux[2]->getConcepteurs()[1]); // Pas demandé.
	cout << *listeJeux[2] << ligneSeparation << copieJeu;

	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	assert(listeJeux[0]->trouverConcepteur([](auto&){ return false;}) == nullptr);  // Une recherche qui ne troupe pas.

	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.
}
