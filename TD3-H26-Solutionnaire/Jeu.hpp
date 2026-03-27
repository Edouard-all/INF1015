#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

class Jeu
{
public:
	//TODO: un constructeur par défaut et un constructeur paramétré.
	Jeu(void) = default;
	Jeu(std::string titre, unsigned annee, std::string developpeur) :
		titre_{move(titre)},
		anneeSortie_{annee},
		developpeur_{move(developpeur)}
	{}

	const std::string& getTitre() const     { return titre_; }
	void setTitre(std::string titre)        { titre_ = move(titre); }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(std::string developpeur) { developpeur_ = move(developpeur); }

	//TODO: Pouvoir accéder à la liste de concepteurs.
	Liste<Concepteur>& getConcepteurs()             { return concepteurs_; }  // On veut pouvoir modifier la liste retournée,
	const Liste<Concepteur>& getConcepteurs() const { return concepteurs_; }  // mais pas si l'objet est const.  
	//NOTE: En C++23 on peut écrire les deux versions (const/non const) en une seule, mais le cours est en C++20.

	//TODO: Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.
	std::shared_ptr<Concepteur> trouverConcepteur(const std::function<bool(const Concepteur&)>& critere) { return concepteurs_.trouver(critere); }

private:
	std::string titre_;
	unsigned anneeSortie_ = 0;
	std::string developpeur_;
	//TODO: Attribut de la liste des concepteurs du jeu
	Liste<Concepteur> concepteurs_;
};

using ListeJeux = Liste<Jeu>;  //TODO: Remplacer cette définition (qui est ici juste pour que le code fourni compile) pour que ListeJeux soit une Liste<Jeu> .