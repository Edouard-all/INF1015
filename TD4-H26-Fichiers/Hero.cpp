/**
* Programme qui implémente la classe Hero.
* \file   Hero.cpp
* \auteurs Aliou Diallo et Edouard Allaire
* \date   16 mars 2026
* Créé le 27 février 2026
*/
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

const void Hero::afficheAlliesEnnemie() {
	cout << "\033[" << getCouleur() << "m" << "Ennemies : " << ennemie_ << endl;
	cout << "Allies :" << endl;
	for (string allie : listeAllies_)
		cout << allie << endl;
}

const void Hero::afficher() {
	Personnage::afficher();
	afficheAlliesEnnemie();
}
void Hero::setListeAllies(vector<string> listeAllies) {
	listeAllies_ = listeAllies;
}

void Hero::setEnnemie(string ennemie){
	ennemie_ = ennemie;
}
vector<string> Hero::getListeAllies() { return listeAllies_; }
string Hero::getEnnemie() { return ennemie_; }