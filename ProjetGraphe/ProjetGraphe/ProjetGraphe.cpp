#include <iostream>
#include "CGraphe.h"

using namespace std;

int main()
{
	//Création sommet 
	CSommet SOMSommet;
	SOMSommet.SOMModifierNumeroSommet(12);
	cout << "Num : " << SOMSommet.SOMLireNumeroSommet() << endl;
	cout << "Nb sortant : " << SOMSommet.SOMLireNombreArcSortant() << endl;
	cout << "Nb arrivant " << SOMSommet.SOMLireNombreArcArrivant() << endl << endl;

	//Création arc arrivants
	CArc* ARCarcArrivant = new CArc(12);
	cout << "ArcArivant : " << ARCarcArrivant->ARCLireDestination() << endl;
	cout << "@ : " << ARCarcArrivant << endl << endl;
	CArc* pARCarcPartant = new CArc(12);
	cout << "ArcArivant2 : " << pARCarcPartant->ARCLireDestination() << endl;
	cout << "@ : " << pARCarcPartant << endl << endl;
	CArc* ARCarcArrivant3 = new CArc(12);
	cout << "ArcArivant : " << ARCarcArrivant3->ARCLireDestination() << endl;
	cout << "@ : " << ARCarcArrivant3 << endl << endl;
	CArc* ARCarcArrivant4 = new CArc(12);
	cout << "ArcArivant : " << ARCarcArrivant4->ARCLireDestination() << endl;
	cout << "@ : " << ARCarcArrivant4 << endl << endl;
	CArc* ARCarcArrivant5 = new CArc(12);
	cout << "ArcArivant : " << ARCarcArrivant5->ARCLireDestination() << endl;
	cout << "@ : " << ARCarcArrivant5 << endl << endl;
	CArc* ARCarcArrivant6 = new CArc(12);
	cout << "ArcArivant : " << ARCarcArrivant6->ARCLireDestination() << endl;
	cout << "@ : " << ARCarcArrivant6 << endl << endl;

	//Ajout arcs
	SOMSommet.SOMAjouterArcArrivant(ARCarcArrivant);
	cout << "Num : " << SOMSommet.SOMLireNumeroSommet() << endl;
	cout << "Nb sortant : " << SOMSommet.SOMLireNombreArcSortant() << endl;
	cout << "Nb arrivant " << SOMSommet.SOMLireNombreArcArrivant() << endl << endl;
	SOMSommet.SOMAjouterArcArrivant(pARCarcPartant);
	cout << "Num : " << SOMSommet.SOMLireNumeroSommet() << endl;
	cout << "Nb sortant : " << SOMSommet.SOMLireNombreArcSortant() << endl;
	cout << "Nb arrivant " << SOMSommet.SOMLireNombreArcArrivant() << endl << endl;
	SOMSommet.SOMAjouterArcArrivant(ARCarcArrivant3);
	SOMSommet.SOMAjouterArcArrivant(ARCarcArrivant4);
	SOMSommet.SOMAjouterArcArrivant(ARCarcArrivant5);
	SOMSommet.SOMAjouterArcArrivant(ARCarcArrivant6);
	
	//test ajout
	for (int i = 1; i <= SOMSommet.SOMLireNombreArcArrivant(); i++)
	{
		cout << "Liste arrivant " << i << " : " << SOMSommet.SOMLireArcArrivant(i)->ARCLireDestination() << endl;
		cout << "@ : " << SOMSommet.SOMLireArcArrivant(i) << endl << endl;
	}


	//test sortant : création arcs 
	CArc* pARCarcsortant1 = new CArc(1);
	cout << "ArcArivant : " << pARCarcsortant1->ARCLireDestination() << endl;
	cout << "@ : " << pARCarcsortant1 << endl << endl;
	CArc* pARCarcsortant2 = new CArc(2);
	cout << "ArcArivant : " << pARCarcsortant2->ARCLireDestination() << endl;
	cout << "@ : " << pARCarcsortant2 << endl << endl;
	CArc* pARCarcsortant3 = new CArc(3);
	cout << "ArcArivant : " << pARCarcsortant3->ARCLireDestination() << endl;
	cout << "@ : " << pARCarcsortant3 << endl << endl;
	CArc* pARCarcsortant4 = new CArc(4);
	cout << "ArcArivant : " << pARCarcsortant4->ARCLireDestination() << endl;
	cout << "@ : " << pARCarcsortant4 << endl << endl;
	CArc* pARCarcsortant5 = new CArc(5);
	cout << "ArcArivant : " << pARCarcsortant5->ARCLireDestination() << endl;
	cout << "@ : " << pARCarcsortant5 << endl << endl;

	//ajout
	SOMSommet.SOMAjouterArcSortant(pARCarcsortant1);
	SOMSommet.SOMAjouterArcSortant(pARCarcsortant2);
	SOMSommet.SOMAjouterArcSortant(pARCarcsortant3);
	SOMSommet.SOMAjouterArcSortant(pARCarcsortant4);
	SOMSommet.SOMAjouterArcSortant(pARCarcsortant5);

	cout << "Num : " << SOMSommet.SOMLireNumeroSommet() << endl;
	cout << "Nb sortant : " << SOMSommet.SOMLireNombreArcSortant() << endl;
	cout << "Nb arrivant " << SOMSommet.SOMLireNombreArcArrivant() << endl << endl;
	//test ajout
	for (int i = 1; i <= SOMSommet.SOMLireNombreArcSortant(); i++)
	{
		cout << "Liste sortant " << i << " : " << SOMSommet.SOMLireArcSortant(i)->ARCLireDestination() << endl;
		cout << "@ : " << SOMSommet.SOMLireArcSortant(i) << endl << endl;
	}

	return 0;
}
