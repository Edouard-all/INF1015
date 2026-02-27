#include <iostream>

class Affichable {
	Affichable();
	virtual void afficher() = 0;
	virtual void changerCouleur(int couleur) = 0;
};