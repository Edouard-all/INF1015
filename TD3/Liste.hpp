#pragma once
#include <iostream>
#include "cppitertools/range.hpp"
#include <cassert>
#include <span>

using namespace std;

//TODO: Rentdre la liste générique.
template<typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste() {
		capacite_ = 0;
		nElements_ = 0;
		elements_ = make_unique<shared_ptr<T>[]>(0);
	}

	Liste(unsigned longueur) {
		capacite_ = longueur;
		nElements_ = 0;
		elements_ = make_unique<shared_ptr<T>[]>(longueur);
	}

	Liste(const Liste& other) {
		nElements_ = other.size();
		capacite_ = other.getCapacite();
		elements_ = make_unique<shared_ptr<T>[]>(capacite_);
		for (uint8_t i = 0; i < nElements_; i++) {
			elements_[i] = other.elements_[i];
		}
	}

	Liste operator= (const Liste<T>& other) { return other; }
	shared_ptr<T>& operator[](uint8_t index) const { return elements_[index]; }
	shared_ptr<T>& operator[](uint8_t index) { return elements_[index]; }


	

	//TODO: Méthode pour ajouter un élément à la liste
	void ajouterElement(shared_ptr<T> element)
	{
		if (nElements_ == capacite_)
			changerCapaciteListe(max(1U, capacite_ * 2));
		elements_[nElements_++] = element;
	}
	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const { return nElements_; }
	unsigned getCapacite() const { return capacite_; }

	//TODO: Méthode pour changer la capacité de la liste
	void changerCapaciteListe(const unsigned nouvelleCapacite)
	{
		assert(nouvelleCapacite >= nElements_); // On ne demande pas de supporter les réductions de nombre d'éléments.
		unique_ptr<shared_ptr<T>[]> nouvelleListe = make_unique<shared_ptr<T>[]>(nouvelleCapacite);
		// Pas nécessaire de tester si liste.elements est nullptr puisque si c'est le cas, nElements est nécessairement 0.
		for (int i : iter::range(nElements_))
			nouvelleListe[i] = move(elements_[i]);
		elements_ = move(nouvelleListe);
		capacite_ = nouvelleCapacite;
	}
	//TODO: Méthode pour trouver un élément selon un critère (lambda).
	shared_ptr<T> trouverElementSi(const function<bool(string)>& critere) const {
		for (int i = 0; i < nElements_; i++) {
			shared_ptr<T> element = elements_[i];
			if (critere(element->getNom()))
				return element;
		}
		return nullptr;
	}
	void afficherListe()
	{
		static const string ligneSeparation = "\n\033[95m"
			"══════════════════════════════════════════════════════════════════════════"
			"\033[0m\n";

		cout << ligneSeparation << endl;
		for (uint8_t i = 0; i < nElements_; i++) {
			elements_[i].afficher();
			cout << ligneSeparation << endl;
		}
	}
private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les éléments de la liste.
	unique_ptr<shared_ptr<T>[]> elements_;
};
