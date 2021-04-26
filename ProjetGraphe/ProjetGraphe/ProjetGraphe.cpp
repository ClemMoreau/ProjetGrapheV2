#include <iostream>
#include "CGraphe.h"

using namespace std;

int main()
{
	CSommet SOMSommet;
	SOMSommet.SOMModifierNumeroSommet(12);
	cout << "Num : " << SOMSommet.SOMLireNumeroSommet() << endl;
	cout << "Nb sortant : " << SOMSommet.SOMLireNombreArcSortant() << endl;
	cout << "Nb arrivant " << SOMSommet.SOMLireNombreArcArrivant() << endl << endl;

	CArc* ARCarcArrivant = new CArc(12);
	cout << "ArcArivant : " << ARCarcArrivant->ARCLireDestination() << endl;
	cout << "@ : " << &ARCarcArrivant << endl << endl;
	CArc* pARCarcPartant = new CArc(2);
	cout << "ArcArivant2 : " << pARCarcPartant->ARCLireDestination() << endl;
	cout << "@ : " << pARCarcPartant << endl << endl;

	SOMSommet.SOMAjouterArcArrivant(ARCarcArrivant);
	cout << "Num : " << SOMSommet.SOMLireNumeroSommet() << endl;
	cout << "Nb sortant : " << SOMSommet.SOMLireNombreArcSortant() << endl;
	cout << "Nb arrivant " << SOMSommet.SOMLireNombreArcArrivant() << endl << endl;

	SOMSommet.SOMAjouterArcArrivant(pARCarcPartant);
	/*cout << "Num : " << SOMSommet.SOMLireNumeroSommet() << endl;
	cout << "Nb sortant : " << SOMSommet.SOMLireNombreArcSortant() << endl;
	cout << "Nb arrivant " << SOMSommet.SOMLireNombreArcArrivant() << endl << endl;*/

	cout << "Liste arrivant : " << SOMSommet.SOMLireArcArrivant(1)->ARCLireDestination() << endl << endl;
	cout << "@ : " << SOMSommet.SOMLireArcArrivant(2) << endl << endl;

	/*SOMSommet.SOMModifierArcArrivant(1, 13);
	cout << "ArcArivant : " << SOMSommet.SOMLireArcArrivant(1)->ARCLireDestination() << endl;
	cout << "@ : " << SOMSommet.SOMLireArcArrivant(1) << endl << endl;*/

	return 0;
}
