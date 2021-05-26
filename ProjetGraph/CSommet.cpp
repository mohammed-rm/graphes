#include "CSommet.h"
#include <iostream>

CSommet::CSommet() {
	uiSOMNumeroS = 0;
	uiSOMTailleArrivant = 0;
	uiSOMTaillePartant = 0;
	pSOMArcArrivant = (CArc**)malloc(sizeof(CArc*));
	pSOMArcPartant = (CArc**)malloc(sizeof(CArc*));
}

CSommet::CSommet(CSommet &SOMArg) {
	uiSOMNumeroS = SOMArg.uiSOMNumeroS;
	uiSOMTailleArrivant = SOMArg.uiSOMTailleArrivant;
	uiSOMTaillePartant = SOMArg.uiSOMTaillePartant;
	pSOMArcArrivant = (CArc**)malloc(sizeof(CArc*));
	pSOMArcPartant = (CArc**)malloc(sizeof(CArc*));

	for (int iBoucleA = 0; iBoucleA <= uiSOMTailleArrivant; iBoucleA++) {
		pSOMArcArrivant[iBoucleA] = SOMArg.pSOMArcArrivant[iBoucleA];
	}

	for (int iBoucleP = 0; iBoucleP <= uiSOMTaillePartant; iBoucleP++) {
		pSOMArcPartant[iBoucleP] = SOMArg.pSOMArcPartant[iBoucleP];
	}

}

CSommet::CSommet(unsigned int uiNumSom) {
	uiSOMNumeroS = uiNumSom;
	uiSOMTailleArrivant = 0;
	uiSOMTaillePartant = 0;
	pSOMArcArrivant = (CArc**)malloc(sizeof(CArc*));
	pSOMArcPartant = (CArc**)malloc(sizeof(CArc*));
}

CSommet::~CSommet() {

}

unsigned int CSommet::SOMGetNumero() {
	return uiSOMNumeroS;
}

unsigned int CSommet::SOMGetTailleArrivant() {
	return uiSOMTailleArrivant;
}

void CSommet::SOMSetTailleArrivant(unsigned int uiSOMArg) {
	uiSOMTailleArrivant = uiSOMArg;
}


unsigned int CSommet::SOMGetTaillePartant() {
	return uiSOMTaillePartant;
}

void CSommet::SOMSetTaillePartant(unsigned int uiSOMArg) {
	uiSOMTaillePartant = uiSOMArg;
}

void CSommet::SOMSetNumero(unsigned int uiSOMArg) {
	uiSOMNumeroS = uiSOMArg;
}

CArc** CSommet::SOMGetArcArrivant() {
	return pSOMArcArrivant;
}

void CSommet::SOMSetArcArrivant(CArc** pSOMArg) {
	for (int iBoucle = 0; iBoucle < uiSOMTailleArrivant; iBoucle++) {
		pSOMArcArrivant[iBoucle]->ARCSetDestination(pSOMArg[iBoucle]->ARCGetDestination());
	}
}

CArc** CSommet::SOMGetArcPartant() {
	return pSOMArcPartant;
}

void CSommet::SOMSetArcPartant(CArc** pSOMArg) {
	for (int iBoucle = 0; iBoucle < uiSOMTaillePartant; iBoucle++) {
		pSOMArcPartant[iBoucle]->ARCSetDestination(pSOMArg[iBoucle]->ARCGetDestination());
	}
}

void CSommet::SOMAjouterArcPartant(int iARCarg) {
	uiSOMTaillePartant++;
	pSOMArcPartant = (CArc**)realloc(pSOMArcPartant, uiSOMTaillePartant * sizeof(CArc*));
	pSOMArcPartant[uiSOMTaillePartant - 1] = new CArc();
	pSOMArcPartant[uiSOMTaillePartant - 1]->ARCSetDestination(iARCarg);
}

void CSommet::SOMSupprimerArcPartant(int ARCarg) {}

void CSommet::SOMAjouterArcArrivant(int iARCarg) {
	uiSOMTailleArrivant++;
	pSOMArcArrivant = (CArc**)realloc(pSOMArcArrivant, uiSOMTailleArrivant * sizeof(CArc*));
	pSOMArcArrivant[uiSOMTailleArrivant - 1] = new CArc();
	pSOMArcArrivant[uiSOMTailleArrivant - 1]->ARCSetDestination(iARCarg);
}

void CSommet::SOMSupprimerArcArrivant(int ARCarg) {}

void CSommet::SOMAffichage() {
	if (uiSOMTaillePartant > 0) {
		for (int iBoucle = 0; iBoucle < uiSOMTaillePartant; iBoucle++) {
			cout << uiSOMNumeroS << "--->" << pSOMArcPartant[iBoucle]->ARCGetDestination() << endl;;
		}
		/*if(uiSOMTailleArrivant>0){
		  for(int iBoucle=0;iBoucle<uiSOMTailleArrivant;iBoucle++){
		  cout << uiSOMNumeroS<< "<---"<< pSOMArcArrivant[iBoucle]->ARCGetDestination() <<endl;;
		  }
		}*/
	}
	else {
		cout << uiSOMNumeroS << endl;
	}
}
