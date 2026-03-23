/**
* Programme qui affiche les heros, vilains et vilainshero a partir d'un fichier binaire.
* \file   main.cpp
* \auteurs Aliou Diallo et Edouard Allaire
* \date   16 mars 2026
* Créé le 27 février 2026
*/
#include <fstream>
#include "bibliotheque_cours.hpp"
#include <vector>
#include "VilainHero.hpp"
using namespace std;

using UInt8  = uint8_t;
using UInt16 = uint16_t;
// Trait de separation
static const string trait =
"\033[92m═════════════════════════════════════════════════════════════════════════";


UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}

template <class T>
concept Dereferencable = requires (T&& t) { *std::forward<T>(t); };

// Surcharge quand c'est un pointeur
template <Dereferencable T> 
decltype(auto) as_ref(T&& t)
{
	return *std::forward<T>(t);
}

// Surcharge moins contrainte (donc quand ce n'est pas un pointeur)
template <class T>
T&& as_ref(T&& t) {
	return std::forward<T>(t);
}

template<typename T>
const void afficher(vector<T> listeElements) {
	for (T element : listeElements) {
		element->afficher();
		cout << trait << endl;
	}
}

template<typename T>
void ajouterElement(vector<shared_ptr<T>> elements,vector<shared_ptr<Personnage>> listePersonnages) {
	for (shared_ptr<T> element : elements) {
		listePersonnages.push_back(element);
	}
}
int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	
	// Ouverture des fichiers binaires
	ifstream fichierHeros("heros.bin", ios::binary);
	ifstream fichierVilains("vilains.bin", ios::binary);
	fichierHeros.exceptions(ios::failbit);
	fichierVilains.exceptions(ios::failbit);

	//TODO: Votre code pour le main commence ici
	vector<shared_ptr<Vilain>> vilains;
	vector<shared_ptr<Hero>> heros;
	vector<shared_ptr<Personnage>> personnages;
	Personnage copieHero;
	uint16_t nHero = lireUint16(fichierHeros);
	uint16_t nVilain = lireUint16(fichierVilains);
	uint8_t nAllie = 0;


	for (uint8_t i = 0; i < nHero; i++){
		shared_ptr<Hero> hero = make_shared<Hero>();
		hero->changerCouleur(bleu);
		hero->setNom(lireString(fichierHeros));
		hero->setJeu(lireString(fichierHeros));
		hero->setEnnemie(lireString(fichierHeros));
		nAllie = lireUint8(fichierHeros);
		vector<string> listeAllies;
		for (uint8_t j = 0; j < nAllie; j++){
			listeAllies.push_back(lireString(fichierHeros));
		}
		hero->setListeAllies(listeAllies);
		heros.push_back(hero);

	}

	for (uint8_t i = 0; i < nVilain; i++){
		shared_ptr<Vilain> vilain = make_shared<Vilain>();
		vilain->changerCouleur(rouge);
		vilain->setNom(lireString(fichierVilains));
		vilain->setJeu(lireString(fichierVilains));
		vilain->setObjectif(lireString(fichierVilains));
		vilains.push_back(vilain);
	}

	afficher(heros);
	afficher(vilains);
	ajouterElement<Hero>(heros, personnages);
	ajouterElement<Vilain>(vilains, personnages);
	
	uint8_t i = 0;
	if (heros[0]->getEnnemie() == vilains[0]->getNom()){
		while(heros[0]->getEnnemie() == vilains[i]->getNom()){
			i++;
		}
	}
	shared_ptr<VilainHero> vilainHero;
	vilainHero = make_shared<VilainHero>( *vilains[i],*heros[0] );
	personnages.push_back(vilainHero);
	afficher(personnages);
	cout << "\033[00m";
}
