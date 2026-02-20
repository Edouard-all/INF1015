// Fonctions pour lire le fichier binaire.
#pragma once
#include "Jeu.hpp"
#include "Concepteur.hpp"
#include <iostream>
#include "Liste.hpp"

using ListeJeux = Liste<Jeu>;

shared_ptr<Concepteur> chercherConcepteur(ListeJeux & listeJeux, const std::string & nom);
shared_ptr<Concepteur> lireConcepteur(ListeJeux& lj, std::istream& f);
shared_ptr<Jeu> lireJeu(std::istream& f, ListeJeux& lj);
ListeJeux creerListeJeux(const std::string& nomFichier);
