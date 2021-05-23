#ifndef CGRAPHE_H
#define CGRAPHE_H 2

#include "CSommet.h"
#include <cstring>
#include <fstream>
#include "CException.h"
#include <stdlib.h>
class CGraphe {
	//Attributs
private:
	CSommet** TGRASommet;
	unsigned int uiGRANbrSommet;
public:
	//Methodes

	  //Constructeur par defaut
	CGraphe(void);


	//Constructeur par recopie
	CGraphe(CGraphe & GRAArg);

	/*
	entree : un tableau contenant les sommets et le nombre de sommet dans le graphe
	sortie : rien
	Pre-condition : rien
	Post-condition : creer un graphe avec ses sommets et met a jour son nombre
	*/
	CGraphe(CSommet** pSOMArg, unsigned int uiNombreSommet);


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
	entree : un numero
	sortie : rien
	Pre-condition : rien
	Post-condition : recupere un sommet a partir de son numero
	*/
	CSommet* GRAGetSommet(unsigned int uiNumero);

	/*
	entree : un tableau de sommet
	sortie : rien
	Pre-condition : rien
	Post-condition : ajoute un tableau de sommet au graphe
	*/
	void GRASetSommet(CSommet** pSOMArg, unsigned int uiNombreSommet);


	/*
	entree : un sommet
	sortie : rien
	Pre-condition : rien
	Post-condition : ajoute un sommet au graphe
	*/
	void GRAAddSommet(CSommet & pSOMArg);

	/*
	entree : un natuel
	sortie : rien
	Pre-condition : rien
	Post-condition : supprime un sommet du graphe a partir de son numero
	*/
	void GRASupprimerSommet(unsigned int uiNumero);


	//Methode d'affichage d'un graphe
	void GRAAffiche();

	//Methode dde lecture d'un fichier
	void GRALirefichier(char* pcNomFichier);

};
#endif