#include "VilainHero.hpp"

VilainHero::VilainHero() {

}
VilainHero::VilainHero(Vilain& vilain, Hero& hero) : 
	Personnage(mauve,hero.getNom() + "-" + vilain.getNom(), hero.getJeu() + "-" + vilain.getJeu())
{
	/*setNom(hero.getNom() + "-" + vilain.getNom());
	setJeu(hero.getJeu() + "-" + vilain.getJeu());*/
	setEnnemie(hero.getEnnemie());
	setObjectif(vilain.getObjectif());
	vector<string> listeAllies = hero.getListeAllies();
	setListeAllies(listeAllies);
	missionSpeciale_ = vilain.getObjectif() + " dans le monde de " + hero.getJeu();
}
const void VilainHero::afficher() {
	Personnage::afficher();
	Vilain::afficher();
	Hero::afficher();
	cout <<"\033[" << getCouleur() << "m" << missionSpeciale_ << endl;
}