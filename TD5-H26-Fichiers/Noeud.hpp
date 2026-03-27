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
	Noeud(T donne, Noeud<T>* avant, Noeud<T>* apres) {
		donne_ = donne;
		avant_ = avant;
		apres_ = apres;
	}
private:
	//TODO: Attributs d'un noeud.
	Noeud<T>* avant_ = nullptr;
	Noeud<T>* apres_ = nullptr;
	T donne_;
};
