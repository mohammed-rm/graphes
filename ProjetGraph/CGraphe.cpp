#include "CGraphe.h"
#include <iostream>

CGraphe::CGraphe(void) {
	TGRASommet = (CSommet*)malloc(sizeof(CSommet));
	uiGRANbrSommet = 0;
}

CGraphe::CGraphe(CGraphe & GRAArg) {
	uiGRANbrSommet = GRAArg.uiGRANbrSommet;
	TGRASommet = (CSommet*)malloc(uiGRANbrSommet * sizeof(CSommet));
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbrSommet; uiBoucle++) {
		TGRASommet[uiBoucle] = GRAArg.TGRASommet[uiBoucle];
	}
}

CGraphe::CGraphe(CParser & PARArg) {
	if (PARArg.PARGetArc() == nullptr) {
		CException EXCParserFailed;
		EXCParserFailed.EXCModifier_valeur(EXC_Failed_Parser);
		throw(EXCParserFailed);
	}

	//On créer les sommets du graphs
	uiGRANbrSommet = 0;
	TGRASommet = (CSommet*)malloc(PARArg.PARGetNombreSommet() * sizeof(CSommet));
	for (unsigned int uiBoucle = 0; uiBoucle < PARArg.PARGetNombreSommet(); uiBoucle++) {
		//Numero du sommet
		unsigned int uiNumero = PARArg.PARGetSommet()[uiBoucle];
		//Creation du sommet
		CSommet SOMTemporaire(uiNumero);
		//Insertion du sommet au graphe
		GRAAddSommet(SOMTemporaire);
	}

	//On ajoute les arcs
	for (unsigned int uiBoucle = 0; uiBoucle < PARArg.PARGetNombreArc(); uiBoucle++) {
		unsigned int uiNumeroSommetDebut = PARArg.PARGetArc()[uiBoucle][0];
		unsigned int uiNumeroSommetFin = PARArg.PARGetArc()[uiBoucle][1];
		int uiPositionSommetDebut = GRAGetIndexSom(uiNumeroSommetDebut);
		int uiPositionSommeFin = GRAGetIndexSom(uiNumeroSommetFin);
		if (uiPositionSommeFin == -1 || uiPositionSommetDebut == -1) {
			CException EXCParserFailed;
			EXCParserFailed.EXCModifier_valeur(EXC_Failed_Parser);
			throw(EXCParserFailed);
		}
		else {
			//On ajoute l'arc correspondant au Sommet debut dans les arc arrivant du Sommet Fin
			TGRASommet[uiPositionSommeFin].SOMAjouterArcArrivant(uiNumeroSommetDebut);

			//On ajoute l'arc correspondant au Sommet Fin dans les arc partant du Sommet Début
			TGRASommet[uiPositionSommetDebut].SOMAjouterArcPartant(uiNumeroSommetFin);
		}
	}
}

CGraphe::~CGraphe() {
	delete(TGRASommet);
}

unsigned int CGraphe::GRAGetIndexSom(unsigned int uiNumeroSom) {
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbrSommet; uiBoucle++) {
		if (TGRASommet[uiBoucle].SOMGetNumero() == uiNumeroSom) {
			return uiBoucle;
		}
	}
	return -1;
}

CGraphe & CGraphe::operator=(CGraphe & GRAArg) {
	if (TGRASommet)
	{
		delete(TGRASommet);
	}
	uiGRANbrSommet = GRAArg.uiGRANbrSommet;
	TGRASommet = (CSommet*)malloc(uiGRANbrSommet * sizeof(CSommet));
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbrSommet; uiBoucle++) {
		TGRASommet[uiBoucle] = GRAArg.TGRASommet[uiBoucle];
	}
	return *this;
}

unsigned int CGraphe::GRAGetNbSommet() {
	return uiGRANbrSommet;
}

void CGraphe::GRASetSommet(CSommet* pSOMArg, unsigned int uiNombreSommet) {
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreSommet; uiBoucle++) {
		TGRASommet[uiBoucle].SOMSetNumero(pSOMArg[uiBoucle].SOMGetNumero());
		TGRASommet[uiBoucle].SOMSetTaillePartant(pSOMArg[uiBoucle].SOMGetTaillePartant());
		TGRASommet[uiBoucle].SOMSetTailleArrivant(pSOMArg[uiBoucle].SOMGetTailleArrivant());
		TGRASommet[uiBoucle].SOMSetArcPartant(pSOMArg[uiBoucle].SOMGetArcPartant());
		TGRASommet[uiBoucle].SOMSetArcArrivant(pSOMArg[uiBoucle].SOMGetArcArrivant());
	}
}

void CGraphe::GRAAddSommet(CSommet & pSOMArg) {
	TGRASommet[uiGRANbrSommet] = pSOMArg;
	uiGRANbrSommet++;
}

void CGraphe::GRASupprimerSommet(unsigned int uiNumero) {
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbrSommet; uiBoucle++) {
		if (TGRASommet[uiBoucle].SOMGetNumero() == uiNumero) {
			for (unsigned int uiBoucle2 = uiBoucle; uiBoucle2 < uiGRANbrSommet - 1; uiBoucle2++) {
				TGRASommet[uiBoucle2] = TGRASommet[uiBoucle2 + 1];
			}
		}
	}
	uiGRANbrSommet--;
}

void CGraphe::GRAAffiche() {
	cout << "Nombre de sommets dans le Graphe : " << uiGRANbrSommet << endl;
	cout << "Voici le graphe : " << std::endl;
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbrSommet; uiBoucle++) {
		TGRASommet[uiBoucle].SOMAffichage();
	}
}
