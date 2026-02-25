#pragma once
#include "Developpeur.hpp"
using namespace std;
#include <span>



class ListeDeveloppeurs
{
	//TODO: En faire une classe qui suit les principes OO.
	//TODO: On veut pouvoir ajouter et enlever un Developpeur* de la liste, avec réallocation dynamique tel que faite pour ListeJeux.
	//NOTE: Le code sera principalement copié de certaines fonctions écrites pour la partie 1, mais mises dans une classe.
	
	public:
		ListeDeveloppeurs();
		ListeDeveloppeurs(unsigned nElements, unsigned capacite, Developpeur** elements);
		~ListeDeveloppeurs();
		void afficher() const;
		unsigned obtenirNElements() const;
		unsigned obtenirCapacite() const;
		Developpeur** obtenirElements() const;
		void ajouterDeveloppeur(Developpeur* developpeur);
		void retirerDeveloppeur(Developpeur& developpeur); 
		span<Developpeur*> spanListeDeveloppeurs(const ListeDeveloppeurs& listeDeveloppeur) const;

	private:
		unsigned nElements;
		unsigned capacite;
		Developpeur** elements;
};
