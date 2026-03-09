#include "Hero.hpp"
#include "Vilain.hpp"
#pragma once


class VilainHero : public Vilain, public Hero {
public:
	VilainHero();
	VilainHero(Vilain& vilain, Hero& hero);
	void afficher() override;
private:
	string missionSpeciale_;
};