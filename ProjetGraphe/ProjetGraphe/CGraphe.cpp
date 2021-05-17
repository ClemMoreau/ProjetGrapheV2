#include "CGraphe.h"

/*********************************************************
Constructeur par défaut de la classe CGraphe
*********************************************************
Entrée:(rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	(L'objet est initialisé avec 
uiGRANbSommet = 0 et pSOMGRAListeSommet = nullptr)
*********************************************************/
CGraphe::CGraphe()
{
	// Initialisation des attributs
	uiGRANbSommet = 0;
	pSOMGRAListeSommet = nullptr;
}

/*********************************************************
Constructeur de recopie de la classe CGraphe 
prenant un CGraphe en paramètre
*********************************************************
Entrée: CGraphe& GRAGraphe : le graphe à recopier
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	(L'objet est initialisé avec
uiGRANbSommet = GRAGraphe.uiGRANbSommet 
et pSOMGRAListeSommet = GRAGraphe.pSOMGRAListeSommet)
*********************************************************/
CGraphe::CGraphe(CGraphe& GRAGraphe)
{
	// Recopie du nombre de sommet
	uiGRANbSommet = GRAGraphe.uiGRANbSommet;

	// Allocation en mémoire de la lsite de sommet
	pSOMGRAListeSommet = (CSommet*)malloc(uiGRANbSommet * sizeof(CSommet));

	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommet; uiBoucle++)
	{
		// Copie des sommets 
		pSOMGRAListeSommet[uiGRANbSommet] = GRAGraphe.pSOMGRAListeSommet[uiGRANbSommet];
	}
}

/*********************************************************
Constructeur de la classe CGraphe
prenant en paramètre un entier
*********************************************************
Entrée: int iNombreSommet : le nombre de sommet du graphe à créer
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	(L'objet est initialisé avec
uiGRANbSommet = iNombreSommet
et pSOMGRAListeSommet = GRAGraphe.pSOMGRAListeSommet)
*********************************************************/
CGraphe::CGraphe(int iNombreSommet)
{
	// Initialisation du nombre de sommet
	uiGRANbSommet = iNombreSommet;

	// Allocation en mémoire de la liste de sommet
	pSOMGRAListeSommet = (CSommet*)malloc(uiGRANbSommet * sizeof(CSommet));
}///peut être à suppr

CGraphe::~CGraphe()
{
	// On vide le graphe de ces sommets
	uiGRANbSommet = 0;

	// Libération de la liste de sommet
	free(pSOMGRAListeSommet);
}

/*********************************************************
Retourne le nombre de sommets du graphe
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: unsgined int : le nombre de sommet du graphe
Entraîne :	(rien)
*********************************************************/
unsigned int CGraphe::GRALireNombreSommet()
{
	return uiGRANbSommet;
}

/*********************************************************
Retourne la liste des sommets du graphe
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: CSommet* : la liste des sommets du graphe
Entraîne :	(rien)
*********************************************************/
CSommet* CGraphe::GRALireListeSommet()
{
	return pSOMGRAListeSommet;
}

/*********************************************************
Retourne le sommet d'indice iIndice
dans la liste des sommets du graphe
*********************************************************
Entrée: int iIndice : indice du sommet à retourner
Nécessite:	(rien)
Sortie: CSommet : le sommet d'indice iIndice
Entraîne :	(rien)
*********************************************************/
CSommet CGraphe::GRALireSommet(int iIndice)
{
	// Vérification de l'indice en paramètre
	if (iIndice < 0 || iIndice > int(uiGRANbSommet))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	return pSOMGRAListeSommet[iIndice];
}

//ATTENTION FAIRE GAFFE : MAYBE COMME SOMRAJOUTERARC FAUDRA METTRE DES POINTEURS SINON CA PEUT BUGUER?

/*********************************************************
Ajoute un sommet au graphe
*********************************************************
Entrée: CSommet& SOMSommet : le sommet à rajouter dans le graphe
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	(SOMSommet a été rajouter à la fin de la liste des sommets) ou
(Exception echec_malloc levée)
*********************************************************/
void CGraphe::GRAAjouterSommet(CSommet& SOMSommet)
{
	// Reallocation de la liste de sommet du graphe
	pSOMGRAListeSommet = (CSommet*) realloc(pSOMGRAListeSommet, (uiGRANbSommet + 1) * sizeof(CSommet));
	///Si l'allocation à réussi
	if (pSOMGRAListeSommet != nullptr)
	{
		// Ajout du sommet dans la liste et mise à jour du nombre de sommet du graphe
		pSOMGRAListeSommet[uiGRANbSommet] = SOMSommet;
		uiGRANbSommet++;
	}
	///Sinon on lève une exception
	else
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
}

/*********************************************************
Modifie le sommet d'indice iIndice
dans la liste des sommets du graphe
*********************************************************
Entrée: int iIndice : indice du sommet à modifier
		CSommet& SOMSommet : le nouveau sommet du graphe
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	(pSOMGRAListeSommet[iIndice - 1] = SOMSommet) ou
(Exception indice_incorrecte levée)
*********************************************************/
void CGraphe::GRAModifierSommet(int iIndice, CSommet& SOMSommet)
{
	if (iIndice < 0 || iIndice > int(uiGRANbSommet))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	pSOMGRAListeSommet[iIndice - 1] = SOMSommet;
}

/*********************************************************
Supprime le sommet d'indice iIndice
dans la liste des sommets du graphe
*********************************************************
Entrée: int iIndice : indice du sommet à supprimer
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	(Le sommet d'indice iIndice a été supprimer) ou
(Exception indice_incorrecte levée) ou
(Exception liste_vide levée)  ou
(Exception echec_malloc levée)
*********************************************************/
void CGraphe::GRASupprimerSommet(int iIndice)
{
	// Si la liste est vide on lève une exception
	if (uiGRANbSommet == 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(liste_vide);
		EXCLevee.EXCmodifier_message("liste vide !");
		throw(EXCLevee);
	}

	// Si l'indice passé en paramètre n'est pas dans le tableau on lève une exception
	if (iIndice < 0 || iIndice > int(uiGRANbSommet))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}
	
	// On décale les sommets à partir du sommet à supprimer pour l'écraser
	for (unsigned int uiBoucle = iIndice; uiBoucle <= uiGRANbSommet - 1; uiBoucle++)
	{
		pSOMGRAListeSommet[uiBoucle - 1] = pSOMGRAListeSommet[uiBoucle];
	}

	// Si il n'y avait qu'un seul sommet on désalloue la liste
	if (uiGRANbSommet - 1 == 0)
	{
		free(pSOMGRAListeSommet);
		pSOMGRAListeSommet = nullptr;
	}
	// Si on réalloue la liste avec la nouvelle taille
	else
	{
		pSOMGRAListeSommet = (CSommet*)realloc(pSOMGRAListeSommet, (uiGRANbSommet - 1) * sizeof(CSommet));
		// Si l'allocation à réussi on met à jour le nombre de sommet
		if (pSOMGRAListeSommet != nullptr)
		{
			uiGRANbSommet--;
		}
		// Sinon on lève une exception
		else
		{
			CException EXCLevee;
			EXCLevee.EXCmodifier_valeur(echec_malloc);
			EXCLevee.EXCmodifier_message("Echec realloc !");
			throw(EXCLevee);
		}

	}
}

//revoir les cas particuliers

/*********************************************************
Ajoute un arc au graphe
entre les sommets iNumeroSommetDepart et iNumeroSommetDestination
*********************************************************
Entrée: int iNumeroSommetDepart : le numero du sommet de depart
		int iNumeroSommetDestination : le numero du sommet de destination
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	(deux arcs entre iNumeroSommetDepart et iNumeroSommetDestination ont été rajouter) ou
(Exception sommet_introuvable levée)
*********************************************************/
void CGraphe::GRAAjouterArc(int iNumeroSommetDepart, int iNumeroSommetDestination)
{
	// Initialisation des variables locales
	bool bTestPresenceSommetDepart = false;
	bool bTestPresenceSommetDestination = false;
	unsigned int uiBoucle, uiIndiceSommetDepart, uiIndiceSommetDestination;

	for (uiBoucle = 0; uiBoucle < uiGRANbSommet; uiBoucle++)
	{
		// Recherche du sommet de départ
		if (pSOMGRAListeSommet[uiBoucle].SOMLireNumeroSommet() == iNumeroSommetDepart)
		{
			bTestPresenceSommetDepart = true;
			uiIndiceSommetDepart = uiBoucle;
		}

		// Recherche du sommet de destination
		if (pSOMGRAListeSommet[uiBoucle].SOMLireNumeroSommet() == iNumeroSommetDestination)
		{
			bTestPresenceSommetDestination = true;
			uiIndiceSommetDestination = uiBoucle;
		}
	}

	// Si le sommet de départ n'est pas dans la liste on lève une exception 
	/// on rajoute un sommet?
	if (bTestPresenceSommetDepart == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de départ n'a pas été trouvé dans la liste !");
		throw EXCLevee;
	}

	// Si le sommet de destination n'est pas dans la liste on lève une exception 
	/// on rajoute un sommet?
	if (bTestPresenceSommetDestination == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de destination n'a pas été trouvé dans la liste !");
		throw EXCLevee;
	}

	// Ajout d'un arc partant en destination de iNumeroSometDestination
	CArc* pARCArcPartant = new CArc(iNumeroSommetDestination);
	pSOMGRAListeSommet[uiIndiceSommetDepart].SOMAjouterArcSortant(pARCArcPartant);

	// Ajout d'un arc arrivant en destination de iNumeroSommetDepart
	CArc* pARCArcArrivant = new CArc(iNumeroSommetDepart);
	pSOMGRAListeSommet[uiIndiceSommetDestination].SOMAjouterArcArrivant(pARCArcArrivant);
}

//mettre des try catchs

/*********************************************************
Modifie l'arc allant de iAncienSommetDepart à iAncienSommetDestination
*********************************************************
Entrée: int iAncienSommetDepart : le numero de l'ancien sommet de depart
		int iAncienSommetDestination : le numero de l'ancien sommet de destination
		int iNouveauSommetDepart : le numero du nouveau sommet de depart
		int iNouveauSommetDestination : le numero du nouveau sommet de destination
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	()
*********************************************************/
void CGraphe::GRAModifierArc(int iAncienSommetDepart, int iAncienSommetDestination, int iNouveauSommetDepart, int iNouveauSommetDestination)
{	
	try
	{
		GRASupprimerArc(iAncienSommetDepart, iAncienSommetDestination);
		//GRASupprimerArc(iAncienSommetDestination, iAncienSommetDepart);
		GRAAjouterArc(iNouveauSommetDepart, iNouveauSommetDestination);
		//GRAAjouterArc(iAncienSommetDestination, iAncienSommetDepart);
	}
	catch (CException EXCLevee)
	{
		std::cout << EXCLevee.EXClire_message() << std::endl;
	}
}

/*********************************************************
Supprime l'arc allant de iNumeroSommetDepart à iNumeroSommetDestination
*********************************************************
Entrée: int iNumeroSommetDepart : le numero du sommet de depart
		int iNumeroSommetDestination : le numero du sommet de destination
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	()
*********************************************************/
void CGraphe::GRASupprimerArc(int iNumeroSommetDepart, int iNumeroSommetDestination)
{
	// Initalisation variables locales
	bool bTestPresenceSommetDepart = false;
	bool bTestPresenceSommetDestination = false;
	unsigned int uiBoucleSommet, uiIndiceSommetDepart, uiIndiceSommetDestination;

	for (uiBoucleSommet = 0; uiBoucleSommet < uiGRANbSommet || bTestPresenceSommetDepart == false; uiBoucleSommet++)
	{
		// Recherche du sommet de depart
		if (int(pSOMGRAListeSommet[uiBoucleSommet].SOMLireNumeroSommet()) == iNumeroSommetDepart)
		{
			bTestPresenceSommetDepart = true;
			uiIndiceSommetDepart = uiBoucleSommet;
		}

		// Recherche du sommet de destination
		if (int(pSOMGRAListeSommet[uiBoucleSommet].SOMLireNumeroSommet()) == iNumeroSommetDestination)
		{
			bTestPresenceSommetDestination = true;
			uiIndiceSommetDestination = uiBoucleSommet;
		}
	}

	// Si le sommet de départ n'est pas présent on lève une exception
	if (bTestPresenceSommetDepart == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de départ n'est pas dans la liste !");
		throw EXCLevee;
	}

	// Si le sommet de destination n'est pas présent on lève une exception
	if (bTestPresenceSommetDestination == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de destination n'est pas dans la liste !");
		throw EXCLevee;
	}

	// Initialisation des variables de recherche des arcs
	bool bTestPresenceArcSortant = false, bTestPresenceArcArrivant = false;;
	unsigned int uiBoucleArc, uiIndiceArcSortant, uiIndiceArcArrivant;

	for (uiBoucleArc = 1; uiBoucleArc <= pSOMGRAListeSommet[uiIndiceSommetDepart].SOMLireNombreArcSortant() || bTestPresenceArcSortant == false; uiBoucleArc++)
	{
		// Recherche de l'arc iNumeroSommetDepart -> iNumeroSommetDestination
		if (pSOMGRAListeSommet[uiIndiceSommetDepart].SOMLireArcSortant(uiBoucleArc)->ARCLireDestination() == iNumeroSommetDestination)
		{
			bTestPresenceArcSortant = true;
			uiIndiceArcSortant = uiBoucleArc;
		}
	}
	for (uiBoucleArc = 1; uiBoucleArc <= pSOMGRAListeSommet[uiIndiceSommetDestination].SOMLireNombreArcArrivant() || bTestPresenceArcArrivant == false; uiBoucleArc++)
	{
		// Recherche de l'arc iNumeroSommetDestination -> iNumeroSommetDepart 
		if (pSOMGRAListeSommet[uiIndiceSommetDestination].SOMLireArcArrivant(uiBoucleArc)->ARCLireDestination() == iNumeroSommetDepart)
		{
			bTestPresenceArcArrivant = true;
			uiIndiceArcArrivant = uiBoucleArc;
		}
	}

	// Si l'arc iNumeroSommetDepart -> iNumeroSommetDestination n'est pas présent on lève une exception
	if (bTestPresenceArcSortant == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("L'arc n'est pas dans la liste des sortants du sommet!");
		throw EXCLevee;
	}

	// Si l'arc iNumeroSommetDestination -> iNumeroSommetDepart n'est pas présent on lève une exception
	if (bTestPresenceArcArrivant == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("L'arc n'est pas dans la liste des sortants du sommet!");
		throw EXCLevee;
	}

	// Suppression des arcs
	pSOMGRAListeSommet[uiIndiceSommetDepart].SOMSupprimerArcSortant(uiIndiceArcSortant);
	pSOMGRAListeSommet[uiIndiceSommetDestination].SOMSupprimerArcArrivant(uiIndiceArcArrivant);
}

CGraphe CGraphe::GRAInverseGraphe()
{
	CGraphe GRAGraphe;
	return GRAGraphe;
}

/*********************************************************
Affiche le graphe dans le console
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	()
*********************************************************/
void CGraphe::GRAAfficherGraphe()
{
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiGRANbSommet; uiBoucleSommet++)
	{
		std::cout << "*************************" << std::endl;
		std::cout << "    Sommet numero : " << pSOMGRAListeSommet[uiBoucleSommet].SOMLireNumeroSommet() << std::endl;
		std::cout << "Liste arcs arrivant : " << std::endl;
		for (unsigned int uiBoucleArcArrivant = 1; uiBoucleArcArrivant <= pSOMGRAListeSommet[uiBoucleSommet].SOMLireNombreArcArrivant(); uiBoucleArcArrivant++)
		{
			std::cout << "Arc numero : " << uiBoucleArcArrivant << std::endl;
			std::cout << "	Destination : " << pSOMGRAListeSommet[uiBoucleSommet].SOMLireArcArrivant(uiBoucleArcArrivant)->ARCLireDestination() << std::endl;
		}
		std::cout << std::endl << "Liste arcs sortant : " << std::endl;
		for (unsigned int uiBoucleArcSortant = 1; uiBoucleArcSortant <= pSOMGRAListeSommet[uiBoucleSommet].SOMLireNombreArcSortant(); uiBoucleArcSortant++)
		{
			std::cout << "Arc numero : " << uiBoucleArcSortant << std::endl;
			std::cout << "	Destination : " << pSOMGRAListeSommet[uiBoucleSommet].SOMLireArcSortant(uiBoucleArcSortant)->ARCLireDestination() << std::endl;
		}
		std::cout << "*************************" << std::endl << std::endl;
	}
}

/*********************************************************
Surcharge de l'opérateur d'affectation pour la classe CGraphe
*********************************************************/
CGraphe& CGraphe::operator=(CGraphe& GRAGraphe)
{
	uiGRANbSommet = GRAGraphe.uiGRANbSommet;

	pSOMGRAListeSommet = new CSommet[uiGRANbSommet];

	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommet; uiBoucle++)
	{
		pSOMGRAListeSommet[uiGRANbSommet] = GRAGraphe.pSOMGRAListeSommet[uiGRANbSommet];
	}

	return *this;
}