#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"

//TODO: Rentdre la liste générique.
template <typename T>
class Liste
{
	public:
		//TODO: Constructeurs et surcharges d'opérateurs
		Liste() = default;
		Liste(const Liste<T>&);
		std::shared_ptr<T>& operator[] (int index) const { return elements_[index]; } // Noter qu'on retourne un pointeur non const alors que la liste peut être const; on pourrait vouloir avoir deux versions de l'opérateur const et non const.

		gsl::span<std::shared_ptr<T>> enSpan() const { return { elements_.get(), nElements_ }; } // Pas obligatoire.

		//TODO: Méthode pour ajouter un élément à la liste
		void ajouter(const std::shared_ptr<T>&);

		// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
		unsigned size() const         { return nElements_; }
		unsigned getCapacite() const  { return capacite_; }

		//TODO: Méthode pour changer la capacité de la liste
		void changerCapacite(unsigned nouvelleCapacite);

		//TODO: Méthode pour trouver un élément selon un critère (lambda).
		std::shared_ptr<T> trouver(const std::function<bool(const T&)>& critere) const;  // Selon les notes de cours (et Core Guidelines) on devrait passer un pointeur intelligent seulement si c'est pour influencer la durée de vie.

	private:
		unsigned nElements_ = 0;
		unsigned capacite_ = 0;
		//TODO: Attribut contenant les éléments de la liste.
		std::unique_ptr<std::shared_ptr<T>[]> elements_;
};

template<typename T>
Liste<T>::Liste(const Liste<T>& autre) :
	nElements_{autre.nElements_},
	capacite_{autre.capacite_},
	elements_{std::make_unique<std::shared_ptr<T>[]>(nElements_)}
{
	for (unsigned i = 0; i < nElements_; ++i)
		elements_[i] = autre.elements_[i];
}

template<typename T>
void Liste<T>::ajouter(const std::shared_ptr<T>& elem)  // On peut soit passer le shared_ptr par référence, soit faire un move dans le tableau, pour ne pas compter les références inutilement.
{
	if (nElements_ == capacite_)
		changerCapacite(std::max(1U, 2*capacite_));
	assert(nElements_ < capacite_);
	elements_[nElements_++] = elem;
}

template<typename T>
void Liste<T>::changerCapacite(unsigned nouvelleCapacite)
{
	assert(nElements_ <= capacite_);
	capacite_ = nouvelleCapacite;
	auto nouvelleListe = std::make_unique<std::shared_ptr<T>[]>(capacite_);
	for (int i : iter::range(nElements_))
		nouvelleListe[i] = std::move(elements_[i]);  // On ne demande pas d'éviter le comptage inutile, mais c'est mieux comme ça.
	elements_ = std::move(nouvelleListe);
}

template<typename T>
std::shared_ptr<T> Liste<T>::trouver(const std::function<bool(const T&)>& critere) const
{
	for (unsigned int i = 0; i < size(); i++) {
		if (critere(*elements_[i]))
			return elements_[i];
	}
	return nullptr;  // On n'a pas vraiment vu "static", donc on ne peut pas retourner ce nullptr par référence, d'où le fait qu'on retourne un std::shared_ptr<T> et non un const std::shared_ptr<T>&.
}
