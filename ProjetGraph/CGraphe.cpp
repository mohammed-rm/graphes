/*#include "CGraphe.h"
#include <iostream>

CGraphe::CGraphe(void) {
}

CGraphe::CGraphe(CGraphe & GRAArg) {
}

CGraphe::CGraphe(CSommet** pSOMArg, unsigned int uiNombreSommet) {
}

CGraphe::CGraphe(unsigned int uiNbreSommet) {
}

CGraphe::~CGraphe() {
}

/*CGraphe &::operator=(CGraphe & GRAArg){
}

CSommet* CGraphe::GRAGetSommet(unsigned int uiNumero) {
}

void CGraphe::GRASetSommet(CSommet** pSOMArg, unsigned int uiNombreSommet) {
}

void CGraphe::GRAAddSommet(CSommet & pSOMArg) {
}

void CGraphe::GRASupprimerSommet(unsigned int uiNumero) {
}

void CGraphe::GRAAffiche() {
	cout << "Nombre de sommets dans le Graphe : " << uiGRANbrSommet << endl;
	cout << "Voici la liste des sommets : " << std::endl;
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbrSommet; uiBoucle++) {
		TGRASommet[uiBoucle]->SOMAffichage();
	}
}
void CGraphe::GRALirefichier(char* pcNomFichier) {
	ifstream fFichierTXT(pcNomFichier);
	//L'ouverture s'est bien passée, on peut donc lire
	if (fFichierTXT) {
		char cCaractereFichier; //Caractere pour lire
		int iBoucle = 0; // compteur des =
		int iNbArc = 0;
		while (fFichierTXT.get(cCaractereFichier)) {
			//On lit juste ce qui est apres le symbol egale
			if (cCaractereFichier == '=') {
				// On recontre une information à stocker
				// On ignore les espaces
				fFichierTXT.get(cCaractereFichier);
				while (cCaractereFichier == ' ') {
					fFichierTXT.get(cCaractereFichier);
				}
				// Gérer le nombre de sommets
				if (iBoucle == 0) {
					uiGRANbrSommet = cCaractereFichier - 48;
					iBoucle++;
				}
				// Gérer le nombre d'arcs
				else if (iBoucle == 1) {
					iNbArc = cCaractereFichier - 48;
					iBoucle++;
				}
				// On saute cette ligne (pas d'informations a stocker)
				else if (iBoucle == 2) {
					iBoucle++;
				}
				// Gérer les sommets
				else if (iBoucle == 3) {
				}
			}
		}
	}
	else {
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}*/
