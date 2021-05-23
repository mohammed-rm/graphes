#ifndef CEXCPT
#define CEXCPT 2

#define EXC_erreur_valeur_existante 1
#define EXC_open_file_failed 2
#define EXC_too_argument 3

class CException {
private:
	unsigned int uiEXCvaleur;
public:
	CException(void) {};
	/*
	Entree : Aucune
	Sortie : Renvoie le code d'erreur associe a l'exception
	Pre-condition : Aucune
	Post-condition : Aucune
	*/
	unsigned int EXCLireValeur(void) { return uiEXCvaleur; };
	/*
	Entree : Entier naturel correspondant au code d'erreur
	Sortie : Aucune
	Post-condition : Aucune
	Pre-condition : Aucune
	*/
	void EXCModifier_valeur(unsigned int uiCodeErreur) { uiEXCvaleur = uiCodeErreur; };
};

#endif