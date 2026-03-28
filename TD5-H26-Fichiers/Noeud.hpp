#pragma once
#include <gsl/pointers>
template<typename T> class ListeLiee;
template<typename T> class Iterateur;

template<typename T>
class Noeud
{
	friend class ListeLiee<T>;
	friend class Iterateur<T>;
public:
	//TODO: Constructeur(s).
	Noeud() {}
	Noeud(T donne, Noeud<T>* avant = nullptr, Noeud<T>* apres = nullptr) {
		donne_ = donne;
		precedent_ = avant;
		suivant_ = apres;
	}
private:
	//TODO: Attributs d'un noeud.
	Noeud<T>* precedent_ = nullptr;
	Noeud<T>* suivant_ = nullptr;
	T donne_;
};
