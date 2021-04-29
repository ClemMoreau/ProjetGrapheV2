#include "CSommet.h"

/*********************************************************
Constructeur par d�faut de la classe CSommet
*********************************************************
Entr�e: (rien)
N�cessite: (rien)
Sortie: (rien)
Entra�ne :	(l'objet est initlialis� avec 
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
Entr�e: CSommet& SOMSommet : le sommet � recopier
N�cessite: (rien)
Sortie: (rien)
Entra�ne :	(l'objet est initlialis� avec les attributs 
de SOMSommet pass� en param�tre) ou
(Exception echec_malloc lev�)
*********************************************************/
CSommet::CSommet(CSommet& SOMSommet)
{
	// Recopie du num�ro du sommet
	uiSOMNumero = SOMSommet.SOMLireNumeroSommet();

	// Recopie de la liste des arcs arrivants au sommet
	uiSOMNbArcArrivant = SOMSommet.SOMLireNombreArcArrivant();
	ppARCSOMArcArrivant = (CArc**) realloc(ppARCSOMArcArrivant, sizeof(CArc*) * uiSOMNbArcArrivant);
		/// Si l'allocation � r�ussi on copie la liste
	if (ppARCSOMArcArrivant)
	{
		for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcArrivant; iBoucle++)
		{
			*(ppARCSOMArcArrivant + iBoucle) = new CArc(*SOMSommet.SOMLireArcArrivant(iBoucle + 1));
		}
	}
		/// Sinon une exception est lev�
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
		/// Si l'allocation � r�ussi on copie la liste
	if (ppARCSOMArcSortant)
	{
		for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcSortant; iBoucle++)
		{
			*(ppARCSOMArcSortant + iBoucle) = new CArc(*SOMSommet.SOMLireArcSortant(iBoucle + 1));
		}
	}
		/// Sinon une exception est lev�
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
prenant en param�tre un int
*********************************************************
Entr�e: int iNumeroSommet : le numero du sommet � cr�er
N�cessite: (rien)
Sortie: (rien)
Entra�ne :	(l'objet est initlialis� avec uiSOMNumero = iNumeroSommet)
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
Entr�e: (rien)
N�cessite: (rien)
Sortie: (rien)
Entra�ne : (l'espace m�moire des listes des arcs est lib�r�)
*********************************************************/
CSommet::~CSommet()
{
	/*� modifier passer par suppr arc qui appel destructeur*/
	for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcArrivant; iBoucle++) //v�rifier fuite (tester si commencer � 1 mieux)
	{
		free(*(ppARCSOMArcArrivant + iBoucle));
	}
	//free(ppARCSOMArcArrivant); �a fais planter wtf

	for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcSortant; iBoucle++) //v�rifier fuite (tester si commencer � 1 mieux)
	{
		free(*(ppARCSOMArcSortant + iBoucle));
	}
	//free(ppARCSOMArcSortant);
}

/*********************************************************
Retourne le numero du sommet
*********************************************************
Entr�e: (rien)
N�cessite: (rien)
Sortie: unsigned int uiSOMNumero : le numero du sommet courant
Entra�ne : (rien)
*********************************************************/
unsigned int CSommet::SOMLireNumeroSommet()
{
	return uiSOMNumero;
}

/*********************************************************
Retourne le nombre d'arc arrivant du sommet
*********************************************************
Entr�e: (rien)
N�cessite: (rien)
Sortie: int uiSOMNbArcArrivant : le nombre d'arc arrivant au sommet
Entra�ne : (rien)
*********************************************************/
int CSommet::SOMLireNombreArcArrivant()
{
	return uiSOMNbArcArrivant;
}


/*********************************************************
Retourne l'arc � l'indice iIndice
du tableau des arcs arrivants	
*********************************************************
Entr�e: int iIndice : l'indice de l'arc � retourner
N�cessite: (rien) 
Sortie: CArc* : l'arc � l'indice iIndice de la liste des arcs arrivants
Entra�ne : (CArcs* en sortie) ou (Exception indice_incorrecte lev�e)
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
Entr�e: (rien)
N�cessite: (rien)
Sortie: int uiSOMNbArcSortant : le nombre d'arc sortant au sommet
Entra�ne : (rien)
*********************************************************/
int CSommet::SOMLireNombreArcSortant()
{
	return uiSOMNbArcSortant;
}

/*********************************************************
Retourne l'arc � l'indice iIndice
du tableau des arcs sortants
*********************************************************
Entr�e: int iIndice : l'indice de l'arc � retourner
N�cessite: (rien)
Sortie: CArc* : l'arc � l'indice iIndice de la liste des arcs sortants
Entra�ne : (CArcs* en sortie) ou (Exception indice_incorrecte lev�e)
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
Modifie le num�ro du sommet
*********************************************************
Entr�e: int iNumero : le nouveau num�ro de sommet
N�cessite: (rien)
Sortie: (rien)
Entra�ne : (this.uiSOMNumero = iNumero) ou (Exception numero_negatif lev�e)
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
Entr�e: CArc* pARCArc : un pointeur vers l'arc � ajouter
N�cessite: (rien)
Sortie: (rien)
Entra�ne : 
(pARCArc � �t� ajouter en fin de la liste) et (le tableau a �t� r�allouer) ou
(Exception argument_null lev�e) ou 
(Exception echec_malloc lev�e)
*********************************************************/
void CSommet::SOMAjouterArcArrivant(CArc* pARCArc) 
{
	// Test param�tre non null
	if (!pARCArc)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(argument_null);
		EXCLevee.EXCmodifier_message("Le param�tre � rajouter dans la liste est null !");
		throw(EXCLevee);
	}
	/*un arc arrivant � forc�ment dans sa destination le sommet courant?*/
	/*if (pARCArc->ARCLireDestination() != uiSOMNumero)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_incoh�rente);
		EXCLevee.EXCmodifier_message("Un arc arrivant doit avoir pour destination le sommet courant !");
		throw(EXCLevee);
	}*/

	ppARCSOMArcArrivant = (CArc**) realloc(ppARCSOMArcArrivant, sizeof(CArc*) * (uiSOMNbArcArrivant + 1));
		/// Si l'allocation � r�ussi on rajoute l'arc
	if (ppARCSOMArcArrivant)
	{
		*(ppARCSOMArcArrivant + uiSOMNbArcArrivant) = pARCArc;
		uiSOMNbArcArrivant++;
	}
		/// Sinon une exception est lev�
	else
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
}

/*********************************************************
Modifie l'arc � l'indice iIndice dans la liste des arcs arrivants
*********************************************************
Entr�e: int iIndice : l'indice de l'arc � modifier
	    int iDestination : la nouvelle destination de cet arc
N�cessite: (rien)
Sortie: (rien)
Entra�ne : (l'arc � l'indice iIndice � pour nouvelle destination iDestination) ou
(Exception indice_incorrecte lev�e) ou
(Exception destination_negatif lev�e)
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
Supprime l'arc � l'indice iIndice dans la liste des arcs arrivants
*********************************************************
Entr�e: int iIndice : l'indice de l'arc � supprimer
N�cessite: (rien)
Sortie: (rien)
Entra�ne : 
(l'arc � l'indice iIndice a �t� supprimer) et (le tableau a �t� r�allouer) ou
(Exception indice_incorrecte lev�e) ou
(Exception echec_malloc lev�e)
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

	//on d�cale le tableau
	for (unsigned int iBoucle = iIndice; iBoucle < uiSOMNbArcArrivant - 1; iBoucle++)
	{
		*(ppARCSOMArcArrivant + iBoucle) = *(ppARCSOMArcArrivant + iBoucle + 1);
	}
	//on r�allou
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
Entr�e: CArc* pARCArc : un pointeur vers l'arc � ajouter
N�cessite: (rien)
Sortie: (rien)
Entra�ne :
(pARCArc � �t� ajouter en fin de la liste) et (le tableau a �t� r�allouer) ou
(Exception argument_null lev�e) ou
(Exception echec_malloc lev�e)
*********************************************************/
void CSommet::SOMAjouterArcSortant(CArc* pARCArc)
{
	// Test param�tre non null
	if (!pARCArc)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(argument_null);
		EXCLevee.EXCmodifier_message("Le param�tre � rajouter dans la liste est null !");
		throw(EXCLevee);
	}

	ppARCSOMArcSortant = (CArc**)realloc(ppARCSOMArcSortant, sizeof(CArc*) * (uiSOMNbArcSortant + 1));
		/// Si l'allocation � r�ussi on rajoute l'arc
	if (ppARCSOMArcSortant)
	{
		*(ppARCSOMArcSortant + uiSOMNbArcSortant) = pARCArc;
		uiSOMNbArcSortant++;
	}
		/// Sinon une exception est lev�
	else
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
}

/*********************************************************
Modifie l'arc � l'indice iIndice dans la liste des arcs sortants
*********************************************************
Entr�e: int iIndice : l'indice de l'arc � modifier
		int iDestination : la nouvelle destination de cet arc
N�cessite: (rien)
Sortie: (rien)
Entra�ne : (l'arc � l'indice iIndice � pour nouvelle destination iDestination) ou
(Exception indice_incorrecte lev�e) ou
(Exception destination_negatif lev�e)
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
Supprime l'arc � l'indice iIndice dans la liste des arcs sortants
*********************************************************
Entr�e: int iIndice : l'indice de l'arc � supprimer
N�cessite: (rien)
Sortie: (rien)
Entra�ne :
(l'arc � l'indice iIndice a �t� supprimer) et (le tableau a �t� r�allouer) ou
(Exception indice_incorrecte lev�e)
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

	//on d�cale le tableau
	for (unsigned int iBoucle = iIndice; iBoucle < uiSOMNbArcSortant - 1; iBoucle++)
	{
		*(ppARCSOMArcSortant + iBoucle) = *(ppARCSOMArcSortant + iBoucle + 1);
	}
	//on r�allou
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
Inverse l'orientation de tous les arcs reli�s au sommet
*********************************************************
Entr�e: int iIndice : l'indice de l'arc � supprimer
N�cessite: (rien)
Sortie: (rien)
Entra�ne :
(l'arc � l'indice iIndice a �t� supprimer) et (le tableau a �t� r�allouer) ou
(Exception indice_incorrecte lev�e)
*********************************************************/
void CSommet::SOMInverserArrivantPartant()
{

}