/**
* Programme qui implémente la classe Personnage.
* \file   Personnage.cpp
* \auteurs Aliou Diallo et Edouard Allaire
* \date   16 mars 2026
* Créé le 27 février 2026
*/
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

Personnage::Personnage(const Personnage& autre) {
	couleur_ = autre.couleur_;
	nom_ = autre.nom_;
	jeu_ = autre.jeu_;
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

