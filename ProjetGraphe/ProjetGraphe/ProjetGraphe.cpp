#include <iostream>
#include "CGraphe.h"

using namespace std;

int main()
{
	// Création des arcs de test
	CArc* ARCArc1 = new CArc(1), *ARCArc2 = new CArc(2), *ARCArc3 = new CArc(3);
	// Sommet 1
	CSommet SOMSommet1(2);
	
	// Test getter/setter num sommet
	cout << "			TEST GETTER NUM" << endl ;
	cout << "num SOMSommet1 : " << SOMSommet1.SOMLireNumeroSommet() << endl << endl;
	SOMSommet1.SOMModifierNumeroSommet(32);
	cout << "			TEST SETTER NUM" << endl;
	cout << "new num SOMSommet1 : " << SOMSommet1.SOMLireNumeroSommet() << endl << endl;

	// Test setter ajout arcs arrivant
	cout << "		AJOUT ARRIVANT" << endl;
	SOMSommet1.SOMAjouterArcArrivant(ARCArc2);
		/// Test getter nb arrivant
	cout << "			TEST GETTER NB ARRIVANT" << endl;
	cout << "nb arrivant SOMSommet1 : " << SOMSommet1.SOMLireNombreArcArrivant() << endl;
		/// Test getter arrivant
	cout << "			TEST GETTER ARRIVANT" << endl;
	for (unsigned int i = 1; i <= SOMSommet1.SOMLireNombreArcArrivant(); i++)
	{
		cout << " Arrivant " << i << " : " << endl;
		cout << "	Destination : " << SOMSommet1.SOMLireArcArrivant(i)->ARCLireDestination() << endl;
	}
		/// Test modif arrivant
	cout << endl << "			TEST MODIF ARRIVANT" << endl;
	for (unsigned int i = 1; i <= SOMSommet1.SOMLireNombreArcArrivant(); i++)
	{
		cout << " Arrivant " << i << " : " << endl;
		SOMSommet1.SOMModifierArcArrivant(i, 44 + i);
		cout << "	Destination : " << SOMSommet1.SOMLireArcArrivant(i)->ARCLireDestination() << endl;
	}
		/// Test suppr arrivant
	cout << endl << "			TEST SUPPR ARRIVANT" << endl;
	SOMSommet1.SOMSupprimerArcArrivant(1);
	for (unsigned int i = 1; i <= SOMSommet1.SOMLireNombreArcArrivant(); i++)
	{
		cout << " Arrivant " << i << " : " << endl;
		cout << "	Destination : " << SOMSommet1.SOMLireArcArrivant(i)->ARCLireDestination() << endl;
	}

	// Test setter ajout arcs sortant
	cout << endl << "		AJOUT SORTANT" << endl;
	SOMSommet1.SOMAjouterArcSortant(ARCArc1);
	SOMSommet1.SOMAjouterArcSortant(ARCArc3);
		/// Test getter nb sortant
	cout << "			TEST GETTER NB SORTANT" << endl;
	cout << "nb sortant SOMSommet1 : " << SOMSommet1.SOMLireNombreArcSortant() << endl;
		/// Test setter arrivant
	cout << "			TEST GETTER SORTANT" << endl;
	for (unsigned int i = 1; i <= SOMSommet1.SOMLireNombreArcSortant(); i++)
	{
		cout << " Sortant " << i << " : " << endl;
		cout << "	Destination : " << SOMSommet1.SOMLireArcSortant(i)->ARCLireDestination() << endl;
	}
		/// Test modif sortant
	cout << endl << "			TEST MODIF SORTANT" << endl;
	for (unsigned int i = 1; i <= SOMSommet1.SOMLireNombreArcSortant(); i++)
	{
		cout << " Sortant " << i << " : " << endl;
		SOMSommet1.SOMModifierArcSortant(i, 27 + i);
		cout << "	Destination : " << SOMSommet1.SOMLireArcSortant(i)->ARCLireDestination() << endl << endl;
	}

	/// Test suppr sortant
	cout << endl << "			TEST SUPPR SORTANT" << endl;
	SOMSommet1.SOMSupprimerArcSortant(2);
	for (unsigned int i = 1; i <= SOMSommet1.SOMLireNombreArcSortant(); i++)
	{
		cout << " Sortant " << i << " : " << endl;
		cout << "	Destination : " << SOMSommet1.SOMLireArcSortant(i)->ARCLireDestination() << endl;
	}

	
	// Test copie
	cout << endl << "			TEST SUPPR COPIE" << endl;
	CSommet SOMSommetCopie;

	SOMSommetCopie = SOMSommet1;

	cout << "FIN";
	cout << " FIN";
	cout << " FIN";

	return 0;
}
