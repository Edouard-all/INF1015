#include "Developpeur.hpp"
#include "Jeu.hpp"
#include <span>
#include <iostream>
#include "cppitertools/enumerate.hpp"

using namespace std;
using namespace iter;

Developpeur::Developpeur() {
	
}

Developpeur::Developpeur(const std::string& nom) {
	paireNomJeux_.first = nom;
	paireNomJeux_.second.capacite = 0;
	paireNomJeux_.second.elements = new Jeu*;
	paireNomJeux_.second.nElements = 0;
}

Developpeur::~Developpeur() {
	delete[] paireNomJeux_.second.elements;
	paireNomJeux_.second.elements = nullptr;
	cout << "develeloppeur detruit" << endl;
}

const std::string Developpeur::obtenirNom() const {
	return paireNomJeux_.first;
}

uint8_t Developpeur::compterNombreJeuxDeveloppe(const ListeJeux& listeJeux) const {
	span<Jeu*> listeJeuSpanne(listeJeux.elements, listeJeux.nElements);
	uint8_t compteur = 0;
	for (Jeu* jeu : listeJeuSpanne) {
		if (jeu->developpeur == paireNomJeux_.first) {
			compteur++;
		}
	}
	return compteur;
}

void Developpeur::mettreAJourListeJeuxDeveloppeur(const ListeJeux& listeJeux) {
	span<Jeu*> listeJeuSpanne(listeJeux.elements, listeJeux.nElements);
	span<Jeu*> listeJeuSpanneDeveloppeur(paireNomJeux_.second.elements, paireNomJeux_.second.nElements);
	ListeJeux listeJeuxDeveloppeur;
	uint8_t nJeuxDeveloppeur = compterNombreJeuxDeveloppe(listeJeux);
	listeJeuxDeveloppeur.elements = new Jeu* [nJeuxDeveloppeur];
	listeJeuxDeveloppeur.capacite = nJeuxDeveloppeur;
	listeJeuxDeveloppeur.nElements = 0;
	for (auto [i, jeu] : enumerate(listeJeuSpanneDeveloppeur)) { 
		listeJeuxDeveloppeur.elements[i] = jeu;
		listeJeuxDeveloppeur.nElements++;
	}
	for (Jeu* jeu : listeJeuSpanne) {
		
			//uint8_t compteur = 0;
			if (jeu->developpeur == paireNomJeux_.first) {
				listeJeuxDeveloppeur.elements[listeJeuxDeveloppeur.nElements] = jeu;
				listeJeuxDeveloppeur.nElements++;

			}
		
	}
	delete paireNomJeux_.second.elements;
	
	paireNomJeux_.second = listeJeuxDeveloppeur;
}

void Developpeur::afficherJeuxDeveloppe() const {
	span<Jeu*> listeJeuSpanne(paireNomJeux_.second.elements, paireNomJeux_.second.nElements);
	for (Jeu* jeu : listeJeuSpanne) {
		cout << jeu->titre;
	}
}