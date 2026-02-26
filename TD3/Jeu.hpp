#pragma once
#include <string>
#include "Liste.hpp"
#include "Concepteur.hpp"

using ListeConcepteurs = Liste<Concepteur>;
class Jeu
{
public:
	//TODO: un constructeur par défaut et un constructeur paramétré.
	Jeu() {
		titre_ = "";
		anneeSortie_ = 0;
		developpeur_ = "";
		listeConcepteurs_ = ListeConcepteurs();
	}
	Jeu(string titre, unsigned anneeSortie, string developpeur, unsigned capacite) {
		titre_ = titre;
		anneeSortie_ = anneeSortie;
		developpeur_ = developpeur;
		listeConcepteurs_ = ListeConcepteurs(capacite);
	}

	const std::string& getTitre() const { return titre_; }
	void setTitre(std::string titre) { titre_ = move(titre); }
	unsigned getAnneeSortie() const { return anneeSortie_; }
	void setAnneeSortie(unsigned annee) { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(std::string developpeur) { developpeur_ = move(developpeur); }


	//TODO: Pouvoir accéder à la liste de concepteurs.
	const ListeConcepteurs& getListeConcepteur() const { return listeConcepteurs_; }
	void setConcepteur(uint8_t index, shared_ptr<Concepteur> concepteur) { listeConcepteurs_[index] = concepteur; };



	//TODO: Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.
	void ajouterConcepteur(shared_ptr<Concepteur> concepteur) { listeConcepteurs_.ajouterElement(concepteur); };
	shared_ptr<Concepteur> trouverConcepteur(string nom) const { listeConcepteurs_.trouverElementSi([=](string nom2)->bool {if (nom == nom2) return true; else return false; }); }
	void afficher() const {
		cout << "Titre : " << "\033[94m" << titre_ << "\033[0m" << endl;
		cout << "Parution : " << "\033[94m" << anneeSortie_ << "\033[0m"
			<< endl;
		cout << "Développeur :  " << "\033[94m" << developpeur_ << "\033[0m"
			<< endl;
		cout << "Concepteurs du jeu :" << "\033[94m" << endl;

	}

private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	//TODO: Attribut de la liste des concepteurs du jeu
	ListeConcepteurs listeConcepteurs_;
};

  //TODO: Remplacer cette définition (qui est ici juste pour que le code fourni compile) pour que ListeJeux soit une Liste<Jeu> .
 