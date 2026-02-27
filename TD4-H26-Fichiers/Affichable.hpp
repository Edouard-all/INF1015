#include <iostream>

class Affichable {
public:
	Affichable();
	virtual void afficher() = 0;
	virtual void changerCouleur(int couleur) = 0;
};