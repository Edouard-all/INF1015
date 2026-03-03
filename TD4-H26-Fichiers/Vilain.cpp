#include "Vilain.hpp"

Vilain::Vilain(){
    objectif_ = {};
}

Vilain::Vilain(string objectif ){
    objectif_ = objectif;
}

void Vilain::afficher() {
    cout << objectif_ << endl;
}