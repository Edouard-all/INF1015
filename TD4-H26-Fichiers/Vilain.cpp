#include "Vilain.hpp"

Vilain::Vilain(){
    objectif_ = {};
}

Vilain::Vilain(string objectif ){
    objectif_ = objectif;
}

void Vilain::afficher() {
    changerCouleur(2);
    cout << objectif_ << endl;
}

void Vilain::setObjectif(string objectif){
    objectif_ = objectif;
}
string Vilain::getObjectif() {
    return objectif_;
}