#include <iostream>
#include "CSommet.h"
#include "CArc.h"
#include "CGraphe.h"
//#include "CGraphe.cpp"
//#include "CArc.cpp"
//#include "CSommet.cpp"
#include "CParser.h"
//#include "CParser.cpp"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2) {
		cout << "Besoin d'arguments(Le nom du fichier)" << endl;
		return 1;
	}
	CParser Parser(argv[1]);
	Parser.PARLecture();
	CGraphe Graphe(Parser);
	Graphe.GRAAffiche();
	CGraphe Inverse(Graphe);
	Inverse.GRAAffiche();



	//Test ARC//
	//Test constructeur
	/*CArc Arc;
	//Test set
	Arc.ARCSetDestination(1);
	//Test get
	int D=Arc.ARCGetDestination();
	//test constructeur de recopie
	CArc Arc2(Arc);
	int D2=Arc.ARCGetDestination();
	//Test doperateur ==
	if(Arc==Arc2) cout << "Ils sont egales" << endl;
	//Test affichage
	Arc.ARCAfficher();
	Arc2.ARCAfficher();

	cout << D << D2 << endl;

  //Test Sommet//
	CSommet Sommet;
	Sommet.SOMSetNumero(3);
	CArc** listearcarrivant=Sommet.SOMGetArcArrivant();
	CArc** listearcpartant=Sommet.SOMGetArcPartant();
	CSommet Sommet2;
	Sommet2.SOMSetNumero(2);
	Sommet2.SOMSetArcArrivant(listearcarrivant);
	Sommet2.SOMSetArcPartant(listearcpartant);
	Sommet2.SOMAjouterArcPartant(2);
	Sommet2.SOMAjouterArcPartant(3);
	Sommet2.SOMAjouterArcArrivant(4);
	CSommet Sommet3(Sommet2);


	Sommet2.SOMAffichage();
	Sommet3.SOMAffichage();
	Sommet.SOMAffichage();*/

	/*cout<< "Nombre sommets:"<<Parser.PARGetNombreSommet() << endl;
	cout<< "Nombre arcs:"<<Parser.PARGetNombreArc() << endl;
	for(int i=0;i<Parser.PARGetNombreSommet();i++){
	  cout << "Sommet:"<<Parser.PARGetSommet()[i] << endl;
	}
	for(int i=0;i<Parser.PARGetNombreArc();i++){
	  cout <<"debut:"<<Parser.PARGetArc()[i][0] <<" fin:"<< Parser.PARGetArc()[i][1] << endl;
	}*/

	return 0;
}