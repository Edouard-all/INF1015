#include "Personnage.hpp"

Personnage::Personnage() {
	nom_ = "";
	jeu_ = "";
}

Personnage::Personnage(string nom, string jeu) {
	nom_ = nom;
	jeu_ = jeu;
}

void Personnage::afficher() {
	cout << "Nom: " << nom_ << endl;
	cout << "Parution: " << jeu_ << endl;
}

void Personnage::setNom(string nom) {
	nom_ = nom;
}

string Personnage::getNom() {
	return nom_;
}

void Personnage::setJeu(string jeu) {
	jeu_ = jeu;
}

string Personnage::getJeu() {
	return jeu_;
}

