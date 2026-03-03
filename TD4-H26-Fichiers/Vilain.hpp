
class Vilain : virtual public Personnage {
public:
    Vilain();
    Vilain(string objectif);
    void afficher() override;
private:
    string objectif_;
};