#include "Personnage.hpp"
#include <vector>

class Hero : virtual public Personnage {
public:
	Hero();
	Hero(vector<string> listeAllies, string ennemie);
	void afficher() override;
	//vector<string> getListeAllies();
	//string getEnnemie();
private:
	vector<string> listeAllies_;
	string ennemie_;
};