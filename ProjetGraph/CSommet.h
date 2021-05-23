#ifndef CSOM
#define CSOM 0

#include "CArc.h"
using namespace std;

class CSommet {
private:
	unsigned int uiSOMNumeroS;
	CArc** pSOMArcArrivant;
	unsigned int uiSOMTailleArrivant;
	CArc** pSOMArcPartant;
	unsigned int uiSOMTaillePartant;

public:

	//Constructeur par defaut
	CSommet();

	//Constructeur par recopie
	CSommet(CSommet &SOMArg);

	//Destructeur par defaut
	~CSommet();

	/*
	   * Entrée : rien
	   * Sortie : Le numero du sommet
	   * Pré-condition : rien
	   * Post-condition : rien
	  */
	unsigned int SOMGetNumero();

	/*
	   * Entrée : Numero a donner pour le sommet
	   * Sortie : rien
	   * Pré-condition : rien
	   * Post-condition : met a jour le numero du sommet
	  */
	void SOMSetNumero(unsigned int uiSOMArg);

	/*
	   * Entrée : rien
	   * Sortie : La liste des arcs arrivant
	   * Pré-condition : rien
	   * Post-condition : rien
	  */
	CArc** SOMGetArcArrivant();

	/*
	   * Entrée : Liste d'arcs arrivant
	   * Sortie : rien
	   * Pré-condition : rien
	   * Post-condition : Met a jour la liste des arcs arrivant
	  */
	void SOMSetArcArrivant(CArc** pSOMArg);

	/*
	   * Entrée : rien
	   * Sortie : La liste des arcs partant
	   * Pré-condition : rien
	   * Post-condition : rien
	  */
	CArc** SOMGetArcPartant();

	/*
	   * Entrée : Liste d'arcs partant
	   * Sortie : rien
	   * Pré-condition : rien
	   * Post-condition : Met a jour la liste des arcs partant
	  */
	void SOMSetArcPartant(CArc** pSOMArg);

	/*
	   * Entrée : Numero du sommet destination
	   * Sortie : rien
	   * Pré-condition : rien
	   * Post-condition : Ajout l'arc de destination ARCarg dans                        la liste des arcs partant
	  */
	void SOMAjouterArcPartant(int ARCarg);

	/*
	   * Entrée : Numero du sommet destination
	   * Sortie : rien
	   * Pré-condition : rien
	   * Post-condition : Supprime l'arc de destination ARCarg dans                     la liste des arcs partant
	  */
	void SOMSupprimerArcPartant(int ARCarg);

	/*
	   * Entrée : Numero du sommet destination
	   * Sortie : rien
	   * Pré-condition : rien
	   * Post-condition : Ajout l'arc de destination ARCarg dans                        la liste des arcs arrivant
	  */
	void SOMAjouterArcArrivant(int ARCarg);

	/*
	   * Entrée : Numero du sommet destination
	   * Sortie : rien
	   * Pré-condition : rien
	   * Post-condition : Supprime l'arc de destination ARCarg dans                     la liste des arcs arrivant
	  */
	void SOMSupprimerArcArrivant(int ARCarg);

	//Methode d'affichage d'un sommet
	void SOMAffichage();
};
#endif
