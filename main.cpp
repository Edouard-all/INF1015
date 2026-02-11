/**
* Programme qui détermine si une année lue du clavier est bissextile.
* \file   main.cpp
* \author Aliou Diallo et Édouard Allaire
* \date   11 février 2026
* Créé le 30 janvier 2026
*/
#include "Jeu.hpp"
#include <iostream>
#include <fstream>
#include <span>
#include "cppitertools/range.hpp"
#include "cppitertools/enumerate.hpp"
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  // Ajout des numéros de ligne des "new" dans le rapport de fuites.  Doit être après les include du système, qui peuvent utiliser des "placement new" (non supporté par notre ajout de numéros de lignes).
#include <string>

using namespace std;
using namespace iter;

#pragma region "Fonctions de base pour vous aider"
typedef uint8_t UInt8;
typedef uint16_t UInt16;
UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read((char*)&texte[0], streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
#pragma endregion

span<Jeu*>spanListeJeux(ListeJeux listeJeux) {
	return span<Jeu*>(listeJeux.elements, listeJeux.nElements);
}
//TODO: Fonction qui cherche un designer par son nom dans une ListeJeux.  Devrait utiliser span.
span<Designer*> spanListeDesigners(ListeDesigners& listeDesigners) {
	span<Designer*> spanDesigners(listeDesigners.elements, listeDesigners.nElements);
	return spanDesigners;

}

Designer* chercheDesigner(string nomDesigner, ListeJeux& listeJeux) {
	span<Jeu*> listeJeuxSpanner;
	span<Designer*> listeDesignersSpanner;
	listeJeuxSpanner = spanListeJeux(listeJeux);
	
	for (Jeu* i : listeJeuxSpanner) {
		listeDesignersSpanner = spanListeDesigners(i->designers);
		for (Designer* j : listeDesignersSpanner) {
			if (j->nom == nomDesigner) {
				return j;
					}
			}

	}
	return nullptr;

}


Designer* lireDesigner(istream& fichier, ListeJeux lj)
{
	Designer designer = {};
	designer.nom = lireString(fichier);
	designer.anneeNaissance = lireUint16(fichier);
	designer.pays = lireString(fichier);

	//TODO: Ajouter en mémoire le designer lu. Il faut revoyer le pointeur créé.
	// TIP: Afficher un message lorsque l'allocation du designer est réussie pour aider au débogage.
	// Vous pouvez enlever l'affichage une fois que le tout fonctionne.
	Designer* designerPtr = chercheDesigner(designer.nom, lj);
	if (designerPtr == nullptr) {
		designerPtr = new Designer(designer);
		cout << "Designer est alloue" << endl;
		cout << designer.nom << endl;
	}//TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.
	return designerPtr; //TODO: Retourner le pointeur vers le designer crée.
}

//TODO: Fonction qui change la taille du tableau de jeux de ListeJeux.

//TODO: Fonction pour ajouter un Jeu à ListeJeux.
void ajouterJeu(Jeu* jeu, ListeJeux& listeJeux) {
	if (listeJeux.capacite == 0) {
		listeJeux.capacite = 1;
		listeJeux.elements = new Jeu*[1];
		listeJeux.elements[0] = jeu;
		//cout << "ajout de " << jeu->titre << endl;
		listeJeux.nElements = 1;
	}
	else if (listeJeux.nElements == listeJeux.capacite) {
		span<Jeu*> ancienne;
		ancienne = spanListeJeux(listeJeux);
		Jeu** nouvelleListe;
		listeJeux.capacite *= 2;
		nouvelleListe = new Jeu* [listeJeux.capacite] ;
		for (auto [i, jeu] : enumerate(ancienne)) {
			nouvelleListe[i] = jeu;
		}
		delete[] listeJeux.elements;
		listeJeux.elements = nullptr;
		listeJeux.elements = nouvelleListe;
		listeJeux.elements[listeJeux.nElements] = jeu;
		listeJeux.nElements += 1;
		//cout << "ajout de " << jeu->titre << endl;

	}
	else {
		listeJeux.elements[listeJeux.nElements] = jeu;
		listeJeux.nElements += 1;
		cout << "ajout de " << jeu->titre << endl;
	}
}

//TODO: Fonction qui enlève un jeu de ListeJeux.
void enleverJeu(Jeu* jeu, ListeJeux& listeJeux) {
	span<Jeu*> lj = spanListeJeux(listeJeux);
	for (auto [i, leJeu] : enumerate(lj)) {
		if (jeu->titre == leJeu->titre) {
			Jeu* jeuTemp;
			//jeuTemp = new Jeu;
			jeuTemp = listeJeux.elements[listeJeux.nElements - 1];
			listeJeux.elements[listeJeux.nElements - 1] = leJeu;
			listeJeux.elements[i] = jeuTemp;
			listeJeux.nElements -= 1;
			//jeuTemp = listeJeux.elements[2];
			cout << "Jeu " << jeu->titre << " enleve" << endl;
			break;
		}
	}
}
Jeu* lireJeu(istream& fichier, ListeJeux lj)
{
	Jeu jeu = {};
	jeu.titre = lireString(fichier);
	jeu.anneeSortie = lireUint16(fichier);
	jeu.developpeur = lireString(fichier);
	jeu.designers.nElements = lireUint8(fichier);
	jeu.designers.capacite = jeu.designers.nElements;
	Designer** tableauDesignerPtr = new Designer* [jeu.designers.capacite];
	jeu.designers.elements = tableauDesignerPtr;
	Jeu* jeuPtr = new  Jeu{ jeu };
	cout << "jeu: " << jeu.titre << "alloue" << endl;
	


	//TODO: Ajouter en mémoire le jeu lu. Il faut revoyer le pointeur créé.
	// TIP: Afficher un message lorsque l'allocation du jeu est réussie pour aider au débogage.
	// Vous pouvez enlever l'affichage une fois que le tout fonctionne.

	
	for ([[maybe_unused]] int i : iter::range(jeu.designers.nElements)) {

		Designer* designerPtr = lireDesigner(fichier, lj);  //TODO: Mettre le designer dans la liste des designer du jeu.
		jeu.designers.elements[i] = designerPtr;
		
		
		//TODO: Ajouter le jeu à la liste des jeux auquel a participé le designer.
		ajouterJeu(jeuPtr, designerPtr->listeJeuxParticipes);
	}
	return jeuPtr; //TODO: Retourner le pointeur vers le nouveau jeu.
}

ListeJeux creerListeJeux(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	int nElements = lireUint16(fichier);
	ListeJeux listeJeux = {};
	listeJeux.nElements = 0 /*nElements*/;
	listeJeux.capacite = 0/*nElements*/;
	Jeu** tableauJeuPtr = nullptr/*new Jeu * [listeJeux.capacite]*/;
	listeJeux.elements = tableauJeuPtr;
	for ([[maybe_unused]] int n : iter::range(nElements))
	{
		Jeu* jeuPtr = lireJeu(fichier,listeJeux);//TODO: Ajouter le jeu à la ListeJeux.
		//listeJeux.elements[n] = jeuPtr;
		ajouterJeu(jeuPtr, listeJeux);
	}
	/*for (int i : iter::range(nElements)) {
		for (int j : iter::range((*(listeJeux.elements[i])).designers.nElements)) {
			Designer* designerExistant = chercheDesigner((*(listeJeux.elements[i])).designers.elements[j]->nom, listeJeux);
			Designer*& designerCourant = (*(listeJeux.elements[i])).designers.elements[j];
			if (designerExistant != designerCourant) {
				delete designerCourant;
				cout << "designer delete" << endl;
				designerCourant = designerExistant;

			}
		}
	}*/

	return listeJeux; //TODO: Renvoyer la ListeJeux.
}

//TODO: Fonction pour détruire un jeu (libération de mémoire allouée).
// TIP: Afficher un message lorsque le jeu est détruit pour aider au débogage.
// Vous pouvez enlever l'affichage une fois que le tout fonctionne.
void detruireJeu(Jeu* jeu) {
	span<Designer*> ld = spanListeDesigners(jeu->designers);
	for (Designer* designer : ld) {
		Jeu** listeTemporaire = designer->listeJeuxParticipes.elements;
		span<Jeu*> ljd(listeTemporaire, designer->listeJeuxParticipes.nElements);
		for (uint8_t i : iter::range<uint8_t>(ljd.size(),1, -1)) {
			if (jeu == designer->listeJeuxParticipes.elements[i-1])
				enleverJeu(jeu, designer->listeJeuxParticipes);
		}
		
	}
	for (Designer* designer : ld) {
		if (designer->listeJeuxParticipes.nElements == 0) {
			delete[] designer->listeJeuxParticipes.elements;
			designer->listeJeuxParticipes.elements = nullptr;
			cout << "listejeuxparticipe desaloue" << endl;
			delete designer;
			cout << "designer desaloue" << endl;
			designer = nullptr;
			break;
		}
	}
	for (uint8_t i : iter::range(ld.size())) {
		jeu->designers.elements[i] = 0;
	}
	delete[] jeu->designers.elements;
	string nom = jeu->titre;
	delete jeu;
	cout << "jeu " << nom << " desaloue" << endl;
}


//TODO: Fonction pour détruire une ListeJeux et tous ses jeux.
void detruireListeJeux(ListeJeux & lj) {
	//uint8_t compteur = 0;
	while(lj.nElements) {
		detruireJeu(lj.elements[lj.nElements - 1]);
		//compteur += 1;
		lj.nElements -= 1;
	}
	delete[] lj.elements;
	cout << "la liste est detruite";
}
//TODO: Fonction pour afficher les infos d'un designer.
void afficherInfoDesigner(Designer& designer) {
	cout << designer.nom << endl;
	cout << designer.anneeNaissance << endl;
	cout << designer.pays << endl;
	// est-ce qu'il faut mettre la liste des jeux dans le quelle il a participé
}

//TODO: Fonction pour afficher les infos d'un jeu ainsi que ses designers.
void afficherInfoJeu(Jeu& jeu) {
	cout << jeu.titre << endl;
	cout << jeu.anneeSortie << endl;
	cout << jeu.developpeur << endl;
	for (int i : iter::range(jeu.designers.nElements)) {
		string  designer = jeu.designers.elements[i]->nom;
		cout << designer  << endl;
	}
}


//TODO: Fonction pour afficher tous les jeux de ListeJeux, séparés par un ligne.
// Votre ligne de séparation doit être différent de celle utilisée dans le main.

void afficherListeJeux(ListeJeux& listeJeux) {
	static const string ligneSeparation = "\n\033[35m**************************************\033[0m\n";
	for (int i : iter::range(listeJeux.nElements)) {
		afficherInfoJeu(*listeJeux.elements[i]);
		for (int j : iter::range(listeJeux.elements[i]->designers.nElements)) {
			afficherInfoDesigner(*listeJeux.elements[i]->designers.elements[j]);
			for (int k : iter::range(listeJeux.elements[i]->designers.elements[j]->listeJeuxParticipes.nElements)) {
				cout << listeJeux.elements[i]->designers.elements[j]->listeJeuxParticipes.elements[k]->titre;
			}
		}
		cout << ligneSeparation << endl;
	}
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	//Jeu* tableau[5];
	//tableau[0] = &jeu1;
	//tableau[1] = &jeu2;
	//ListeJeux lj;
	//lj.elements = tableau;
	//lj.nElements = 0;
	//lj.capacite = 0;
	//Jeu* jeuUn = new Jeu{ "mario", 1999, "emem"};
	//Jeu* jeuDeux = new Jeu{ "pacman", 2000, "abdul"};
	//Jeu* jeuTrois = new Jeu{ "froggy", 1444, "edouard"};

#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
#pragma endregion

	int* fuite = new int;  // Pour vérifier que la détection de fuites fonctionne; un message devrait dire qu'il y a une fuite à cette ligne.

	ListeJeux listeJeu = creerListeJeux("jeux.bin"); //TODO: Appeler correctement votre fonction de création de la liste de jeux.

	static const string ligneSeparation = "\n\033[35m════════════════════════════════════════\033[0m\n";
	cout << ligneSeparation << endl;
	cout << "Premier jeu de la liste :" << endl;
	//TODO: Afficher le premier jeu de la liste (en utilisant la fonction).  Devrait être Chrono Trigger.
	afficherInfoJeu(*(listeJeu.elements[0]));
	cout << ligneSeparation << endl;

	//TODO: Appel à votre fonction d'affichage de votre liste de jeux.
	afficherListeJeux(listeJeu);

	//TODO: Faire les appels à toutes vos fonctions/méthodes pour voir qu'elles fonctionnent et avoir 0% de lignes non exécutées dans le programme (aucune ligne rouge dans la couverture de code; c'est normal que les lignes de "new" et "delete" soient jaunes).  Vous avez aussi le droit d'effacer les lignes du programmes qui ne sont pas exécutée, si finalement vous pensez qu'elle ne sont pas utiles.
	detruireListeJeux(listeJeu);
	cout << "fin" << endl;

	//TODO: Détruire tout avant de terminer le programme.  Devrait afficher "Aucune fuite detectee." a la sortie du programme; il affichera "Fuite detectee:" avec la liste des blocs, s'il manque des delete.
}
