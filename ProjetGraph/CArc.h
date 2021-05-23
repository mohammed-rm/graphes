#ifndef CARC
#define CARC 0

using namespace std;

class CArc {
private:
	// Attributs
	unsigned int uiARCDestination;// Numéro du sommet destination

public:
	//Methodes

	//Constructeur par defaut
	CArc();
	//Constructeur par recopie
	CArc(CArc &ARCArg);

	/*
	   * Entrée : le nombre du sommet destination
	   * Sortie : rien
	   * Pré-condition : rien
	   * Post-condition : creer un arc et met a jour son nombre
	  */
	CArc(unsigned int uiDestination);

	/*
	   * Entrée : Un Arc ARCArg
	   * Sortie : Un booléen
	   * Pré-condition : Aucune
	   * Post-condition : Egalité des deux arc
	   */
	bool operator==(CArc &ARCArg);

	/*
	   * Entrée : rien
	   * Sortie : un naturel
	   * Pré-condition : Aucune
	   * Post-condition : recupere le numero du sommet destination
	   */
	unsigned int ARCGetDestination();

	/*
	   * Entrée : Le numero du sommet destination
	   * Sortie : rien
	   * Pré-condition : Aucune
	   * Post-condition : met a jour le numero du sommet
	   */
	void ARCSetDestination(unsigned int uiNumero);

	//Methode d'affichage d'un arc
	void ARCAfficher();

};

#endif