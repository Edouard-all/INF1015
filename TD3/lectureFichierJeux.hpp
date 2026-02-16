// Fonctions pour lire le fichier binaire.
#pragma once
#include "Jeu.hpp"
#include "Concepteur.hpp"
#include <iostream>
#include "Liste.hpp"

using ListeJeux = Liste<Jeu>;

Concepteur* chercherConcepteur(ListeJeux& listeJeux, const std::string& nom);
Concepteur* lireConcepteur(ListeJeux& lj, std::istream& f);
Jeu* lireJeu(std::istream& f, ListeJeux& lj);
ListeJeux creerListeJeux(const std::string& nomFichier);
