#include <iostream>
#pragma once

class Affichable {
public:
	Affichable() {};
	//Affichable(int couleur) { _couleur = couleur; };
	virtual const void afficher() = 0;
	virtual void changerCouleur(int couleur) = 0;
//private:
//	int _couleur = 0;
};