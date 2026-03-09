#include "Personnage.hpp"

Personnage::Personnage() {
	nom_ = "";
	jeu_ = "";
}

Personnage::Personnage(int couleur,string nom, string jeu) {
	couleur_ = couleur;
	nom_ = nom;
	jeu_ = jeu;
}

const void Personnage::afficher() {
	cout << "\033[" << couleur_ << "m" << "Nom: " << nom_ << endl;
	cout << "Parution: " << jeu_ << endl;
}

void Personnage::changerCouleur(int couleur) {
	couleur_ = couleur;
}

int Personnage::getCouleur() { return couleur_; }

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

