#include "Personnage.hpp"
#pragma once


class Vilain : virtual public Personnage {
public:
    Vilain();
    Vilain(string objectif);
    void afficher() override;
    void setObjectif(string objectif);
    string getObjectif();
private:
    string objectif_;
};