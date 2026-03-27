#pragma once
#include "Liste.hpp"
#include <string>
#include <memory>

class Concepteur
{
public:
	//TODO: Un constructeur par défaut et un constructeur paramétré.
	Concepteur() = default;
	Concepteur(const std::string& nom, unsigned anneeNaissance, const std::string& pays) :
		nom_(nom),
		anneeNaissance_(anneeNaissance),
		pays_(pays)
	{}

	const std::string& getNom() const     { return nom_; }
	void setNom(std::string nom)          { nom_ = move(nom); }
	int getAnneeNaissance() const         { return anneeNaissance_; }
	void setAnneeNaissance(int annee)     { anneeNaissance_ = annee; }
	const std::string& getPays() const    { return pays_; }
	void setPays(std::string pays)        { pays_ = move(pays); }

private:
	std::string nom_;
	int anneeNaissance_ = 0;
	std::string pays_;
};
