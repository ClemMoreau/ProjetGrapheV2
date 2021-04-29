#include "CSommet.h"

/*********************************************************
Constructeur par défaut de la classe CSommet
*********************************************************
Entrée: (rien)
Nécessite: (rien)
Sortie: (rien)
Entraîne :	(l'objet est initlialisé avec 
uiSOMNbArcArrivant = uiSOMNbArcSortant = 0 et
ppARCSOMArcArrivant = ppARCSOMArcSortant = NULL) 
*********************************************************/
CSommet::CSommet()
{
	// Initialisation des attributs
	uiSOMNbArcArrivant = uiSOMNbArcSortant = 0;
	ppARCSOMArcArrivant = NULL;
	ppARCSOMArcSortant = NULL;
}

/*********************************************************
Constructeur de recopie de la classe CSommet
*********************************************************
Entrée: CSommet& SOMSommet : le sommet à recopier
Nécessite: (rien)
Sortie: (rien)
Entraîne :	(l'objet est initlialisé avec les attributs 
de SOMSommet passé en paramètre) ou
(Exception echec_malloc levé)
*********************************************************/
CSommet::CSommet(CSommet& SOMSommet)
{
	// Recopie du numéro du sommet
	uiSOMNumero = SOMSommet.SOMLireNumeroSommet();

	// Recopie de la liste des arcs arrivants au sommet
	uiSOMNbArcArrivant = SOMSommet.SOMLireNombreArcArrivant();
	ppARCSOMArcArrivant = (CArc**) realloc(ppARCSOMArcArrivant, sizeof(CArc*) * uiSOMNbArcArrivant);
		/// Si l'allocation à réussi on copie la liste
	if (ppARCSOMArcArrivant)
	{
		for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcArrivant; iBoucle++)
		{
			*(ppARCSOMArcArrivant + iBoucle) = new CArc(*SOMSommet.SOMLireArcArrivant(iBoucle + 1));
		}
	}
		/// Sinon une exception est levé
	else
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}

	// Recopie de la liste des arcs sortants du sommet
	uiSOMNbArcSortant = SOMSommet.SOMLireNombreArcSortant();
	ppARCSOMArcSortant = (CArc**) realloc(ppARCSOMArcSortant, sizeof(CArc*) * uiSOMNbArcSortant);
		/// Si l'allocation à réussi on copie la liste
	if (ppARCSOMArcSortant)
	{
		for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcSortant; iBoucle++)
		{
			*(ppARCSOMArcSortant + iBoucle) = new CArc(*SOMSommet.SOMLireArcSortant(iBoucle + 1));
		}
	}
		/// Sinon une exception est levé
	else
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
}	

/*********************************************************
Constructeur de la classe CSommet
prenant en paramètre un int
*********************************************************
Entrée: int iNumeroSommet : le numero du sommet à créer
Nécessite: (rien)
Sortie: (rien)
Entraîne :	(l'objet est initlialisé avec uiSOMNumero = iNumeroSommet)
*********************************************************/
CSommet::CSommet(int iNumeroSommet)
{
	uiSOMNumero = iNumeroSommet;
	uiSOMNbArcArrivant = uiSOMNbArcSortant = 0;
	ppARCSOMArcArrivant = NULL;
	ppARCSOMArcSortant = NULL;
}

/*********************************************************
Destructeur de la classe CSommet
*********************************************************
Entrée: (rien)
Nécessite: (rien)
Sortie: (rien)
Entraîne : (l'espace mémoire des listes des arcs est libéré)
*********************************************************/
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

/*********************************************************
Retourne le numero du sommet
*********************************************************
Entrée: (rien)
Nécessite: (rien)
Sortie: unsigned int uiSOMNumero : le numero du sommet courant
Entraîne : (rien)
*********************************************************/
unsigned int CSommet::SOMLireNumeroSommet()
{
	return uiSOMNumero;
}

/*********************************************************
Retourne le nombre d'arc arrivant du sommet
*********************************************************
Entrée: (rien)
Nécessite: (rien)
Sortie: int uiSOMNbArcArrivant : le nombre d'arc arrivant au sommet
Entraîne : (rien)
*********************************************************/
int CSommet::SOMLireNombreArcArrivant()
{
	return uiSOMNbArcArrivant;
}


/*********************************************************
Retourne l'arc à l'indice iIndice
du tableau des arcs arrivants	
*********************************************************
Entrée: int iIndice : l'indice de l'arc à retourner
Nécessite: (rien) 
Sortie: CArc* : l'arc à l'indice iIndice de la liste des arcs arrivants
Entraîne : (CArcs* en sortie) ou (Exception indice_incorrecte levée)
*********************************************************/
CArc* CSommet::SOMLireArcArrivant(int iIndice)
{
	// Test indice compris dans les bornes du tableau
	if (iIndice < 0 || iIndice > SOMLireNombreArcArrivant())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}
	return *(ppARCSOMArcArrivant + iIndice - 1);
}

/*********************************************************
Retourne le nombre d'arc sortant du sommet
*********************************************************
Entrée: (rien)
Nécessite: (rien)
Sortie: int uiSOMNbArcSortant : le nombre d'arc sortant au sommet
Entraîne : (rien)
*********************************************************/
int CSommet::SOMLireNombreArcSortant()
{
	return uiSOMNbArcSortant;
}

/*********************************************************
Retourne l'arc à l'indice iIndice
du tableau des arcs sortants
*********************************************************
Entrée: int iIndice : l'indice de l'arc à retourner
Nécessite: (rien)
Sortie: CArc* : l'arc à l'indice iIndice de la liste des arcs sortants
Entraîne : (CArcs* en sortie) ou (Exception indice_incorrecte levée)
*********************************************************/
CArc* CSommet::SOMLireArcSortant(int iIndice)
{
	// Test indice compris dans les bornes du tableau
	if (iIndice < 0 || iIndice > SOMLireNombreArcSortant())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}
	return *(ppARCSOMArcSortant + iIndice - 1);
}

/*********************************************************
Modifie le numéro du sommet
*********************************************************
Entrée: int iNumero : le nouveau numéro de sommet
Nécessite: (rien)
Sortie: (rien)
Entraîne : (this.uiSOMNumero = iNumero) ou (Exception numero_negatif levée)
*********************************************************/
void CSommet::SOMModifierNumeroSommet(int iNumero)
{
	// Test valeur positive
	if (iNumero < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(numero_negatif);
		EXCLevee.EXCmodifier_message("Numero sommet negatif !");
		throw(EXCLevee);
	}
	uiSOMNumero = iNumero;
}

/*********************************************************
Ajoute un arc dans la liste des arcs arrivants
*********************************************************
Entrée: CArc* pARCArc : un pointeur vers l'arc à ajouter
Nécessite: (rien)
Sortie: (rien)
Entraîne : 
(pARCArc à été ajouter en fin de la liste) et (le tableau a été réallouer) ou
(Exception argument_null levée) ou 
(Exception echec_malloc levée)
*********************************************************/
void CSommet::SOMAjouterArcArrivant(CArc* pARCArc) 
{
	// Test paramètre non null
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
		/// Si l'allocation à réussi on rajoute l'arc
	if (ppARCSOMArcArrivant)
	{
		*(ppARCSOMArcArrivant + uiSOMNbArcArrivant) = pARCArc;
		uiSOMNbArcArrivant++;
	}
		/// Sinon une exception est levé
	else
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
}

/*********************************************************
Modifie l'arc à l'indice iIndice dans la liste des arcs arrivants
*********************************************************
Entrée: int iIndice : l'indice de l'arc à modifier
	    int iDestination : la nouvelle destination de cet arc
Nécessite: (rien)
Sortie: (rien)
Entraîne : (l'arc à l'indice iIndice à pour nouvelle destination iDestination) ou
(Exception indice_incorrecte levée) ou
(Exception destination_negatif levée)
*********************************************************/
void CSommet::SOMModifierArcArrivant(int iIndice, int iDestination)
{
	// Test indice dans la liste
	if (iIndice < 0 || iIndice > int(uiSOMNbArcArrivant))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	// Test destination positive
	if (0 > iDestination)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_negatif);
		EXCLevee.EXCmodifier_message("Destination negative !");
		throw(EXCLevee);
	}

	SOMLireArcArrivant(iIndice)->ARCModifierDestination(iDestination); //voir pour modifier
}

/*********************************************************
Supprime l'arc à l'indice iIndice dans la liste des arcs arrivants
*********************************************************
Entrée: int iIndice : l'indice de l'arc à supprimer
Nécessite: (rien)
Sortie: (rien)
Entraîne : 
(l'arc à l'indice iIndice a été supprimer) et (le tableau a été réallouer) ou
(Exception indice_incorrecte levée) ou
(Exception echec_malloc levée)
*********************************************************/
void CSommet::SOMSupprimerArcArrivant(int iIndice)
{
	// Test indice dans tableau
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
	if (!ppARCSOMArcSortant)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
}

/*********************************************************
Ajoute un arc dans la liste des arcs sortants
*********************************************************
Entrée: CArc* pARCArc : un pointeur vers l'arc à ajouter
Nécessite: (rien)
Sortie: (rien)
Entraîne :
(pARCArc à été ajouter en fin de la liste) et (le tableau a été réallouer) ou
(Exception argument_null levée) ou
(Exception echec_malloc levée)
*********************************************************/
void CSommet::SOMAjouterArcSortant(CArc* pARCArc)
{
	// Test paramètre non null
	if (!pARCArc)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(argument_null);
		EXCLevee.EXCmodifier_message("Le paramètre à rajouter dans la liste est null !");
		throw(EXCLevee);
	}

	ppARCSOMArcSortant = (CArc**)realloc(ppARCSOMArcSortant, sizeof(CArc*) * (uiSOMNbArcSortant + 1));
		/// Si l'allocation à réussi on rajoute l'arc
	if (ppARCSOMArcSortant)
	{
		*(ppARCSOMArcSortant + uiSOMNbArcSortant) = pARCArc;
		uiSOMNbArcSortant++;
	}
		/// Sinon une exception est levé
	else
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
}

/*********************************************************
Modifie l'arc à l'indice iIndice dans la liste des arcs sortants
*********************************************************
Entrée: int iIndice : l'indice de l'arc à modifier
		int iDestination : la nouvelle destination de cet arc
Nécessite: (rien)
Sortie: (rien)
Entraîne : (l'arc à l'indice iIndice à pour nouvelle destination iDestination) ou
(Exception indice_incorrecte levée) ou
(Exception destination_negatif levée)
*********************************************************/
void CSommet::SOMModifierArcSortant(int iIndice, int iDestination)
{
	// Test indice dans la liste
	if (0 > iIndice || iIndice > int(uiSOMNbArcSortant))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	// Test destination positive
	if (0 > iDestination)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_negatif);
		EXCLevee.EXCmodifier_message("Destination negative !");
		throw(EXCLevee);
	}

	SOMLireArcSortant(iIndice)->ARCModifierDestination(iDestination);
}


/*********************************************************
Supprime l'arc à l'indice iIndice dans la liste des arcs sortants
*********************************************************
Entrée: int iIndice : l'indice de l'arc à supprimer
Nécessite: (rien)
Sortie: (rien)
Entraîne :
(l'arc à l'indice iIndice a été supprimer) et (le tableau a été réallouer) ou
(Exception indice_incorrecte levée)
*********************************************************/
void CSommet::SOMSupprimerArcSortant(int iIndice)
{
	// Test indice dans la liste
	if (0 > iIndice || iIndice > int(uiSOMNbArcSortant))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	//on décale le tableau
	for (unsigned int iBoucle = iIndice; iBoucle < uiSOMNbArcSortant - 1; iBoucle++)
	{
		*(ppARCSOMArcSortant + iBoucle) = *(ppARCSOMArcSortant + iBoucle + 1);
	}
	//on réallou
	ppARCSOMArcSortant = (CArc**)realloc(ppARCSOMArcSortant, sizeof(CArc*) * (uiSOMNbArcSortant - 1));
	if (!ppARCSOMArcSortant)
	{
	CException EXCLevee;
	EXCLevee.EXCmodifier_valeur(echec_malloc);
	EXCLevee.EXCmodifier_message("Echec realloc !");
	throw(EXCLevee);
	}
}

/*********************************************************
Inverse l'orientation de tous les arcs reliés au sommet
*********************************************************
Entrée: int iIndice : l'indice de l'arc à supprimer
Nécessite: (rien)
Sortie: (rien)
Entraîne :
(l'arc à l'indice iIndice a été supprimer) et (le tableau a été réallouer) ou
(Exception indice_incorrecte levée)
*********************************************************/
void CSommet::SOMInverserArrivantPartant()
{

}