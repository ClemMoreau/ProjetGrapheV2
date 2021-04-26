#include "CSommet.h"

CSommet::CSommet()
{
	uiSOMNbArcArrivant = uiSOMNbArcSortant = 0;
	ppARCSOMArcArrivant = NULL;
	ppARCSOMArcSortant = NULL;
}

CSommet::CSommet(CSommet& SOMSommet)
{
	uiSOMNumero = SOMSommet.SOMLireNumeroSommet();

	uiSOMNbArcArrivant = SOMSommet.SOMLireNombreArcArrivant();
	ppARCSOMArcArrivant = (CArc**) realloc(ppARCSOMArcArrivant, sizeof(CArc*) * uiSOMNbArcArrivant);
	for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcArrivant; iBoucle++)
	{
		*(ppARCSOMArcArrivant + iBoucle) = new CArc(*SOMSommet.SOMLireArcArrivant(iBoucle + 1));
	}

	uiSOMNbArcSortant = SOMSommet.SOMLireNombreArcSortant();
	ppARCSOMArcSortant = (CArc**) realloc(ppARCSOMArcSortant, sizeof(CArc*) * uiSOMNbArcSortant);
	for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcSortant; iBoucle++)
	{
		*(ppARCSOMArcSortant + iBoucle) = new CArc(*SOMSommet.SOMLireArcSortant(iBoucle + 1));
	}
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
	if (!pARCArc)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(argument_null);
		EXCLevee.EXCmodifier_message("Le paramètre à rajouter dans la liste est null !");
		throw(EXCLevee);
	}
	/*un arc arrivant à forcément dans sa destination le sommet courant?*/
	/*if (pARCArc->ARCLireDestination() != uiSOMNumero)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_incohérente);
		EXCLevee.EXCmodifier_message("Un arc arrivant doit avoir pour destination le sommet courant !");
		throw(EXCLevee);
	}*/
	ppARCSOMArcArrivant = (CArc**) realloc(ppARCSOMArcArrivant, sizeof(CArc*) * (uiSOMNbArcArrivant + 1));
	*(ppARCSOMArcArrivant + uiSOMNbArcArrivant) = pARCArc;
	uiSOMNbArcArrivant++;
}

void CSommet::SOMModifierArcArrivant(int iIndice, int iDestination)
{
	if (iIndice < 0 || iIndice > int(uiSOMNbArcArrivant))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
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
	if (iIndice < 0 || iIndice > int(uiSOMNbArcArrivant))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	//on décale le tableau
	for (unsigned int iBoucle = iIndice; iBoucle < uiSOMNbArcArrivant - 1; iBoucle++)
	{
		*(ppARCSOMArcArrivant + iBoucle) = *(ppARCSOMArcArrivant + iBoucle + 1);
	}
	//on réallou
	ppARCSOMArcArrivant = (CArc**)realloc(ppARCSOMArcArrivant, sizeof(CArc*) * (uiSOMNbArcArrivant - 1));
}

void CSommet::SOMAjouterArcSortant(CArc* pARCArc)
{
	if (!pARCArc)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(argument_null);
		EXCLevee.EXCmodifier_message("Le paramètre à rajouter dans la liste est null !");
		throw(EXCLevee);
	}
	ppARCSOMArcSortant = (CArc**)realloc(ppARCSOMArcSortant, sizeof(CArc*) * (uiSOMNbArcSortant + 1));
	*(ppARCSOMArcSortant + uiSOMNbArcSortant) = pARCArc;
	uiSOMNbArcSortant++;
}

void CSommet::SOMModifierArcSortant(int iIndice, int iDestination)
{
	if (0 > iIndice || iIndice > int(uiSOMNbArcSortant))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	if (0 > iDestination)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_negatif);
		EXCLevee.EXCmodifier_message("Destination negative !");
		throw(EXCLevee);
	}

	SOMLireArcSortant(iIndice)->ARCModifierDestination(iDestination);
}

void CSommet::SOMSupprimerArcSortant(int iIndice)
{
	//on décale le tableau
	for (unsigned int iBoucle = iIndice; iBoucle < uiSOMNbArcSortant - 1; iBoucle++)
	{
		*(ppARCSOMArcSortant + iBoucle) = *(ppARCSOMArcSortant + iBoucle + 1);
	}
	//on réallou
	ppARCSOMArcSortant = (CArc**)realloc(ppARCSOMArcSortant, sizeof(CArc*) * (uiSOMNbArcSortant - 1));
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