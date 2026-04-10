#include "Personnage.hpp"
#include "Heros.hpp"
#include "Vilain.hpp"
#include "VilainHeros.hpp"
#include "ListeLiee.hpp"
#include <fstream>
#include <vector>
#include <functional>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include <queue>
#include <map>

using namespace std;
using namespace iter;

using UInt8  = uint8_t;
using UInt16 = uint16_t;

UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}

template <typename T>
vector<T> lireFichier(istream& fichier)
{
	vector<T> elements;
	for ([[maybe_unused]] int i : range(lireUint16(fichier)))
		elements.push_back(T(fichier));
	return elements;
}

ifstream ouvrirLectureFichierBinaire(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	return fichier;
}

// Permet d'avoir une référence non-const à un objet temporaire.
template <typename T> T& temporaireModifiable(T&& objet) { return objet; }

template <typename T>
vector<T> lireFichier(const string& nomFichier)
{
	return lireFichier<T>(temporaireModifiable(
		ouvrirLectureFichierBinaire(nomFichier)));
}

template <typename T>
Iterateur<T> trouverParNom(ListeLiee<T>& liste, const string& nom)
{
	Iterateur<T> fin = liste.end();
	for (Iterateur<T> pos = liste.begin(); pos != fin; pos.avancer()) {
		if ((*pos).getNom() == nom)
			return pos;
	}
	return fin;
}

int main()
{
#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
#pragma endregion

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	static const string separateurSections = "\033[95m" + trait + "\033[0m\n";
	static const string separateurElements = "\033[33m" + trait + "\033[0m\n";

	//{ Solutionnaire du TD4:
	vector<Heros> heros = lireFichier<Heros>("heros.bin");
	vector<Vilain> vilains = lireFichier<Vilain>("vilains.bin");
	vector<unique_ptr<Personnage>> peronnages;  // Doit être des pointeurs pour le polymorphisme, l'énoncé ne force pas les unique_ptr.

#if 1 //TODO: Vous n'avez pas à conserver ces affichages pour le TD5, ils sont pour le solutionnaire du TD4:
	cout << separateurSections << "Heros:" << endl;
	for (auto& h : heros) {
		cout << separateurElements;
		h.changerCouleur(cout, 0);
		h.afficher(cout);
	}

	cout << separateurSections << "Vilains:" << endl;
	for (auto& v : vilains) {
		std::cout << separateurElements;
		v.changerCouleur(cout, 0);
		v.afficher(std::cout);
	}

	for (auto& h : heros)
		peronnages.push_back(make_unique<Heros>(h));

	for (auto& v : vilains)
		peronnages.push_back(make_unique<Vilain>(v));

	peronnages.push_back(make_unique<VilainHeros>(vilains[1], heros[2]));

	std::cout << separateurSections << "Personnages:" << endl;
	for (auto& p : peronnages) {

		std::cout << separateurElements;
		p->changerCouleur(std::cout, 0);
		p->afficher(std::cout);
	}
	std::cout << separateurSections << "Un autre vilain heros (exemple de l'énoncé du TD):" << endl;
	VilainHeros kefkaCrono(vilains[2], heros[0]);
	kefkaCrono.changerCouleur(std::cout, 1);
	kefkaCrono.afficher(std::cout);
#endif
	//}

	//TODO: Transférez les héros du vecteur heros dans une ListeLiee.
	ListeLiee<Heros> listeLieeHeros;
	for (uint8_t i = 0; i < size(heros); i++)
		listeLieeHeros.push_back(heros[i]);
	//TODO: Créez un itérateur sur la liste liée à la position du héros Alucard
	// Servez-vous de la fonction trouverParNom définie plus haut
	Iterateur<Heros> it(trouverParNom(listeLieeHeros, "Alucard"));
	//TODO: Servez-vous de l'itérateur créé précédemment pour trouver l'héroine Aya Brea,
	// en sachant qu'elle se trouve plus loin dans la liste.
	Heros  hero1 = *it;
	while (hero1.getNom() != "Aya Brea") {
		it.avancer();
		hero1 = *it;
	}
	UInt8 tailleAvant = listeLieeHeros.size();
	//TODO: Ajouter un hero bidon à la liste avant Aya Brea en vous servant de l'itérateur.
	Heros heroBidon("Aliou", "Echec", "les blancs");
	it = listeLieeHeros.insert(it, heroBidon);
	//TODO: Assurez-vous que la taille de la liste est correcte après l'ajout.
	UInt8 tailleApres = listeLieeHeros.size();
	bool estEgal = tailleApres == ++tailleAvant;
	cout << estEgal << endl;
	//TODO: Reculez votre itérateur jusqu'au héros Mario et effacez-le en utilisant l'itérateur, puis affichez le héros suivant dans la liste (devrait êter "Naked Snake/John").
	hero1 = *it;
	while (hero1.getNom() != "Mario") {
		it.reculer();
		hero1 = *it;
	}
	tailleAvant = listeLieeHeros.size();
	it = listeLieeHeros.erase(it);
	//TODO: Assurez-vous que la taille de la liste est correcte après le retrait.
	tailleApres = listeLieeHeros.size();
	estEgal = tailleApres == --tailleAvant;
	cout << estEgal << endl;
	//TODO: Effacez le premier élément de la liste.
	listeLieeHeros.erase(listeLieeHeros.begin());
	//TODO: Affichez votre liste de héros en utilisant un itérateur. La liste débute
	// avec le héros Randi et n'a pas Mario.
	// Servez-vous des methodes begin et end de la liste...
	it = listeLieeHeros.begin();
	do {
		hero1 = *it;
		hero1.afficher(cout);
		it.avancer();
	} while (it != listeLieeHeros.end());
	//TODO: Refaite le même affichage mais en utilisant une simple boucle "for" sur intervalle.
	it = listeLieeHeros.begin();
	for (UInt8 i = 0; i < listeLieeHeros.size(); i++) {
		hero1 = *it;
		hero1.afficher(cout);
		it.avancer();
	}
	//TODO: Utilisez un conteneur pour avoir les héros en ordre alphabétique (voir point 2 de l'énoncé).
	multimap<string, Heros> listeHeros; 

	for (Heros hero : heros){
		listeHeros.insert({ hero.getNom(), hero });
	}
	listeHeros.find("Crono")->second.afficher(cout);

	//TODO: Assurez-vous de n'avoir aucune ligne non couverte dans les classes pour la liste liée.  Il peut y avoir des lignes non couvertes dans les personnages...
}
