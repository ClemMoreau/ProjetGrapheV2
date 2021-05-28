#include "CGraphe.h"

/*********************************************************
Constructeur par d�faut de la classe CGraphe
*********************************************************
Entr�e:(rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	(L'objet est initialis� avec 
uiGRANbSommet = 0 et pSOMGRAListeSommet = nullptr)
*********************************************************/
CGraphe::CGraphe()
{
	// Initialisation des attributs
	uiGRANbSommet = 0;
	ppSOMGRAListeSommet = nullptr;
}

/*********************************************************
Constructeur de recopie de la classe CGraphe 
prenant un CGraphe en param�tre
*********************************************************
Entr�e: CGraphe& GRAGraphe : le graphe � recopier
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	(L'objet est initialis� avec
uiGRANbSommet = GRAGraphe.uiGRANbSommet 
et pSOMGRAListeSommet = GRAGraphe.pSOMGRAListeSommet)
*********************************************************/
CGraphe::CGraphe(CGraphe& GRAGraphe)
{
	// Recopie du nombre de sommet
	uiGRANbSommet = GRAGraphe.uiGRANbSommet;

	// Allocation en m�moire de la lsite de sommet
	ppSOMGRAListeSommet = (CSommet**)malloc(uiGRANbSommet * sizeof(CSommet*));

	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommet; uiBoucle++)
	{
		// Copie des sommets 
		//ppSOMGRAListeSommet[uiGRANbSommet] = new CSommet(*GRAGraphe.ppSOMGRAListeSommet[uiBoucle]);
		GRAAjouterSommet(*GRAGraphe.ppSOMGRAListeSommet[uiBoucle]);
	}
}

/*********************************************************
Constructeur de la classe CGraphe
prenant en param�tre un entier
*********************************************************
Entr�e: int iNombreSommet : le nombre de sommet du graphe � cr�er
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	(L'objet est initialis� avec
uiGRANbSommet = iNombreSommet
et pSOMGRAListeSommet = GRAGraphe.pSOMGRAListeSommet)
*********************************************************/
CGraphe::CGraphe(int iNombreSommet)
{
	// Initialisation du nombre de sommet
	uiGRANbSommet = iNombreSommet;

	// Allocation en m�moire de la liste de sommet
	ppSOMGRAListeSommet = (CSommet**)malloc(uiGRANbSommet * sizeof(CSommet*));
}///peut �tre � suppr

CGraphe::~CGraphe()
{
	// On vide le graphe de ces sommets
	uiGRANbSommet = 0;

	// Lib�ration de la liste de sommet
	free(ppSOMGRAListeSommet);
}

/*********************************************************
Retourne le nombre de sommets du graphe
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: unsgined int : le nombre de sommet du graphe
Entra�ne :	(rien)
*********************************************************/
unsigned int CGraphe::GRALireNombreSommet()
{
	return uiGRANbSommet;
}

/*********************************************************
Retourne la liste des sommets du graphe
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: CSommet* : la liste des sommets du graphe
Entra�ne :	(rien)
*********************************************************/
CSommet** CGraphe::GRALireListeSommet()
{
	return ppSOMGRAListeSommet;
}

/*********************************************************
Retourne le sommet d'indice iIndice
dans la liste des sommets du graphe
*********************************************************
Entr�e: int iIndice : indice du sommet � retourner
N�cessite:	(rien)
Sortie: CSommet : le sommet d'indice iIndice
Entra�ne :	(rien)
*********************************************************/
CSommet& CGraphe::GRALireSommet(int iIndice)
{
	// V�rification de l'indice en param�tre
	if (iIndice < 0 || iIndice > int(uiGRANbSommet))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	return *ppSOMGRAListeSommet[iIndice];
}

/******************************************************************************************************************************************************************/
//ATTENTION FAIRE GAFFE : MAYBE COMME SOMRAJOUTERARC FAUDRA METTRE DES POINTEURS SINON CA PEUT BUGUER?

/*********************************************************
Ajoute un sommet au graphe
*********************************************************
Entr�e: CSommet& SOMSommet : le sommet � rajouter dans le graphe
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	(SOMSommet a �t� rajouter � la fin de la liste des sommets) ou
(Exception echec_malloc lev�e)
*********************************************************/
void CGraphe::GRAAjouterSommet(CSommet& SOMSommet)
{
	if (GRARechercheIndiceSommet(SOMSommet.SOMLireNumeroSommet()) != -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_existant);
		EXCLevee.EXCmodifier_message("Le sommet est d�j� pr�sent dans la liste !");
		throw(EXCLevee);
	}

	// Reallocation de la liste de sommet du graphe
	ppSOMGRAListeSommet = (CSommet**) realloc(ppSOMGRAListeSommet, (uiGRANbSommet + 1) * sizeof(CSommet*));
	///Si l'allocation � r�ussi
	if (ppSOMGRAListeSommet != nullptr)
	{
		// Ajout du sommet dans la liste et mise � jour du nombre de sommet du graphe
		ppSOMGRAListeSommet[uiGRANbSommet] = new CSommet(SOMSommet);
		uiGRANbSommet++;
	}
	///Sinon on l�ve une exception
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
Entr�e: int iIndice : indice du sommet � modifier
		CSommet& SOMSommet : le nouveau sommet du graphe
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	(pSOMGRAListeSommet[iIndice - 1] = SOMSommet) ou
(Exception indice_incorrecte lev�e)
*********************************************************/
void CGraphe::GRAModifierSommet(int iNumeroSommet, CSommet& SOMSommet)
{
	int iIndiceSommet = GRARechercheIndiceSommet(iNumeroSommet);
	if (iIndiceSommet == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet n'est pas dans la liste !");
		throw(EXCLevee);
	}
	//ajouter/modifier
	ppSOMGRAListeSommet[iIndiceSommet] = new CSommet(SOMSommet);
}

/*********************************************************
Supprime le sommet d'indice iIndice
dans la liste des sommets du graphe
*********************************************************
Entr�e: int iIndice : indice du sommet � supprimer
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	(Le sommet d'indice iIndice a �t� supprimer) ou
(Exception indice_incorrecte lev�e) ou
(Exception liste_vide lev�e)  ou
(Exception echec_malloc lev�e)
*********************************************************/
void CGraphe::GRASupprimerSommet(int iNumeroSommet)
{
	// Si la liste est vide on l�ve une exception
	if (uiGRANbSommet == 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(liste_vide);
		EXCLevee.EXCmodifier_message("liste vide !");
		throw(EXCLevee);
	}

	int iIndiceSommet = GRARechercheIndiceSommet(iNumeroSommet);
	if (iIndiceSommet == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet n'est pas dans la liste !");
		throw(EXCLevee);
	}

	// On d�cale les sommets � partir du sommet � supprimer pour l'�craser
	for (unsigned int uiBoucle = iIndiceSommet; uiBoucle < uiGRANbSommet - 1; uiBoucle++)
	{
		ppSOMGRAListeSommet[uiBoucle] = ppSOMGRAListeSommet[uiBoucle + 1];
	}

	// Si il n'y avait qu'un seul sommet on d�salloue la liste
	if (uiGRANbSommet - 1 == 0)
	{
		free(ppSOMGRAListeSommet);
		ppSOMGRAListeSommet = nullptr;
	}
	// Sinon on r�alloue la liste avec la nouvelle taille
	else
	{
		ppSOMGRAListeSommet = (CSommet**)realloc(ppSOMGRAListeSommet, (uiGRANbSommet - 1) * sizeof(CSommet*));
		// Si l'allocation � r�ussi on met � jour le nombre de sommet
		if (ppSOMGRAListeSommet != nullptr)
		{
			uiGRANbSommet--;
		}
		// Sinon on l�ve une exception
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
Entr�e: int iNumeroSommetDepart : le numero du sommet de depart
		int iNumeroSommetDestination : le numero du sommet de destination
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	(deux arcs entre iNumeroSommetDepart et iNumeroSommetDestination ont �t� rajouter) ou
(Exception sommet_introuvable lev�e)
*********************************************************/
void CGraphe::GRAAjouterArc(int iNumeroSommetDepart, int iNumeroSommetDestination)
{
	// Recherche du sommet de d�part
	int uiIndiceSommetDepart = GRARechercheIndiceSommet(iNumeroSommetDepart);
	// Recherche du sommet de destination
	int uiIndiceSommetDestination = GRARechercheIndiceSommet(iNumeroSommetDestination);

	// Si le sommet de d�part n'est pas dans la liste on l�ve une exception 
	/// on rajoute un sommet?
	if (uiIndiceSommetDepart == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de d�part n'a pas �t� trouv� dans la liste !");
		throw EXCLevee;
	}

	// Si le sommet de destination n'est pas dans la liste on l�ve une exception 
	/// on rajoute un sommet?
	if (uiIndiceSommetDestination == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de destination n'a pas �t� trouv� dans la liste !");
		throw EXCLevee;
	}

	if (ppSOMGRAListeSommet[uiIndiceSommetDepart]->SOMRechercheIndiceArcSortant(iNumeroSommetDestination) == -1)
	{
		// Ajout d'un arc partant en destination de iNumeroSometDestination
		CArc* pARCArcPartant = new CArc(iNumeroSommetDestination);
		ppSOMGRAListeSommet[uiIndiceSommetDepart]->SOMAjouterArcSortant(pARCArcPartant);

		// Ajout d'un arc arrivant en destination de iNumeroSommetDepart
		CArc* pARCArcArrivant = new CArc(iNumeroSommetDepart);
		ppSOMGRAListeSommet[uiIndiceSommetDestination]->SOMAjouterArcArrivant(pARCArcArrivant);
	}
	else
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_existant);
		EXCLevee.EXCmodifier_message("Le sommet est d�j� pr�sent dans la liste !");
		throw(EXCLevee);
	}
}

/*********************************************************
Modifie l'arc allant de iAncienSommetDepart � iAncienSommetDestination
*********************************************************
Entr�e: int iAncienSommetDepart : le numero de l'ancien sommet de depart
		int iAncienSommetDestination : le numero de l'ancien sommet de destination
		int iNouveauSommetDepart : le numero du nouveau sommet de depart
		int iNouveauSommetDestination : le numero du nouveau sommet de destination
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	()
*********************************************************/
void CGraphe::GRAModifierArc(int iAncienSommetDepart, int iAncienSommetDestination, int iNouveauSommetDepart, int iNouveauSommetDestination)
{	
	try
	{
		GRASupprimerArc(iAncienSommetDepart, iAncienSommetDestination);
		GRAAjouterArc(iNouveauSommetDepart, iNouveauSommetDestination);
	}
	catch (CException EXCLevee)
	{
		std::cout << EXCLevee.EXClire_message() << std::endl;
	}
}

/*********************************************************
Supprime l'arc allant de iNumeroSommetDepart � iNumeroSommetDestination
*********************************************************
Entr�e: int iNumeroSommetDepart : le numero du sommet de depart
		int iNumeroSommetDestination : le numero du sommet de destination
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	()
*********************************************************/
void CGraphe::GRASupprimerArc(int iNumeroSommetDepart, int iNumeroSommetDestination)
{
	// Recherche du sommet de d�part
	int uiIndiceSommetDepart = GRARechercheIndiceSommet(iNumeroSommetDepart);
	// Recherche du sommet de destination
	int uiIndiceSommetDestination = GRARechercheIndiceSommet(iNumeroSommetDestination);

	// Si le sommet de d�part n'est pas dans la liste on l�ve une exception 
	/// on rajoute un sommet?
	if (uiIndiceSommetDepart == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de d�part n'a pas �t� trouv� dans la liste !");
		throw EXCLevee;
	}

	// Si le sommet de destination n'est pas dans la liste on l�ve une exception 
	/// on rajoute un sommet?
	if (uiIndiceSommetDestination == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de destination n'a pas �t� trouv� dans la liste !");
		throw EXCLevee;
	}

	// Si l'arc iNumeroSommetDepart -> iNumeroSommetDestination n'est pas pr�sent on l�ve une exception
	if (ppSOMGRAListeSommet[uiIndiceSommetDepart]->SOMRechercheIndiceArcSortant(iNumeroSommetDestination) == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("L'arc n'est pas dans la liste des sortants du sommet!");
		throw EXCLevee;
	}

	// Si l'arc iNumeroSommetDestination -> iNumeroSommetDepart n'est pas pr�sent on l�ve une exception
	if (ppSOMGRAListeSommet[uiIndiceSommetDestination]->SOMRechercheIndiceArcArrivant(iNumeroSommetDepart) == -1)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("L'arc n'est pas dans la liste des sortants du sommet!");
		throw EXCLevee;
	}

	// Suppression des arcs
	ppSOMGRAListeSommet[uiIndiceSommetDepart]->SOMSupprimerArcSortant(iNumeroSommetDestination);
	ppSOMGRAListeSommet[uiIndiceSommetDestination]->SOMSupprimerArcArrivant(iNumeroSommetDepart);
}

CGraphe& CGraphe::GRAInverseGraphe()
{
	CGraphe* pGRAGraphe = new CGraphe();

	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiGRANbSommet; uiBoucleSommet++)
	{
		pGRAGraphe->GRAAjouterSommet(ppSOMGRAListeSommet[uiBoucleSommet]->SOMInverserArrivantPartant());
	}

	return *pGRAGraphe;
}

/*********************************************************
Recherche si le sommet est pr�sent dans le graphe
*********************************************************/
int CGraphe::GRARechercheIndiceSommet(int iNumeroSommet)
{
	for (unsigned int uiIndiceBoucleSommet = 0; uiIndiceBoucleSommet < uiGRANbSommet; uiIndiceBoucleSommet++)
	{
		if (GRALireSommet(uiIndiceBoucleSommet).SOMLireNumeroSommet() == iNumeroSommet)
		{
			return uiIndiceBoucleSommet;
		}
	}
	return -1;
}

/*********************************************************
Affiche le graphe dans le console
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	()
*********************************************************/
void CGraphe::GRAAfficherGraphe()
{
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiGRANbSommet; uiBoucleSommet++)
	{
		std::cout << "*************************" << std::endl;
		std::cout << "    Sommet numero : " << ppSOMGRAListeSommet[uiBoucleSommet]->SOMLireNumeroSommet() << std::endl;
		std::cout << "Liste arcs arrivant : " << std::endl;
		for (unsigned int uiBoucleArcArrivant = 0; uiBoucleArcArrivant < ppSOMGRAListeSommet[uiBoucleSommet]->SOMLireNombreArcArrivant(); uiBoucleArcArrivant++)
		{
			std::cout << "Arc numero : " << uiBoucleArcArrivant << std::endl;
			std::cout << "	Destination : " << ppSOMGRAListeSommet[uiBoucleSommet]->SOMLireArcArrivant(uiBoucleArcArrivant)->ARCLireDestination() << std::endl;
		}
		std::cout << std::endl << "Liste arcs sortant : " << std::endl;
		for (unsigned int uiBoucleArcSortant = 0; uiBoucleArcSortant < ppSOMGRAListeSommet[uiBoucleSommet]->SOMLireNombreArcSortant(); uiBoucleArcSortant++)
		{
			std::cout << "Arc numero : " << uiBoucleArcSortant << std::endl;
			std::cout << "	Destination : " << ppSOMGRAListeSommet[uiBoucleSommet]->SOMLireArcSortant(uiBoucleArcSortant)->ARCLireDestination() << std::endl;
		}
		std::cout << "*************************" << std::endl << std::endl;
	}
}

/*********************************************************
Surcharge de l'op�rateur d'affectation pour la classe CGraphe
*********************************************************/
CGraphe& CGraphe::operator=(CGraphe& GRAGraphe)
{
	// Recopie du nombre de sommet
	uiGRANbSommet = GRAGraphe.uiGRANbSommet;

	// Allocation en m�moire de la lsite de sommet
	ppSOMGRAListeSommet = (CSommet**)malloc(uiGRANbSommet * sizeof(CSommet*));

	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommet; uiBoucle++)
	{
		// Copie des sommets 
		ppSOMGRAListeSommet[uiGRANbSommet] = new CSommet(*GRAGraphe.GRALireListeSommet()[uiBoucle]);
	}

	return *this;
}