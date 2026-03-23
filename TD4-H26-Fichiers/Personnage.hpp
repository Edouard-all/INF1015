#include "Affichable.hpp"
#include <string>
#pragma once

using namespace std;

class Personnage : public Affichable {
public:
	Personnage();
	Personnage(int couleur, string nom, string jeu);
	virtual const void afficher() override;
	void changerCouleur(int couleur) override;
	int getCouleur();
	void setNom(string nom);
	string getNom();
	void setJeu(string jeu);
	string getJeu();
protected:
	Personnage(const Personnage& autre);
private:
	string nom_;
	string jeu_;
	int couleur_ = 0;
};