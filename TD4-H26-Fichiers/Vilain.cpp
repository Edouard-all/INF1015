/**
* Programme qui implémente la classe Vilain.
* \file   Vilain.cpp
* \auteurs Aliou Diallo et Edouard Allaire
* \date   16 mars 2026
* Créé le 27 février 2026
*/
#include "Vilain.hpp"

Vilain::Vilain(){
    objectif_ = {};
}

Vilain::Vilain(int couleur, string nom, string jeu, string objectif ) :
    Personnage(couleur, nom, jeu)
{
    objectif_ = objectif;
}

const void Vilain::afficherObjectif() {
    cout << "\033[" << getCouleur() << "m" << objectif_ << endl;
}

const void Vilain::afficher() {
    Personnage::afficher();
    afficherObjectif();
}

void Vilain::setObjectif(string objectif){
    objectif_ = objectif;
}
string Vilain::getObjectif() {
    return objectif_;
}