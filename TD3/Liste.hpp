#pragma once

//TODO: Rentdre la liste générique.
template<typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste() {
		nElements_ = 0;
		capacite_ = 1;
		elements_ = make_unique<T[]>();
	}
	Liste(unsigned nElement, unsigned capacite) { 
		nElements_ = nElement; 
		capacite_ = capacite; 
	}
	//TODO: Méthode pour ajouter un élément à la liste

	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: Méthode pour changer la capacité de la liste
	void changerCapacite(unsigned capacite) { capacite_ = capacite; }
	//TODO: Méthode pour trouver un élément selon un critère (lambda).
	T trouverElement();
private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les éléments de la liste.
	unique_ptr<shared_ptr<T>> elements_;
};
