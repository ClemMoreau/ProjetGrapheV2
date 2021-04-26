#include "CSommet.h"

CSommet::CSommet()
{
	uiSOMNbArcArrivant = uiSOMNbArcSortant = 0;
	ppARCSOMArcArrivant = (CArc**)malloc(uiSOMNbArcArrivant * sizeof(CArc*));
	ppARCSOMArcSortant = (CArc**)malloc(uiSOMNbArcSortant * sizeof(CArc*));
}

CSommet::CSommet(CSommet& SOMSommet)
{

}

CSommet::~CSommet()
{
	/*à modifier passer par suppr arc qui appel destructeur*/
	for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcArrivant; iBoucle++) //vérifier fuite (tester si commencer à 1 mieux)
	{
		free(*(ppARCSOMArcArrivant + iBoucle));
	}
	//free(ppARCSOMArcArrivant); ça fais planter wtf

	for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcSortant; iBoucle++) //vérifier fuite (tester si commencer à 1 mieux)
	{
		free(*(ppARCSOMArcSortant + iBoucle));
	}
	//free(ppARCSOMArcSortant);
}

unsigned int CSommet::SOMLireNumeroSommet()
{
	return uiSOMNumero;
}

CArc* CSommet::SOMLireArcArrivant(int iIndice)
{
	return *(ppARCSOMArcArrivant + iIndice - 1);
}

CArc* CSommet::SOMLireArcSortant(int iIndice)
{
	return *(ppARCSOMArcSortant + iIndice - 1);
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
	/*un arc arrivant à forcément dans sa destination le sommet courant?*/
	//if (pARCArc->ARCLireDestination() != uiSOMNumero)
	ppARCSOMArcArrivant = (CArc**) realloc(ppARCSOMArcArrivant, uiSOMNbArcArrivant + 1);
	*(ppARCSOMArcArrivant + uiSOMNbArcArrivant) = pARCArc;
	uiSOMNbArcArrivant++;
}

void CSommet::SOMModifierArcArrivant(int iIndice, int iDestination)
{
	if (0 > iIndice || iIndice > uiSOMNbArcArrivant)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		EXCLevee.EXCmodifier_message("Dimension hors du tableau !");
		throw(EXCLevee);
	}

	if (0 > iDestination)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_negatif);
		EXCLevee.EXCmodifier_message("Destination negative !");
		throw(EXCLevee);
	}

	SOMLireArcArrivant(iIndice)->ARCModifierDestination(iDestination); //voir pour modifier
}

void CSommet::SOMSupprimerArcArrivant(int iIndice)
{
	
}

void CSommet::SOMAjouterArcSortant(CArc* pARCArc)
{
	ppARCSOMArcSortant = (CArc**)realloc(ppARCSOMArcSortant, uiSOMNbArcSortant + 1);
	*(ppARCSOMArcSortant + uiSOMNbArcSortant) = pARCArc;
	uiSOMNbArcSortant++;
}

void CSommet::SOMModifierArcSortant(int iIndice, int iDestination)
{

}

void CSommet::SOMSupprimerArcSortant(int iIndice)
{

}

int CSommet::SOMLireNombreArcArrivant()
{
	return uiSOMNbArcArrivant;
}

int CSommet::SOMLireNombreArcSortant()
{
	return uiSOMNbArcSortant;
}

void CSommet::SOMInverserArrivantPartant()
{

}