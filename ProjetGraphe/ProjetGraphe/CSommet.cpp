#include "CSommet.h"

/*********************************************************
Constructeur par d�faut de la classe CSommet
*********************************************************
Entr�e: (rien)
N�cessite: (rien)
Sortie: (rien)
Entra�ne :	(l'objet est initlialis� avec 
uiSOMNumero = 0,
uiSOMNbArcArrivant = uiSOMNbArcSortant = 0 et
ppARCSOMArcArrivant = ppARCSOMArcSortant = nullptr) 
*********************************************************/
CSommet::CSommet()
{
	// Initialisation des attributs
	uiSOMNumero = 0;

	uiSOMNbArcArrivant = uiSOMNbArcSortant = 0;

	ppARCSOMArcArrivant = nullptr;
	ppARCSOMArcSortant = nullptr;
}

/*********************************************************
Constructeur de recopie de la classe CSommet
*********************************************************
Entr�e: CSommet& SOMSommet : le sommet � recopier
N�cessite: (rien)
Sortie: (rien)
Entra�ne :	(l'objet est initialis� avec les attributs 
de SOMSommet pass� en param�tre) ou
(Exception echec_malloc lev�)
*********************************************************/
CSommet::CSommet(CSommet& SOMSommet)
{
	// Recopie du num�ro du sommet
	uiSOMNumero = SOMSommet.uiSOMNumero;

	// Recopie de la liste des arcs arrivants au sommet
	uiSOMNbArcArrivant = SOMSommet.uiSOMNbArcArrivant;
		/// Si pas d'arc, pas d'allocation
	if (uiSOMNbArcArrivant == 0)
	{
		ppARCSOMArcArrivant = nullptr;
	}
		/// Sinon, copie des arcs
	else
	{
		ppARCSOMArcArrivant = (CArc**) malloc(sizeof(CArc*) * uiSOMNbArcArrivant);
			/// Si l'allocation � r�ussi on copie la liste
		if (ppARCSOMArcArrivant != nullptr)
		{
			for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcArrivant; iBoucle++)
			{
				ppARCSOMArcArrivant[iBoucle] = new CArc(*SOMSommet.ppARCSOMArcArrivant[iBoucle]);
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

	// Recopie de la liste des arcs sortants du sommet
	uiSOMNbArcSortant = SOMSommet.uiSOMNbArcSortant;
		/// Si pas d'arc, pas d'allocation
	if (uiSOMNbArcSortant == 0)
	{
		ppARCSOMArcSortant = nullptr;
	}
		/// Sinon, copie des arcs
	else
	{
		ppARCSOMArcSortant = (CArc**) malloc(sizeof(CArc*) * uiSOMNbArcSortant);

			/// Si l'allocation � r�ussi on copie la liste
		if (ppARCSOMArcSortant != nullptr)
		{
			for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcSortant; iBoucle++)
			{
				ppARCSOMArcSortant[iBoucle] = new CArc(*SOMSommet.ppARCSOMArcSortant[iBoucle]);
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
	if (iNumeroSommet < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(numero_negatif);
		EXCLevee.EXCmodifier_message("Numero sommet negatif !");
		throw(EXCLevee);
	}

	uiSOMNumero = iNumeroSommet;
	uiSOMNbArcArrivant = uiSOMNbArcSortant = 0;
	ppARCSOMArcArrivant = nullptr;
	ppARCSOMArcSortant = nullptr;
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
	uiSOMNumero = 0;

	if (ppARCSOMArcArrivant != nullptr)
	{
		unsigned int uiNbArcArrivantTempo = uiSOMNbArcArrivant;
		for (unsigned int iBoucle = 0; iBoucle < uiNbArcArrivantTempo; iBoucle++)
		{
			if (ppARCSOMArcArrivant[iBoucle] != nullptr)
			{
				delete(ppARCSOMArcArrivant[iBoucle]);
				uiSOMNbArcArrivant--;
			}
		}
		free(ppARCSOMArcArrivant);
	}

	if (ppARCSOMArcSortant != nullptr)
	{
		unsigned int uiNbArcSortantTempo = uiSOMNbArcSortant;
		for (unsigned int iBoucle = 0; iBoucle < uiNbArcSortantTempo; iBoucle++)
		{
			if (ppARCSOMArcSortant[iBoucle] != nullptr)
			{
				delete(ppARCSOMArcSortant[iBoucle]);
				uiSOMNbArcSortant--;
			}
		}
		free(ppARCSOMArcSortant);
	}
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
unsigned int CSommet::SOMLireNombreArcArrivant()
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
Entra�ne : (CArc* en sortie) ou (Exception indice_incorrecte lev�e)
*********************************************************/
CArc* CSommet::SOMLireArcArrivant(int iIndice)
{
	// Test indice compris dans les bornes du tableau
	if (iIndice < 0 || iIndice > int(SOMLireNombreArcArrivant()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}
	return ppARCSOMArcArrivant[iIndice];
}

/*********************************************************
Retourne le nombre d'arc sortant du sommet
*********************************************************
Entr�e: (rien)
N�cessite: (rien)
Sortie: int uiSOMNbArcSortant : le nombre d'arc sortant au sommet
Entra�ne : (rien)
*********************************************************/
unsigned int CSommet::SOMLireNombreArcSortant()
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
Entra�ne : (CArc* en sortie) ou (Exception indice_incorrecte lev�e)
*********************************************************/
CArc* CSommet::SOMLireArcSortant(int iIndice)
{
	// Test indice compris dans les bornes du tableau
	if (iIndice < 0 || iIndice > int(SOMLireNombreArcSortant()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}
	return ppARCSOMArcSortant[iIndice];
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
N�cessite: (pARCArc doit �tre un pointeur vers un arc et non l'adresse d'un arc)
Sortie: (rien)
Entra�ne : 
(pARCArc � �t� ajouter en fin de la liste) et (le tableau a �t� r�allouer) ou
(Exception argument_null lev�e) ou 
(Exception echec_malloc lev�e) ou 
(Exception arc_existant lev�e)
*********************************************************/
void CSommet::SOMAjouterArcArrivant(CArc* pARCArc) 
{
	//On v�rifie que l'arc ne soit pas d�j� dans la liste
	if (SOMRechercheIndiceArcArrivant(pARCArc->ARCLireDestination()) != -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_existant);
		EXCLevee.EXCmodifier_message("L'arc est d�j� pr�sent dans la liste !");
		throw(EXCLevee);
	}

	// Test param�tre non null
	if (pARCArc == nullptr)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(argument_null);
		EXCLevee.EXCmodifier_message("Le param�tre � rajouter dans la liste est null !");
		throw(EXCLevee);
	}

	ppARCSOMArcArrivant = (CArc**) realloc(ppARCSOMArcArrivant, sizeof(CArc*) * (uiSOMNbArcArrivant + 1));
		/// Si l'allocation � r�ussi ajout de l'arc en fin de liste et actualisation du nombre d'arc entrant
	if (ppARCSOMArcArrivant != nullptr)
	{
		ppARCSOMArcArrivant[uiSOMNbArcArrivant] = new CArc(*pARCArc);
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
Modifie l'arc ayant pour destination iAncienDestination par
iNouvelleDestination dans la liste des arcs arrivants
*********************************************************
Entr�e: int iAncienDestination : l'ancienne destination de l'arc
	    int iNouvelleDestination : la nouvelle destination de cet arc
N�cessite: (rien)
Sortie: (rien)
Entra�ne : (l'arc ayant pour destination iAncienDestination a maintenant
iNouvelleDestination en destination) ou
(Exception arc_introuvable lev�e)
*********************************************************/
void CSommet::SOMModifierArcArrivant(int iAncienDestination, int iNouvelleDestination)
{
	// Test destination positive
	if (0 > iNouvelleDestination)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("Destination negative !");
		throw(EXCLevee);
	}
	
	int iIndiceArc = SOMRechercheIndiceArcArrivant(iAncienDestination);
	// Test indice dans la liste
	if (iIndiceArc == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	ppARCSOMArcArrivant[iIndiceArc]->ARCModifierDestination(iNouvelleDestination);
}

/*********************************************************
Supprime l'arc ayant pour destination iDestination
dans la liste des arcs arrivants
*********************************************************
Entr�e: int iDestination : la destination de l'arc � supprimer
N�cessite: (rien)
Sortie: (rien)
Entra�ne : 
(l'arc de destination iDestination a �t� supprimer) et (le tableau a �t� r�allouer) ou
(Exception liste_vide lev�e) ou
(Exception echec_malloc lev�e)ou
(Exception liste_vide lev�e)
*********************************************************/
void CSommet::SOMSupprimerArcArrivant(int iDestination)
{
	if (uiSOMNbArcArrivant == 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(liste_vide);
		EXCLevee.EXCmodifier_message("Liste arc entrant vide !");
		throw(EXCLevee);
	}

	int iIndiceArc = SOMRechercheIndiceArcArrivant(iDestination);
	// Test indice dans tableau
	if (iIndiceArc == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("L'arc n'est pas dans la liste !");
		throw(EXCLevee);
	}

	//on d�cale le tableau
	for (unsigned int iBoucle = iIndiceArc; iBoucle < uiSOMNbArcArrivant; iBoucle++)
	{
		ppARCSOMArcArrivant[iBoucle] = ppARCSOMArcArrivant[iBoucle + 1];
	}
	//on r�allou
	ppARCSOMArcArrivant = (CArc**)realloc(ppARCSOMArcArrivant, sizeof(CArc*) * (uiSOMNbArcArrivant - 1));
	if (ppARCSOMArcArrivant == nullptr && uiSOMNbArcArrivant - 1 > 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
	else
	{
		//On met � jour le nombre d'arc
		uiSOMNbArcArrivant--;
	}
}

/*********************************************************
Ajoute un arc dans la liste des arcs sortants
*********************************************************
Entr�e: CArc* pARCArc : un pointeur vers l'arc � ajouter
N�cessite: (pARCArc doit �tre un pointeur vers un arc et non l'adresse d'un arc)
Sortie: (rien)
Entra�ne :
(pARCArc � �t� ajouter en fin de la liste) et (le tableau a �t� r�allouer) ou
(Exception argument_null lev�e) ou
(Exception echec_malloc lev�e) ou
(Exception arc_existant lev�e)
*********************************************************/
void CSommet::SOMAjouterArcSortant(CArc* pARCArc)
{
	if (SOMRechercheIndiceArcSortant(pARCArc->ARCLireDestination()) != -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_existant);
		EXCLevee.EXCmodifier_message("L'arc est d�j� pr�sent dans la liste !");
		throw(EXCLevee);
	}

	// Test param�tre non null
	if (pARCArc == nullptr)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(argument_null);
		EXCLevee.EXCmodifier_message("Le param�tre � rajouter dans la liste est null !");
		throw(EXCLevee);
	}

	ppARCSOMArcSortant = (CArc**)realloc(ppARCSOMArcSortant, sizeof(CArc*) * (uiSOMNbArcSortant + 1));
		/// Si l'allocation � r�ussi on rajoute l'arc
	if (ppARCSOMArcSortant != nullptr)
	{
		ppARCSOMArcSortant[uiSOMNbArcSortant] = pARCArc;
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
Modifie l'arc ayant pour destination iAncienDestination par
iNouvelleDestination dans la liste des arcs sortants
*********************************************************
Entr�e: int iAncienDestination : l'ancienne destination de l'arc
		int iNouvelleDestination : la nouvelle destination de cet arc
N�cessite: (rien)
Sortie: (rien)
Entra�ne : (l'arc ayant pour destination iAncienDestination a maintenant
iNouvelleDestination en destination) ou
(Exception arc_introuvable lev�e)
*********************************************************/
void CSommet::SOMModifierArcSortant(int iAncienDestination, int iNouvelleDestination)
{
	// Test destination positive
	if (0 > iNouvelleDestination)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_negatif);
		EXCLevee.EXCmodifier_message("Destination negative !");
		throw(EXCLevee);
	}

	int iIndiceArc = SOMRechercheIndiceArcSortant(iAncienDestination);
	// Test indice dans la liste
	if (iIndiceArc == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	//On modifie la destination de l'arc
	ppARCSOMArcSortant[iIndiceArc]->ARCModifierDestination(iNouvelleDestination);
}


/*********************************************************
Supprime l'arc ayant pour destination iDestination
dans la liste des arcs sortants
*********************************************************
Entr�e: int iDestination : la destination de l'arc � supprimer
N�cessite: (rien)
Sortie: (rien)
Entra�ne :
(l'arc de destination iDestination a �t� supprimer) et (le tableau a �t� r�allouer) ou
(Exception liste_vide lev�e) ou
(Exception echec_malloc lev�e)ou
(Exception liste_vide lev�e)
*********************************************************/
void CSommet::SOMSupprimerArcSortant(int iDestination)
{
	if (uiSOMNbArcSortant == 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(liste_vide);
		EXCLevee.EXCmodifier_message("Liste arc sortant vide !");
		throw(EXCLevee);
	}

	int iIndiceArc = SOMRechercheIndiceArcSortant(iDestination);
	// Test indice dans tableau
	if (iIndiceArc == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("L'arc n'est pas dans la liste !");
		throw(EXCLevee);
	}

	//on d�cale le tableau
	for (unsigned int iBoucle = iIndiceArc; iBoucle < uiSOMNbArcSortant; iBoucle++)
	{
		ppARCSOMArcSortant[iBoucle] = ppARCSOMArcSortant[iBoucle + 1];
	}
	//on r�allou
	ppARCSOMArcSortant = (CArc**)realloc(ppARCSOMArcSortant, sizeof(CArc*) * (uiSOMNbArcSortant - 1));
	if (ppARCSOMArcSortant == nullptr && uiSOMNbArcSortant - 1 > 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
	else
	{
		//On met � jour le nombre d'arc
		uiSOMNbArcSortant--;
	}
}

/*********************************************************
Inverse l'orientation de tous les arcs reli�s au sommet
*********************************************************
Entr�e: (rien)
N�cessite: (rien)
Sortie: (rien)
Entra�ne :
(les arcs arrivant et sortant sont invers�)
*********************************************************/
CSommet& CSommet::SOMInverserArrivantPartant()
{
	CSommet* pSOMSommet = new CSommet(uiSOMNumero);

	//Inversion des arc : les sortants deviennent arrivant
	for (unsigned int uiBoucleArcArrivant = 0; uiBoucleArcArrivant < uiSOMNbArcArrivant; uiBoucleArcArrivant++)
	{
		pSOMSommet->SOMAjouterArcArrivant(SOMLireArcSortant(uiBoucleArcArrivant));
	}

	//Inversion des arc : les arrivant deviennent sortants
	for (unsigned int uiBoucleArcSortant = 0; uiBoucleArcSortant < uiSOMNbArcSortant; uiBoucleArcSortant++)
	{
		pSOMSommet->SOMAjouterArcSortant(SOMLireArcArrivant(uiBoucleArcSortant));
	}

	return *pSOMSommet;
}

/*********************************************************
Recherche l'indice de l'arc arrivant de destination iDestination
**********************************************************
Entr�e: int iDestination : la destination de l'arc 
� rechercher dans le sommet
N�cessite:	(iDestination > 0)
Sortie: int : l'indice de l'arc trouv� ou -1 si l'arc n'est pas dans le sommet.
Entra�ne :	(rien)
*********************************************************/
int CSommet::SOMRechercheIndiceArcArrivant(int iDestination)
{
	for (unsigned int uiBoucleArcArrivant = 0; uiBoucleArcArrivant < uiSOMNbArcArrivant; uiBoucleArcArrivant++)
	{
		if (ppARCSOMArcArrivant[uiBoucleArcArrivant]->ARCLireDestination() == iDestination)
		{
			return uiBoucleArcArrivant;
		}
	}
	return -1;
}

/*********************************************************
Recherche l'indice de l'arc sortant de destination iDestination
*********************************************************
Entr�e: int iDestination : la destination de l'arc 
� rechercher dans le sommet
N�cessite:	(iDestination > 0)
Sortie: int : l'indice de l'arc trouv� ou -1 si l'arc n'est pas dans le sommet.
Entra�ne :	(rien)
*********************************************************/
int CSommet::SOMRechercheIndiceArcSortant(int iDestination)
{
	for (unsigned int uiBoucleArcSortant = 0; uiBoucleArcSortant < uiSOMNbArcSortant; uiBoucleArcSortant++)
	{
		if (ppARCSOMArcSortant[uiBoucleArcSortant]->ARCLireDestination() == iDestination)
		{
			return uiBoucleArcSortant;
		}
	}
	return -1;
}

/*********************************************************
Surcharge de l'op�rateur d'affectation pour la classe CSommet
*********************************************************
Entr�e: CSommet& SOMSommet : le sommet � affecter
N�cessite:	(rien)
Sortie: CSommet& : le sommet affect�
Entra�ne :	(le sommet en param�tre � �t� affecter au sommet courant)
*********************************************************/
CSommet& CSommet::operator=(CSommet& SOMSommet)
{
	// Recopie du num�ro du sommet
	uiSOMNumero = SOMSommet.uiSOMNumero;

	// Recopie de la liste des arcs arrivants au sommet
	uiSOMNbArcArrivant = SOMSommet.uiSOMNbArcArrivant;
	/// Si pas d'arc, pas d'allocation
	if (uiSOMNbArcArrivant == 0)
	{
		ppARCSOMArcArrivant = nullptr;
	}
	/// Sinon copie des arcs
	else
	{
		ppARCSOMArcArrivant = (CArc**)malloc(sizeof(CArc*) * uiSOMNbArcArrivant);
		/// Si l'allocation � r�ussi on copie la liste
		if (ppARCSOMArcArrivant != nullptr)
		{
			for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcArrivant; iBoucle++)
			{
				*(ppARCSOMArcArrivant + iBoucle) = new CArc(*SOMSommet.ppARCSOMArcArrivant[iBoucle]);
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

	// Recopie de la liste des arcs sortants du sommet
	uiSOMNbArcSortant = SOMSommet.uiSOMNbArcSortant;
	/// Si pas d'arc, pas d'allocation
	if (uiSOMNbArcSortant == 0)
	{
		ppARCSOMArcSortant = nullptr;
	}
	/// Sinon copie des arcs
	else
	{
		ppARCSOMArcSortant = (CArc**)malloc(sizeof(CArc*) * uiSOMNbArcSortant);

		/// Si l'allocation � r�ussi on copie la liste
		if (ppARCSOMArcSortant != nullptr)
		{
			for (unsigned int iBoucle = 0; iBoucle < uiSOMNbArcSortant; iBoucle++)
			{
				*(ppARCSOMArcSortant + iBoucle) = new CArc(*SOMSommet.ppARCSOMArcSortant[iBoucle]);
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
	return *this;
}