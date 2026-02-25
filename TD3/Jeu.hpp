#pragma once
#include <string>
using ListeConcepteur = Liste<Concepteur>;
class Jeu
{
public:
	//TODO: un constructeur par défaut et un constructeur paramétré.
	Jeu() {
		titre_ = "";
		anneeSortie_ = 0;
		developpeur_ = "";
		listeConcepteur_ = ListeConcepteur();
	}
	Jeu(string titre, unsigned anneeSortie, string developpeur, unsigned capacite) {
		titre_ = titre;
		anneeSortie_ = anneeSortie;
		developpeur_ = developpeur;
		listeConcepteur_ = ListeConcepteur(capacite);
	}

	const std::string& getTitre() const     { return titre_; }
	void setTitre(std::string titre)        { titre_ = move(titre); }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(std::string developpeur) { developpeur_ = move(developpeur); }

	//TODO: Pouvoir accéder à la liste de concepteurs.

	//TODO: Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.

private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	//TODO: Attribut de la liste des concepteurs du jeu
	ListeConcepteur listeConcepteur_;
};

  //TODO: Remplacer cette définition (qui est ici juste pour que le code fourni compile) pour que ListeJeux soit une Liste<Jeu> .
