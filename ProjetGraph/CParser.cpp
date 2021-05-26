#include "CParser.h"
#include <iostream> 


CParser::CParser() {
	puiPARArc = nullptr;
	piPARSommet = nullptr;
	uiPARNombreSommet = 0;
	uiPARNombreArc = 0;
}

CParser::CParser(char* pcArg) {
	pcPARNom_fichier = (char*)malloc(sizeof(char));
	puiPARArc = nullptr;
	piPARSommet = nullptr;
	uiPARNombreSommet = 0;
	uiPARNombreArc = 0;
	strcpy(pcPARNom_fichier, pcArg);
}

CParser::~CParser() {
	if (uiPARNombreArc != 0) {
		for (unsigned int uiBoucle = 0; uiBoucle < uiPARNombreArc; uiBoucle++) {
			delete(puiPARArc[uiBoucle]);
		}
		delete(puiPARArc);
	}
	if (uiPARNombreSommet != 0) {
		delete(piPARSommet);
	}

}

void CParser::PARSetNomFichier(char* STRArg) {
	pcPARNom_fichier = STRArg;
}


char* CParser::PARGetNomFichier() {
	return pcPARNom_fichier;
}

unsigned int CParser::PARGetNombreSommet() {
	return uiPARNombreSommet;
}

unsigned int CParser::PARGetNombreArc() {
	return uiPARNombreArc;
}

unsigned int * CParser::PARGetSommet() {
	return piPARSommet;
}

unsigned int ** CParser::PARGetArc() {
	return puiPARArc;
}

void CParser::PARLecture() {
	//ouverture du fichier
	std::ifstream fFichierTXT(pcPARNom_fichier);
	if (!fFichierTXT) {
		CException EXCOpenFailed;
		EXCOpenFailed.EXCModifier_valeur(EXC_Failed_open_file);
		throw(EXCOpenFailed);
	}
	else {
		char cCaractereFichier; //Caractere pour lire
		int iBoucle = 0; // compteur des =
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
					char* pcNbSom = new char[2048];
					int iIndiceSom = 0;
					while (48 <= cCaractereFichier && cCaractereFichier <= 57) {
						pcNbSom[iIndiceSom] = cCaractereFichier;
						iIndiceSom++;
						fFichierTXT.get(cCaractereFichier);
					}
					uiPARNombreSommet = unsigned int (atof(pcNbSom));
					iBoucle++;
				}
				// Gérer le nombre d'arcs
				else if (iBoucle == 1) {
					char* pcNbArc = new char[2048];
					int iIndiceArc = 0;
					while (48 <= cCaractereFichier && cCaractereFichier <= 57) {
						pcNbArc[iIndiceArc] = cCaractereFichier;
						iIndiceArc++;
						fFichierTXT.get(cCaractereFichier);
					}
					uiPARNombreArc = unsigned int (atof(pcNbArc));
					iBoucle++;
				}
				// On gere les sommets
				else if (iBoucle == 2) {
					iBoucle++;
					fFichierTXT.get(cCaractereFichier);//Pour passer a une nouvelle ligne
					// Chaine de caractères pour lire ligne par ligne
					char* pcLigne = new char[2048];
					//Tableau pour stocker les sommets
					piPARSommet = (unsigned int*)malloc(uiPARNombreSommet * sizeof(unsigned int));
					for (unsigned int uiBoucle = 0; uiBoucle < uiPARNombreSommet; uiBoucle++) {
						fFichierTXT.getline(pcLigne, 2048);
						char* pcResultat = new char[2048];//Chaine pour stocker le nombre du sommet
						int iIndiceResultat = 0;//Indice pour acces a la chaine pcResultat
			//Acces a la ligne caractères par caractères
						for (int iBoucleLigneFichier = 0; iBoucleLigneFichier < strlen(pcLigne); iBoucleLigneFichier++) {
							//Boucle qui prend en compte les nombres negatifs positifs et decimal
							while ((48 <= pcLigne[iBoucleLigneFichier] && pcLigne[iBoucleLigneFichier] <= 57)
								|| pcLigne[iBoucleLigneFichier] == '.'
								|| pcLigne[iBoucleLigneFichier] == '-') {
								pcResultat[iIndiceResultat] = pcLigne[iBoucleLigneFichier];
								iBoucleLigneFichier++;
								iIndiceResultat++;
							}
							//Stocker le resultat
							piPARSommet[uiBoucle] = unsigned int(atof(pcResultat));
						}
					}
				}
				// Gérer les arcs
				else if (iBoucle == 3) {
					fFichierTXT.get(cCaractereFichier);//Pour passer a une nouvelle ligne
					// Chaine de caractères pour lire ligne par ligne
					char* pcLigne = new char[2048];
					//Tableau pour stocker les arcs
					puiPARArc = (unsigned int **)malloc(uiPARNombreArc * sizeof(unsigned int *));
					for (unsigned int uiBoucle = 0; uiBoucle < uiPARNombreArc; uiBoucle++) {
						fFichierTXT.getline(pcLigne, 2048);
						char* pcDebut = new char[2048];//Chaine pour stocker le debut de l'arc
						char* pcFin = new char[2048];//Chaine pour stocker la fin de l'arc
						int iIndiceDebut = 0;//Indice pour acces a la chaine pcDebut
						int iIndiceFin = 0;//Indice pour acces a la chaine pcFin

						int iSwitchDebutFin = 0;//Indicateur pour signaler quoi stocker
						//on initialise un tableau de 2 entier, le premier correspond au début et le deuxième à la fin
						puiPARArc[uiBoucle] = (unsigned int *)malloc(2 * sizeof(unsigned int));

						//Acces a la ligne caractères par caractères
						for (int iBoucleLigneFichier = 0; iBoucleLigneFichier < strlen(pcLigne); iBoucleLigneFichier++) {


							//Boucle qui prend en compte les nombres negatifs positifs et decimal

							//On stock le Debut
							if (iSwitchDebutFin == 0) {
								while ((48 <= pcLigne[iBoucleLigneFichier] && pcLigne[iBoucleLigneFichier] <= 57)
									|| pcLigne[iBoucleLigneFichier] == '.'
									|| pcLigne[iBoucleLigneFichier] == '-') {
									pcDebut[iIndiceDebut] = pcLigne[iBoucleLigneFichier];
									iBoucleLigneFichier++;
									iIndiceDebut++;
								}
							}
							//On stock la fin
							if (iSwitchDebutFin == 1) {
								while ((48 <= pcLigne[iBoucleLigneFichier] && pcLigne[iBoucleLigneFichier] <= 57)
									|| pcLigne[iBoucleLigneFichier] == '.'
									|| pcLigne[iBoucleLigneFichier] == '-') {
									pcFin[iIndiceFin] = pcLigne[iBoucleLigneFichier];
									iBoucleLigneFichier++;
									iIndiceFin++;
								}
							}


							if (pcLigne[iBoucleLigneFichier] == ',') {//On va stocker le debut et on veut reinitialiser pour la fin
								puiPARArc[uiBoucle][0] = unsigned int(atof(pcDebut));
								iSwitchDebutFin = 1;
							}

							//On est a la fin de la ligne et on veut stocker le resultat
							if (iBoucleLigneFichier == strlen(pcLigne)) {
								puiPARArc[uiBoucle][1] = unsigned int(atof(pcFin));
							}
						}
					}
				}
			}
		}
	}
}
