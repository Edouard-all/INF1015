#include <iostream>
#pragma once

const int bleu = 94;
const int rouge = 91;
const int mauve = 35;

class Affichable {
public:
	Affichable() {};
	virtual const void afficher() = 0;
	virtual void changerCouleur(int couleur) = 0;
};