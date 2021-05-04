#include <iostream>
#include "CGraphe.h"

using namespace std;

int main()
{
	bool b = false;
	int i;
	for ( i = 0; i < 4 || b == false; i++)
	{
		if (i == 2)
		{
			b = true;
		}
	}







	CGraphe GRAgraphe;

	CSommet SOMSommet(1);

	CArc* ARCarc1 = new CArc(1);
	SOMSommet.SOMAjouterArcArrivant(ARCarc1);

	GRAgraphe.GRAAjouterSommet(SOMSommet);

	return 0;
}
