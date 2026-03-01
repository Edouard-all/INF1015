#include "Hero.hpp"

Hero::Hero() {
	listeAllies_ = {};
	ennemie_ = {};
}

Hero::Hero(vector<string> listeAllies, string ennemie) {
	listeAllies_ = listeAllies;
	ennemie_ = ennemie;
}

void Hero::afficher() {
	cout << "Ennemies : " << ennemie_ << endl;
	cout << "Alliés :" << endl;
	for (string allie : listeAllies_)
		cout << allie << endl;
}

//vector<string> Hero::getListeAllies() { return listeAllies_; }

//string Hero::getEnnemie() { return ennemie_; }