#include "Affichable.hpp"
#include <string>
#pragma once


using namespace std;

class Personnage : public Affichable {
public:
	Personnage();
	Personnage(string nom, string jeu);
	void afficher() override;
	void setNom(string nom);
	string getNom();
	void setJeu(string jeu);
	string getJeu();
private:
	string nom_;
	string jeu_;
};