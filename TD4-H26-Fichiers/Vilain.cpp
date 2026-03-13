#include "Vilain.hpp"

Vilain::Vilain(){
    objectif_ = {};
}

Vilain::Vilain(int couleur, string nom, string jeu, string objectif ) :
    Personnage(couleur, nom, jeu)
{
    //changerCouleur(rouge);
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