// Fonctions pour lire le fichier binaire.
#include "lectureFichierJeux.hpp"
#include <fstream>
#include <cstdint>
#include "cppitertools/range.hpp"
using namespace std;

using UInt8  = uint8_t;
using UInt16 = uint16_t;

#pragma region "Fonctions de lecture de base"
//TODO: Remplacer lireUint8 et lireUint16 par une seule fonction générique qui permet les deux, mais permettre uniquement des types qui sont is_trivially_copyable_v (un trait de type).
#define PAR_CONCEPT 1
#if PAR_CONCEPT
template <typename T> concept EstCopiableTrivialement = is_trivially_copyable_v<T>;  // Manière 1, avec un concept qui ne permet pas cette fonction sinon.
template <EstCopiableTrivialement T>
#else
template <typename T>
#endif
T lire(istream& fichier)
{
#if !PAR_CONCEPT
	static_assert(is_trivially_copyable_v<T>, "Le type doit être copiable trivialement pour le lire d'un fichier binaire");  // Manière 2, avec une assertion qui échoue si le type n'est pas bon.
#endif
	T valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lire<UInt16>(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
#pragma endregion

shared_ptr<Concepteur> chercherConcepteur(ListeJeux& listeJeux, const string& nom)
{
	//TODO: Compléter la fonction (équivalent de trouverDesigner du TD2).
	for (auto& j : listeJeux.enSpan()) {
		#if 0  // Avant d'avoir fait la méthode pour chercher, on peut faire une boucle simple:
		for (auto& c : j->getConcepteurs().enSpan()) {
			if (c->getNom() == nom)
				return c;
		}
		#else  // On peut aussi utiliser la méthode de recherche:
		if (shared_ptr<Concepteur> concepteur = j->getConcepteurs().trouver(
				[&](auto& c) { return c.getNom() == nom; }
			))
			return concepteur;
		#endif
	}
	return nullptr;
}

shared_ptr<Concepteur> lireConcepteur(ListeJeux& lj, istream& f)
{
	string nom              = lireString(f);
	unsigned anneeNaissance = lire<UInt16>(f);
	string pays             = lireString(f);

	//TODO: Compléter la fonction (équivalent de lireDesigner du TD2).
	if (shared_ptr<Concepteur> ptrConcepteur = chercherConcepteur(lj, nom))
		return ptrConcepteur;
	else
		return make_shared<Concepteur>(nom, anneeNaissance, pays);
}

shared_ptr<Jeu> lireJeu(istream& f, ListeJeux& lj)
{
	string titre          = lireString(f);
	unsigned anneeSortie  = lire<UInt16>(f);
	string developpeur    = lireString(f);
	unsigned nConcepteurs = lire<UInt8>(f);
	//TODO: Compléter la fonction (équivalent de lireJeu du TD2).
	shared_ptr<Jeu> ptrJeu = make_shared<Jeu>(titre, anneeSortie, developpeur);
	for (unsigned int i = 0; i < nConcepteurs; i++)
		ptrJeu->getConcepteurs().ajouter(lireConcepteur(lj, f));

	cout << "\033[96m" << "Allocation en mémoire du jeu " << ptrJeu->getTitre()
		<< "\033[0m" << endl;
	return ptrJeu;
}

ListeJeux creerListeJeux(const string& nomFichier)
{
	ifstream f(nomFichier, ios::binary);
	f.exceptions(ios::failbit);
	int nElements = lire<UInt16>(f);
	//TODO: Compléter la fonction.
	ListeJeux listeJeux;
	for ([[maybe_unused]] int i : iter::range(nElements))
		listeJeux.ajouter(lireJeu(f, listeJeux));

#if 0  // Test qui ne compile pas car string n'est pas is_trivially_copyable_v
	{ string texte = lire<string>(f); }
#endif

	return listeJeux;
}
