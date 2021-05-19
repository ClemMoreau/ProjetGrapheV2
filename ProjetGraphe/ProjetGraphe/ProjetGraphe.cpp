#include <iostream>
#include "CFichier.h"

using namespace std;

int main()
{
	CGraphe GRAgraphe;
	CSommet SOMSommet1(1), SOMSommet2(2), SOMSommet3(3), SOMSommet4(4);

	GRAgraphe.GRAAjouterSommet(SOMSommet1);
	GRAgraphe.GRAAjouterSommet(SOMSommet2);
	GRAgraphe.GRAAjouterSommet(SOMSommet3);
	GRAgraphe.GRAAjouterSommet(SOMSommet4);

	GRAgraphe.GRAAfficherGraphe();
	cout << "*****************************************************" << endl << endl;
	cout << "Ajout 1 -> 2" << endl;
	GRAgraphe.GRAAjouterArc(1, 2);
	GRAgraphe.GRAAfficherGraphe();
	cout << "*****************************************************" << endl << endl;
	cout << "Ajout 3 -> 2" << endl;
	GRAgraphe.GRAAjouterArc(3, 2);
	GRAgraphe.GRAAfficherGraphe();
	cout << "*****************************************************" << endl << endl;
	cout << "Ajout 1 -> 3" << endl;
	GRAgraphe.GRAAjouterArc(1, 3);
	GRAgraphe.GRAAfficherGraphe();
	cout << "*****************************************************" << endl << endl;
	cout << "Ajout 3 -> 4" << endl;
	GRAgraphe.GRAAjouterArc(3, 4);
	GRAgraphe.GRAAfficherGraphe();
	cout << "*****************************************************" << endl << endl;
	cout << "Ajout 4 -> 3" << endl;
	GRAgraphe.GRAAjouterArc(4, 3);
	GRAgraphe.GRAAfficherGraphe();
	cout << "*****************************************************" << endl << endl;

	GRAgraphe.GRAAfficherGraphe();

	return 0;
}
