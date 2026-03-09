#include "Hero.hpp"
#include "Vilain.hpp"
#pragma once

class VilainHero : public Vilain, public Hero {
public:
	VilainHero();
	VilainHero(Vilain& vilain, Hero& hero);
	const void afficher() override;
private:
	string missionSpeciale_;
};