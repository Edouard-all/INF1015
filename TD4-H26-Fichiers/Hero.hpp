#include "Personnage.hpp"
#include <vector>
#pragma once


class Hero : virtual public Personnage {
public:
	Hero();
	Hero(int couleur,string nom, string jeu,vector<string> listeAllies, string ennemie);
	virtual const void afficher() override;
	vector<string> getListeAllies();
	void setListeAllies(vector<string> listeAllies);
	string getEnnemie();
	void setEnnemie(string ennemie);
private:
	vector<string> listeAllies_;
	string ennemie_;
};