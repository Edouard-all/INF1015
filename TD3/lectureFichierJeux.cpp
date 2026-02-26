/**
* Programme qui implemente les fonctions pour lire les informations d'une liste de jeux d'un fichier binaire
* \file   lectureFichierJeux.cpp
* \author Edourard Allaire et Aliou Banire Diallo
* \date	  25 fevrier 2026
* Créé le 13 fevrier 2026
*/

// Fonctions pour lire le fichier binaire.
#include "lectureFichierJeux.hpp"
#include <fstream>
#include <cstdint>
#include "cppitertools/range.hpp"
#include "Liste.hpp"

using namespace std;
using ListeJeux = Liste<Jeu>;

using UInt8  = uint8_t;
using UInt16 = uint16_t;

#pragma region "Fonctions de lecture de base"
//TODO: Remplacer lireUint8 et lireUint16 par une seule fonction générique qui permet les deux, mais permettre uniquement des types qui sont is_trivially_copyable_v (un trait de type).

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lire<UInt16>(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
#pragma endregion



shared_ptr<Concepteur> chercherConcepteur(ListeJeux& listeJeux, const string& nom)
{
	//TODO: Compléter la fonction (équivalent de trouverDesigner du TD2).
	// utiliser la methode trouverElement de liste pour trouver l'element avec un concepteur de nom utiliser la condition lambda pour cette fonction
	for (uint8_t i = 0; i < listeJeux.size(); i++) {
		shared_ptr<Jeu> jeu = listeJeux[i];
		ListeConcepteurs listeConcepteur = jeu->getListeConcepteur();
		return listeConcepteur.trouverElementSi([=](string titre)->bool {return titre == nom; });
		// Normalement on voudrait retourner un pointeur const, mais cela nous
		// empêcherait d'affecter le pointeur retourné lors de l'appel de cette
		// fonction.
	}
}

shared_ptr<Concepteur> lireConcepteur(ListeJeux& lj, istream& f)
{
	string nom              = lireString(f);
	unsigned anneeNaissance = lire<UInt16>(f);
	string pays             = lireString(f);
	Concepteur concepteur(nom,anneeNaissance,pays);
	shared_ptr<Concepteur> concepteurExistant = chercherConcepteur(lj, nom);
	if (concepteurExistant != nullptr)
		return concepteurExistant;
	//TODO: Compléter la fonction (équivalent de lireDesigner du TD2).
	cout << "C: " << nom << endl;  //TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.
	shared_ptr<Concepteur> concepteurPtr = make_shared<Concepteur>(concepteur);
	return concepteurPtr;
}

shared_ptr<Jeu> lireJeu(istream& f, ListeJeux& lj)
{
	string titre          = lireString(f);
	unsigned anneeSortie  = lire<UInt16>(f);
	string developpeur    = lireString(f);
	unsigned nConcepteurs = lire<UInt8>(f);
	//TODO: Compléter la fonction (équivalent de lireJeu du TD2).
	shared_ptr<Jeu> ptrJeu = make_shared<Jeu>(titre,anneeSortie,developpeur,nConcepteurs);
	for (unsigned int i = 0; i < nConcepteurs; i++) {
		shared_ptr<Concepteur> concepteur = lireConcepteur(lj, f);
		ptrJeu->ajouterConcepteur(concepteur);
	}

	cout << "J: " << titre << endl;  //TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.
	return ptrJeu;
}

ListeJeux creerListeJeux(const string& nomFichier)
{
	ifstream f(nomFichier, ios::binary);
	f.exceptions(ios::failbit);
	int nElements = lire<UInt16>(f);
	//TODO: Compléter la fonction.
	ListeJeux listeJeux;
	for ([[maybe_unused]] int i : iter::range(nElements)) {
		listeJeux.ajouterElement(lireJeu(f, listeJeux));
	}

	return listeJeux;
}
