#include "VilainHero.hpp"

VilainHero::VilainHero() {

}
VilainHero::VilainHero(Vilain& vilain, Hero& hero) {
	setNom(hero.getNom() + "-" + vilain.getNom());
	setJeu(hero.getJeu() + "-" + vilain.getJeu());
	missionSpeciale_ = vilain.getObjectif() + " dans le monde de " + hero.getJeu();
}
void VilainHero::afficher() {
	cout << missionSpeciale_ << endl;
}