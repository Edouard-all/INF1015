/**
* Programme qui implémente la classe VilainHero.
* \file   VilainHero.cpp
* \auteurs Aliou Diallo et Edouard Allaire
* \date   16 mars 2026
* Créé le 27 février 2026
*/
#include "VilainHero.hpp"

VilainHero::VilainHero() {

}
VilainHero::VilainHero(Vilain& vilain, Hero& hero) : 
	Personnage(mauve,hero.getNom() + "-" + vilain.getNom(), hero.getJeu() + "-" + vilain.getJeu())
{
	setNom(hero.getNom() + "-" + vilain.getNom());
	setJeu(hero.getJeu() + "-" + vilain.getJeu());
	setEnnemie(hero.getEnnemie());
	setObjectif(vilain.getObjectif());
	vector<string> listeAllies = hero.getListeAllies();
	setListeAllies(listeAllies);
	missionSpeciale_ = vilain.getObjectif() + " dans le monde de " + hero.getJeu();
}
const void VilainHero::afficher() {
	Personnage::afficher();
	Vilain::afficherObjectif();
	Hero::afficheAlliesEnnemie();
	cout <<"\033[" << getCouleur() << "m" << missionSpeciale_ << endl;
}