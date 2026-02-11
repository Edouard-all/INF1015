#pragma once
#include <string>
#include <utility>
#include "ListeJeux.hpp"

class Developpeur
{
	//TODO: En faire une classe qui suit les principes OO.
	//TODO: La destruction d'un Developpeur doit s'assurer que la désallocation de ListeJeux est faite.
	//TODO: Les méthodes à faire...
public:
	Developpeur();
	Developpeur(const std::string& nom);
	~Developpeur();
	const std::string& obtenirNom() const;
	uint8_t compterNombreJeuxDeveloppe(const ListeJeux& listeJeux) const;
	void mettreAJourListeJeuxDeveloppeur(const ListeJeux& lisreJeux);
	void afficherJeuxDeveloppe() const;


private:
	std::pair<std::string, ListeJeux> paireNomJeux_;
};
