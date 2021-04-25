#include <iostream>
#include "CGraphe.h"

using namespace std;

int main()
{
	CSommet SOMSommet;

	SOMSommet.SOMModifierNumeroSommet(12);
	cout << SOMSommet.SOMLireNombreArcArrivant() << endl;
}
