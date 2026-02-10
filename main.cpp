/**
* Programme qui détermine si une année lue du clavier est bissextile.
* \file   main.cpp
* \author Aliou Diallo et Édouard Allaire
* \date   22 janvier 2009
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
//span<Jeu*>spanListeJeux(ListeJeux& listeJeux) {
//	span<Jeu*> spanJeux(listeJeux.elements, listeJeux.nElements);
//	return spanJeux;
//}

span<Designer*> spanListeDesigners(ListeDesigners& listeDesigners) {
	span<Designer*> spanDesigners(listeDesigners.elements, listeDesigners.nElements);
	return spanDesigners;

}

Designer* chercheDesigner(string nomDesigner, ListeJeux& listeJeux, ListeDesigners& listeDesigners) {
	span<Jeu*> listeJeuxSpanner;
	span<Designer*> listeDesignersSpanner;
	listeJeuxSpanner = spanListeJeux(listeJeux);
	listeDesignersSpanner = spanListeDesigners(listeDesigners);
	for (Jeu* i : listeJeuxSpanner) {
		for (Designer* j : listeDesignersSpanner) {
			if (j->nom == nomDesigner) {
				return j;
					}
			}

	}
	return nullptr;

}

Designer* lireDesigner(istream& fichier)
{
	Designer designer = {};
	designer.nom = lireString(fichier);
	designer.anneeNaissance = lireUint16(fichier);
	designer.pays = lireString(fichier);

	//TODO: Ajouter en mémoire le designer lu. Il faut revoyer le pointeur créé.
	// TIP: Afficher un message lorsque l'allocation du designer est réussie pour aider au débogage.
	// Vous pouvez enlever l'affichage une fois que le tout fonctionne.


	cout << designer.nom << endl;  //TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.
	return {}; //TODO: Retourner le pointeur vers le designer crée.
}

//TODO: Fonction qui change la taille du tableau de jeux de ListeJeux.

//TODO: Fonction pour ajouter un Jeu à ListeJeux.
void ajouterJeu(Jeu* jeu, ListeJeux& listeJeux) {
	if (listeJeux.capacite == 0) {
		listeJeux.capacite = 1;
		listeJeux.elements = new Jeu*[1];
		listeJeux.elements[0] = jeu;
		cout << "ajout de " << jeu->titre << endl;
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
		//listeJeux.elements = nullptr;
		listeJeux.elements = nouvelleListe;
		listeJeux.elements[listeJeux.nElements] = jeu;
		listeJeux.nElements += 1;
		cout << "ajout de " << jeu->titre << endl;

	}
	else {
		listeJeux.nElements += 1;
		listeJeux.elements[listeJeux.nElements] = jeu;
		cout << "allocation" << jeu->titre << endl;
	}
}

//TODO: Fonction qui enlève un jeu de ListeJeux.
//void enleverJeu(Jeu* jeu, ListeJeux& listeJeux) {
//	span<Jeu*>ancienne;
//	ancienne = spanListeJeux(listeJeux);
//	Jeu** nouvelleListe;
//	nouvelleListe = new Jeu* [listeJeux.capacite];
//	uint8_t counter = 0;
//	for (auto [i, unJeu] : enumerate(ancienne)) {
//		if (jeu != unJeu) {
//			nouvelleListe[counter] = unJeu;
//			counter++;
//		}
//	}
//	listeJeux.nElements -= 1;
//	delete[] listeJeux.elements;
//	listeJeux.elements = nullptr;
//	listeJeux.elements = nouvelleListe;
//	if ((listeJeux.nElements == listeJeux.capacite / 2 )&&(listeJeux.nElements !=0)) {
//		Jeu** listeTemporaire;
//		listeJeux.capacite /= 2;
//		listeTemporaire = new Jeu* [listeJeux.capacite];
//		span<Jeu*>laListe;
//		laListe = spanListeJeux(listeJeux);
//		for (auto [j, leJeu] : enumerate(laListe)) {
//			listeTemporaire[j] = leJeu;
//		}
//		delete[] listeJeux.elements;
//		listeJeux.elements = nullptr;
//		listeJeux.elements = listeTemporaire;
//	}
//	else if (listeJeux.nElements == 0) {
//		delete[] listeJeux.elements;
//		listeJeux.elements = nullptr;
//	}
//	cout << "jeu " << jeu->titre << " est enleve" << endl;
//}
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
Jeu* lireJeu(istream& fichier)
{
	Jeu jeu = {};
	jeu.titre = lireString(fichier);
	jeu.anneeSortie = lireUint16(fichier);
	jeu.developpeur = lireString(fichier);
	jeu.designers.nElements = lireUint8(fichier);

	//TODO: Ajouter en mémoire le jeu lu. Il faut revoyer le pointeur créé.
	// TIP: Afficher un message lorsque l'allocation du jeu est réussie pour aider au débogage.
	// Vous pouvez enlever l'affichage une fois que le tout fonctionne.


	for ([[maybe_unused]] int i : iter::range(jeu.designers.nElements)) {
		lireDesigner(fichier);  //TODO: Mettre le designer dans la liste des designer du jeu.
		//TODO: Ajouter le jeu à la liste des jeux auquel a participé le designer.
	}
	return {}; //TODO: Retourner le pointeur vers le nouveau jeu.
}

ListeJeux creerListeJeux(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	int nElements = lireUint16(fichier);
	ListeJeux listeJeux = {};
	for ([[maybe_unused]] int n : iter::range(nElements))
	{
		lireJeu(fichier);//TODO: Ajouter le jeu à la ListeJeux.
	}

	return {}; //TODO: Renvoyer la ListeJeux.
}

//TODO: Fonction pour détruire un jeu (libération de mémoire allouée).
// TIP: Afficher un message lorsque le jeu est détruit pour aider au débogage.
// Vous pouvez enlever l'affichage une fois que le tout fonctionne.
void detruireJeu(Jeu* jeu) {
	span<Designer*> ld = spanListeDesigners(jeu->designers);
	for (Designer* designer : ld) {
		Jeu** listeTemporaire = designer->listeJeuxParticipes.elements;
		span<Jeu*> ljd(listeTemporaire, designer->listeJeuxParticipes.nElements);
		for (Jeu* unJeu : ljd) {
			if (jeu == unJeu)
				enleverJeu(unJeu, designer->listeJeuxParticipes);
		}
		
	}
	string nom = jeu->titre;
	delete jeu;
	cout << "jeu " << nom << " desaloue" << endl;
	for (Designer* designer : ld) {
		if (designer->listeJeuxParticipes.nElements == 0) {
			delete[] designer->listeJeuxParticipes.elements;
			designer->listeJeuxParticipes.elements = nullptr;
			delete designer;
			designer = nullptr;
			break;
		}
	}
}


//TODO: Fonction pour détruire une ListeJeux et tous ses jeux.
void detruireListeJeux(ListeJeux & lj) {
	while(lj.nElements) {
		detruireJeu(lj.elements[0]);
		lj.nElements -= 1;
	}
	//delete[] lj.elements;
	cout << "la liste est detruite";
}
//TODO: Fonction pour afficher les infos d'un designer.

//TODO: Fonction pour afficher les infos d'un jeu ainsi que ses designers.


//TODO: Fonction pour afficher tous les jeux de ListeJeux, séparés par un ligne.
// Votre ligne de séparation doit être différent de celle utilisée dans le main.


int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	Jeu* tableau[5];
	//tableau[0] = &jeu1;
	//tableau[1] = &jeu2;
	ListeJeux lj;
	lj.elements = tableau;
	lj.nElements = 0;
	lj.capacite = 0;
	Jeu* jeuUn = new Jeu{ "mario", 1999, "emem"};
	Jeu* jeuDeux = new Jeu{ "pacman", 2000, "abdul"};
	Jeu* jeuTrois = new Jeu{ "froggy", 1444, "edouard"};

#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
#pragma endregion

	int* fuite = new int;  // Pour vérifier que la détection de fuites fonctionne; un message devrait dire qu'il y a une fuite à cette ligne.

	creerListeJeux("jeux.bin"); //TODO: Appeler correctement votre fonction de création de la liste de jeux.

	static const string ligneSeparation = "\n\033[35m════════════════════════════════════════\033[0m\n";
	cout << ligneSeparation << endl;
	cout << "Premier jeu de la liste :" << endl;
	//TODO: Afficher le premier jeu de la liste (en utilisant la fonction).  Devrait être Chrono Trigger.

	cout << ligneSeparation << endl;

	//TODO: Appel à votre fonction d'affichage de votre liste de jeux.
	
	//TODO: Faire les appels à toutes vos fonctions/méthodes pour voir qu'elles fonctionnent et avoir 0% de lignes non exécutées dans le programme (aucune ligne rouge dans la couverture de code; c'est normal que les lignes de "new" et "delete" soient jaunes).  Vous avez aussi le droit d'effacer les lignes du programmes qui ne sont pas exécutée, si finalement vous pensez qu'elle ne sont pas utiles.
	ajouterJeu(jeuTrois, lj);
	ajouterJeu(jeuDeux, lj);
	ajouterJeu(jeuUn, lj);
	/*enleverJeu(jeu3, lj);
	enleverJeu(jeu2, lj);
	enleverJeu(jeu1, lj);*/
	Designer* designer1 = new Designer;
	designer1->nom = "Jason";
	designer1->anneeNaissance = 2006;
	designer1->listeJeuxParticipes = lj;
	Designer* designer2 = new Designer;
	designer2->nom = "Aliou";
	designer2->anneeNaissance = 2009;
	designer2->listeJeuxParticipes = lj;
	Designer* designer3 = new Designer;
	designer3->nom = "Edouard";
	designer3->anneeNaissance = 2005;
	designer3->listeJeuxParticipes = lj;

	ListeDesigners desiListe;
	desiListe.nElements = 3;
	desiListe.capacite = 4;
	
	Designer* tableaud[5] = { designer1, designer2, designer3 };

	desiListe.elements = tableaud;
	jeuUn->designers = desiListe;
	jeuDeux->designers = desiListe;
	jeuTrois->designers = desiListe;




	chercheDesigner("Aliou", lj, desiListe);
	detruireListeJeux(lj);
	//TODO: Détruire tout avant de terminer le programme.  Devrait afficher "Aucune fuite detectee." a la sortie du programme; il affichera "Fuite detectee:" avec la liste des blocs, s'il manque des delete.
}
