#include <iostream>
#include "CSommet.h"
#include "CArc.h"
#include "CGraphe.h"
//#include "CArc.cpp"
//#include "CSommet.cpp"

using namespace std;

int main()
{
	CArc Arc;
	Arc.ARCSetDestination(1);
	int D = Arc.ARCGetDestination();
	cout << D << endl;;
	CSommet Sommet;
	Sommet.SOMSetNumero(3);
	int S = Sommet.SOMGetNumero();
	cout << S << endl;
	return 0;
}