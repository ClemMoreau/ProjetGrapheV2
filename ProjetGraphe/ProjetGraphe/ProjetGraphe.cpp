#include <iostream>
#include "CGraphe.h"

using namespace std;

int main()
{
	CGraphe GRAgraphe;
	CSommet SOMSommet1(1), SOMSommet2(2), SOMSommet3(3);

	GRAgraphe.GRAAjouterSommet(SOMSommet1);
	GRAgraphe.GRAAjouterSommet(SOMSommet2);
	GRAgraphe.GRAAjouterSommet(SOMSommet3);

	GRAgraphe.GRAAjouterArc(1, 3);
	GRAgraphe.GRAAjouterArc(1, 2);
	GRAgraphe.GRAAjouterArc(2, 3);
	GRAgraphe.GRAAjouterArc(3, 1);

	cout << "GRAgraphe" << endl;
	GRAgraphe.GRAAfficherGraphe();

	GRAgraphe.GRASupprimerArc(3, 1);
	GRAgraphe.GRAModifierArc(2, 3, 3, 2);

	cout << "GRAgraphe" << endl;
	GRAgraphe.GRAAfficherGraphe();

	return 0;
}
