#include "Personnage.hpp"
#pragma once

class Vilain : virtual public Personnage {
public:
    Vilain();
    Vilain(int couleur, string nom, string jeu, string objectif);
    const void afficherObjectif();
    virtual const void afficher() override;
    void setObjectif(string objectif);
    string getObjectif();
private:
    string objectif_;
};