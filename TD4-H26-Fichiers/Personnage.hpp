#include <Affichable.hpp>


class Pernonnage : public Affichable {
public:
	Personnage();
	Personnage(string nom, string jeu);
	void afficher() override;
	void setNom();
	string getNom();
	void setJeu();
	string getJeu();
private:
	string nom_;
	string jeu_;
};