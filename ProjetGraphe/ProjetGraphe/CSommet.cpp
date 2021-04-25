#include "CSommet.h"

CSommet::CSommet()
{
	SOMModifierNumeroSommet(0);
	ppARCSOMArcArrivant = NULL;
	ppARCSOMArcSortant = NULL;
}

CSommet::CSommet(CSommet& SOMSommet)
{

}

CSommet::~CSommet()
{
	SOMModifierNumeroSommet(0);

	int NbArc = SOMLireNombreArcArrivant();
	for (int iBoucle = 0; iBoucle < SOMLireNombreArcArrivant(); iBoucle++) //vérifier fuite (tester si commencer à 1 mieux)
	{
		delete[] * (ppARCSOMArcArrivant + iBoucle);
	}
	delete[] ppARCSOMArcArrivant;

	NbArc = SOMLireNombreArcSortant();
	for (int iBoucle = 0; iBoucle < SOMLireNombreArcSortant(); iBoucle++) //vérifier fuite (tester si commencer à 1 mieux)
	{
		delete[] * (ppARCSOMArcSortant + iBoucle);
	}
	delete[] ppARCSOMArcSortant;
}

unsigned int CSommet::SOMLireNumeroSommet()
{
	return uiSOMNumero;
}

CArc* CSommet::SOMLireArcArrivant(int iIndice)
{
	return *(ppARCSOMArcArrivant + iIndice);
}

CArc* CSommet::SOMLireArcSortant(int iIndice)
{
	return *(ppARCSOMArcSortant + iIndice);
}

void CSommet::SOMModifierNumeroSommet(int iNumero)
{
	if (iNumero < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(numero_negatif);
		EXCLevee.EXCmodifier_message("Numero sommet negatif !");
		throw(EXCLevee);
	}
	uiSOMNumero = iNumero;
}

void CSommet::SOMAjouterArcArrivant(CArc* pARCArc) 
{
	ppARCSOMArcArrivant = (CArc**) realloc(ppARCSOMArcArrivant, SOMLireNombreArcArrivant() + 1);
}

void CSommet::SOMModifierArcArrivant(int iIndice, int iDestination)
{

}

void CSommet::SOMSupprimerArcArrivant(int iIndice)
{

}

void CSommet::SOMAjouterArcSortant(CArc* pARCArc)
{

}

void CSommet::SOMModifierArcSortant(int iIndice, int iDestination)
{

}

void CSommet::SOMSupprimerArcSortant(int iIndice)
{

}

int CSommet::SOMLireNombreArcArrivant()
{
	int iCompteurArcs = 0;

	for (int iBoucle = 0; ppARCSOMArcArrivant[iBoucle] != NULL; iBoucle++)
	{
		iCompteurArcs++;
	}
	return iCompteurArcs;
}

int CSommet::SOMLireNombreArcSortant()
{
	int iCompteurArcs = 0;

	for (int iBoucle = 0; ppARCSOMArcSortant[iBoucle] != NULL; iBoucle++)
	{
		iCompteurArcs++;
	}
	return iCompteurArcs;
}

void CSommet::SOMInverserArrivantPartant()
{

}