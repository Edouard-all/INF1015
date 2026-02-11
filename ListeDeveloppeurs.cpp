#include "ListeDeveloppeurs.hpp"
#include "cppitertools/range.hpp"
#include "cppitertools/enumerate.hpp"
#include <iostream>
#include <span>

using namespace std;
using namespace iter;

span<Developpeur*> ListeDeveloppeurs::spanListeDeveloppeurs(ListeDeveloppeurs listeDeveloppeurs) {
	return span<Developpeur*>(*listeDeveloppeurs.elements, listeDeveloppeurs.nElements);
}

ListeDeveloppeurs::ListeDeveloppeurs() {
	this->nElements = 0;
	this->capacite = 0;
	this->elements = nullptr;
}

ListeDeveloppeurs::ListeDeveloppeurs(unsigned nElements, unsigned capacite, Developpeur** elements) {
	this->nElements = nElements;
	this->capacite = capacite;
	this->elements = elements;
}

void ListeDeveloppeurs::afficher() {
	for (int i : iter::range((*this).nElements)) {
		cout << this->elements[i].name << endl; // à modifier selon la façon d'accéder au nom d'un developpeur
		cout << this->elements[i].afficher() << endl;// à modifier selon le nom de la méthode dans développeur
	}
}

void ListeDeveloppeurs::ajouterDeveloppeur(Developpeur* developpeur) {
	if (this->capacite == 0) {
		this->capacite = 1;
		this->elements = new Developpeur * [1];
		this->elements[0] = developpeur;
		//cout << "ajout de " << jeu->titre << endl;
		this->nElements = 1;
	}
	else if (this->nElements == this->capacite) {
		span<Developpeur*> ancienne;
		ancienne = spanListeDeveloppeurs(*this);
		Developpeur** nouvelleListe;
		this->capacite *= 2;
		nouvelleListe = new Developpeur * [this->capacite];
		for (auto [i, dev] : enumerate(ancienne)) {
			nouvelleListe[i] = dev;
		}
		delete[] this->elements;
		this->elements = nullptr;
		this->elements = nouvelleListe;
		this->elements[this->nElements] = developpeur;
		this->nElements += 1;
	}
}

	void ListeDeveloppeurs::retirerDeveloppeur(Developpeur* developpeur) {
		cout << "" << endl;
	}

ListeDeveloppeurs::~ListeDeveloppeurs() {
	delete[] this;
	this->elements = nullptr;

}