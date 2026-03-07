#include "Personnage.hpp"

class Vilain : virtual public Personnage {
public:
    Vilain();
    Vilain(string objectif);
    void afficher() override;
    string getObjectif();
private:
    string objectif_;
};