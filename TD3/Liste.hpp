#pragma once

//TODO: Rentdre la liste générique.
template <typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste(T) {
		capacite_ = 0;
		nElements_ = 0;
		elements_ = make_unique<T[]> tableau[0];
	}
	
	Liste(T, unsigned longueur) {
		capacite_ = longueur;
		nElements = 0;
		elements_ = make_unique<T[]> tableau[longueur];
	}

	//TODO: Méthode pour ajouter un élément à la liste
	void ajouterElement(T element) {

	}
	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const { return nElements_; }
	unsigned getCapacite() const { return capacite_; }

	//TODO: Méthode pour changer la capacité de la liste

	//TODO: Méthode pour trouver un élément selon un critère (lambda).

private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les éléments de la liste
	unique_ptr<T[]> elements_;
	
};