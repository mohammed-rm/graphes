#ifndef CGRAPHE_H
#define CGRAPHE_H 2

#include "CSommet.h"
#include "CParser.h"
#include <cstring>
#include <fstream>
#include "CException.h"
#include <stdlib.h>

#define EXC_Failed_Parser 0

class CGraphe {
	//Attributs
private:
	CSommet* TGRASommet;
	unsigned int uiGRANbrSommet;
public:
	//Methodes

	  //Constructeur par defaut
	CGraphe(void);


	//Constructeur par recopie
	CGraphe(CGraphe & GRAArg);

	//Constructeur par Parseur
	CGraphe(CParser & PARArg);

	/*
	entree : un tableau contenant les sommets et le nombre de sommet dans le graphe
	sortie : rien
	Pre-condition : rien
	Post-condition : creer un graphe avec ses sommets et met a jour son nombre
	*/
	CGraphe(CSommet* pSOMArg, unsigned int uiNombreSommet);


	/*
	entree : un naturel correspondant au nombre de sommets
	sortie : rien
	Pre-condition : rien
	Post-condition : creer un graphe avec uiNbreSommet de sommets
	*/
	CGraphe(unsigned int uiNbreSommet);


	//Destructeur
	~CGraphe();



	/*
	entree : un objet CGraphe
	sortie : rien
	Pre-condition : rien
	Post-condition : operateur = servant pour le constructeur de recopie (variable dynamique)
	*/
	CGraphe & operator=(CGraphe & GRAArg);

	/*
	  entree : Numero du sommet dont on veut l'index
	  sortie : l'index du sommet dans le tableau
	  Pre-condition : rien
	  Post-condition : rien
	  */
	unsigned int GRAGetIndexSom(unsigned int uiNumeroSom);

	/*
	entree : rien
	sortie : rien
	Pre-condition : rien
	Post-condition : recupere le nombre de sommet dans le graphe
	*/
	unsigned int GRAGetNbSommet();

	/*
	entree : un tableau de sommet
	sortie : rien
	Pre-condition : rien
	Post-condition : ajoute un tableau de sommet au graphe
	*/
	void GRASetSommet(CSommet* pSOMArg, unsigned int uiNombreSommet);


	/*
	entree : un sommet
	sortie : rien
	Pre-condition : rien
	Post-condition : ajoute un sommet au graphe
	*/
	void GRAAddSommet(CSommet & pSOMArg);

	/*
	entree : un numero naturel
	sortie : rien
	Pre-condition : rien
	Post-condition : supprime un sommet du graphe a partir de son numero
	*/
	void GRASupprimerSommet(unsigned int uiNumero);


	//Methode d'affichage d'un graphe
	void GRAAffiche();


};
#endif