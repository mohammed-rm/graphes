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

	for (unsigned int iBoucleA = 0; iBoucleA <= uiSOMTailleArrivant; iBoucleA++) {
		pSOMArcArrivant[iBoucleA] = SOMArg.pSOMArcArrivant[iBoucleA];
	}

	for (unsigned int iBoucleP = 0; iBoucleP <= uiSOMTaillePartant; iBoucleP++) {
		pSOMArcPartant[iBoucleP] = SOMArg.pSOMArcPartant[iBoucleP];
	}

}

CSommet::~CSommet() {}

unsigned int CSommet::SOMGetNumero() {
	return uiSOMNumeroS;
}

void CSommet::SOMSetNumero(unsigned int uiSOMArg) {
	uiSOMNumeroS = uiSOMArg;
}

CArc** CSommet::SOMGetArcArrivant() {
	return pSOMArcArrivant;
}

void CSommet::SOMSetArcArrivant(CArc** pSOMArg) {
	for (unsigned int iBoucle = 0; iBoucle <= uiSOMTailleArrivant; iBoucle++) {
		pSOMArcArrivant[iBoucle] = pSOMArg[iBoucle];
	}
}

CArc** CSommet::SOMGetArcPartant() {
	return pSOMArcPartant;
}

void CSommet::SOMSetArcPartant(CArc** pSOMArg) {
	for (unsigned int iBoucle = 0; iBoucle <= uiSOMTaillePartant; iBoucle++) {
		pSOMArcArrivant[iBoucle] = pSOMArg[iBoucle];
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

void CSommet::SOMAffichage() {}
