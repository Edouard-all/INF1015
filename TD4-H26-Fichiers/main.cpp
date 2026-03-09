#include <fstream>
#include "bibliotheque_cours.hpp"
#include <vector>
//#include "Personnage.hpp"
//#include "Vilain.hpp"
//#include "Hero.hpp"
//#include "Vilain.hpp"
#include "VilainHero.hpp"
using namespace std;

using UInt8  = uint8_t;
using UInt16 = uint16_t;
// Trait de separation
static const string trait =
"\033[92m═════════════════════════════════════════════════════════════════════════";


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

template <class T>
concept Dereferencable = requires (T&& t) { *std::forward<T>(t); };

// Surcharge quand c'est un pointeur
template <Dereferencable T> 
decltype(auto) as_ref(T&& t)
{
	return *std::forward<T>(t);
}

// Surcharge moins contrainte (donc quand ce n'est pas un pointeur)
template <class T>
T&& as_ref(T&& t) {
	return std::forward<T>(t);
}

template<typename T>
const void afficher(vector<T> listeItems) {
	for (T item : listeItems) {
		item.afficher();
		cout << trait << endl;
	}
}

//template<typename T>
//void ajouterElement(vector<T> elements,vector<Personnage> listePersonnages) {
//	for (T element : elements) {
//		listePersonnages.push_back(element);
//	}
//}
int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	
	// Ouverture des fichiers binaires
	ifstream fichierHeros("heros.bin", ios::binary);
	ifstream fichierVilains("vilains.bin", ios::binary);
	fichierHeros.exceptions(ios::failbit);
	fichierVilains.exceptions(ios::failbit);

	//TODO: Votre code pour le main commence ici
	vector<Vilain> vilains;
	vector<Hero> heros;
	vector<Personnage> personnages;
	Personnage copieHero;
	VilainHero vilainHero;
	uint16_t nHero = lireUint16(fichierHeros);
	uint16_t nVilain = lireUint16(fichierVilains);
	uint8_t nAllie = 0;


	for (int i = 0; i < nHero; i++){
		Hero hero = Hero();
		hero.changerCouleur(bleu);
		hero.setNom(lireString(fichierHeros));
		hero.setJeu(lireString(fichierHeros));
		hero.setEnnemie(lireString(fichierHeros));
		nAllie = lireUint8(fichierHeros);
		vector<string> listeAllies;
		for (int j = 0; j < nAllie; j++){
			listeAllies.push_back(lireString(fichierHeros));
		}
		hero.setListeAllies(listeAllies);
		heros.push_back(hero);

	}

	for (int i = 0; i < nVilain; i++){
		Vilain vilain = Vilain();
		vilain.changerCouleur(rouge);
		vilain.setNom(lireString(fichierVilains));
		vilain.setJeu(lireString(fichierVilains));
		vilain.setObjectif(lireString(fichierVilains));
		vilains.push_back(vilain);
	}
	//Est-ce que ça respecte le principe DRY

	afficher(heros);
	afficher(vilains);
	//ajouterElement(heros, personnages);
	//ajouterElement(vilains, personnages);
	/*for (Hero hero : heros){
		hero.afficher();
		personnages.push_back(hero);
		cout << trait << endl;
	}
	for (Vilain vilain : vilains){
		vilain.afficher();
		personnages.push_back(vilain);
		cout << trait << endl;
	}*/
	// copie hero dans personnage
	//copieHero = heros[0];

	/*for (Personnage personnage: personnages){
		personnage.afficher();
		cout << trait << endl;
	}*/
	afficher(personnages);
	int i = 0;
	if (heros[0].getEnnemie() == vilains[0].getNom()){
		while(heros[0].getEnnemie() == vilains[i].getNom()){
			i++;
		}
	}
	vilainHero = VilainHero(vilains[i],heros[0]);
	vilainHero.changerCouleur(mauve);
	personnages.push_back(vilainHero);
	vilainHero.afficher();

}
