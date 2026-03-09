#include "Hero.hpp"
#pragma once

Hero::Hero() {
	listeAllies_ = {};
	ennemie_ = {};
}

Hero::Hero(int couleur,string nom, string jeu, vector<string> listeAllies, string ennemie) :
	Personnage(couleur,nom,jeu)
{
	listeAllies_ = listeAllies;
	ennemie_ = ennemie;
}

const void Hero::afficher() {
	changerCouleur(1);
	cout << "Ennemies : " << ennemie_ << endl;
	cout << "Allies :" << endl;
	for (string allie : listeAllies_)
		cout << allie << endl;
}

void Hero::setEnnemie(string ennemie){
	ennemie_ = ennemie;
}
vector<string> Hero::getListeAllies() { return listeAllies_; }
string Hero::getEnnemie() { return ennemie_; }