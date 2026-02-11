#include "ListeDeveloppeurs.hpp"

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
	
}
void ListeDeveloppeurs::ajouterDeveloppeur() {

}
void ListeDeveloppeurs::retirerDeveloppeur() {

}

ListeDeveloppeurs::~ListeDeveloppeurs() {
	delete[] this;
	this->elements = nullptr;

}