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
	uiGRANbSommet = GRAGraphe.uiGRANbSommet;

	pSOMGRAListeSommet = (CSommet*)malloc(uiGRANbSommet * sizeof(CSommet));

	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommet; uiBoucle++)
	{
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
	uiGRANbSommet = iNombreSommet;

	pSOMGRAListeSommet = (CSommet*)malloc(uiGRANbSommet * sizeof(CSommet));
}///peut être à suppr

CGraphe::~CGraphe()
{
	uiGRANbSommet = 0;

	free(pSOMGRAListeSommet);
}

/*********************************************************
Retourne la liste des sommets du graphe
*********************************************************/
unsigned int CGraphe::GRALireNombreSommet()
{
	return uiGRANbSommet;
}

CSommet* CGraphe::GRALireListeSommet()
{
	return pSOMGRAListeSommet;
}

CSommet CGraphe::GRALireSommet(int iIndice)
{
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
void CGraphe::GRAAjouterSommet(CSommet& SOMSommet)
{
	pSOMGRAListeSommet = (CSommet*) realloc(pSOMGRAListeSommet, (uiGRANbSommet + 1) * sizeof(CSommet));
	if (pSOMGRAListeSommet != nullptr)
	{
		pSOMGRAListeSommet[uiGRANbSommet] = SOMSommet;
		uiGRANbSommet++;
	}
	else
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}
}

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

void CGraphe::GRASupprimerSommet(int iIndice)
{
	if (uiGRANbSommet == 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(liste_vide);
		EXCLevee.EXCmodifier_message("liste vide !");
		throw(EXCLevee);
	}

	if (iIndice < 0 || iIndice > int(uiGRANbSommet))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}
	

	for (unsigned int uiBoucle = iIndice; uiBoucle <= uiGRANbSommet - 1; uiBoucle++)
	{
		pSOMGRAListeSommet[uiBoucle - 1] = pSOMGRAListeSommet[uiBoucle];
	}

	if (uiGRANbSommet - 1 == 0)
	{
		free(pSOMGRAListeSommet);
		pSOMGRAListeSommet = nullptr;
	}
	else
	{
		pSOMGRAListeSommet = (CSommet*)realloc(pSOMGRAListeSommet, (uiGRANbSommet - 1) * sizeof(CSommet));
		if (pSOMGRAListeSommet != nullptr)
		{
			uiGRANbSommet--;
		}
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
void CGraphe::GRAAjouterArc(int iNumeroSommetDepart, int iNumeroSommetDestination)
{
	bool bTestPresenceSommetDepart = false;
	bool bTestPresenceSommetDestination = false;
	unsigned int uiBoucle, uiIndiceSommetDepart, uiIndiceSommetDestination;

	for (uiBoucle = 0; uiBoucle < uiGRANbSommet; uiBoucle++)
	{
		if (pSOMGRAListeSommet[uiBoucle].SOMLireNumeroSommet() == iNumeroSommetDepart)
		{
			bTestPresenceSommetDepart = true;
			uiIndiceSommetDepart = uiBoucle;
		}

		if (pSOMGRAListeSommet[uiBoucle].SOMLireNumeroSommet() == iNumeroSommetDestination)
		{
			bTestPresenceSommetDestination = true;
			uiIndiceSommetDestination = uiBoucle;
		}
	}

	if (bTestPresenceSommetDepart == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de départ n'a pas été trouvé dans la liste !");
		throw EXCLevee;
	}

	if (bTestPresenceSommetDestination == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de destination n'a pas été trouvé dans la liste !");
		throw EXCLevee;
	}

	//ajout partant en destination de iNumeroSometDestination
	CArc* pARCArcPartant = new CArc(iNumeroSommetDestination);
	pSOMGRAListeSommet[uiIndiceSommetDepart].SOMAjouterArcSortant(pARCArcPartant);

	//ajout arrivant en destination de iNumeroSommetDepart
	CArc* pARCArcArrivant = new CArc(iNumeroSommetDepart);
	pSOMGRAListeSommet[uiIndiceSommetDestination].SOMAjouterArcArrivant(pARCArcArrivant);
}

//mettre des try catchs
void CGraphe::GRAModifierArc(int iAncienSommetDepart, int iAncienSommetDestination, int iNouveauSommetDepart, int iNouveauSommetDestination)
{	
	GRASupprimerArc(iAncienSommetDepart, iAncienSommetDestination);
	GRAAjouterArc(iNouveauSommetDepart, iNouveauSommetDestination);
}

void CGraphe::GRASupprimerArc(int iNumeroSommetDepart, int iNumeroSommetDestination)
{
	bool bTestPresenceSommetDepart = false;
	bool bTestPresenceSommetDestination = false;
	unsigned int uiBoucleSommet, uiIndiceSommetDepart, uiIndiceSommetDestination;

	for (uiBoucleSommet = 0; uiBoucleSommet < uiGRANbSommet || bTestPresenceSommetDepart == false; uiBoucleSommet++)
	{
		if (int(pSOMGRAListeSommet[uiBoucleSommet].SOMLireNumeroSommet()) == iNumeroSommetDepart)
		{
			bTestPresenceSommetDepart = true;
			uiIndiceSommetDepart = uiBoucleSommet;
		}
		if (int(pSOMGRAListeSommet[uiBoucleSommet].SOMLireNumeroSommet()) == iNumeroSommetDestination)
		{
			bTestPresenceSommetDestination = true;
			uiIndiceSommetDestination = uiBoucleSommet;
		}
	}

	if (bTestPresenceSommetDepart == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de départ n'est pas dans la liste !");
		throw EXCLevee;
	}

	if (bTestPresenceSommetDestination == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet de destination n'est pas dans la liste !");
		throw EXCLevee;
	}

	bool bTestPresenceArcSortant = false;
	unsigned int uiBoucleArc, uiIndiceArcSortant, uiIndiceArcArrivant;

	for (uiBoucleArc = 1; uiBoucleArc <= pSOMGRAListeSommet[uiIndiceSommetDepart].SOMLireNombreArcSortant() || bTestPresenceArcSortant == false; uiBoucleArc++)
	{
		if (pSOMGRAListeSommet[uiIndiceSommetDepart].SOMLireArcSortant(uiBoucleArc)->ARCLireDestination() == iNumeroSommetDestination)
		{
			bTestPresenceArcSortant = true;
			uiIndiceArcSortant = uiBoucleArc;
		}
	}

	bool bTestPresenceArcArrivant = false;
	for (uiBoucleArc = 1; uiBoucleArc <= pSOMGRAListeSommet[uiIndiceSommetDestination].SOMLireNombreArcArrivant() || bTestPresenceArcArrivant == false; uiBoucleArc++)
	{
		if (pSOMGRAListeSommet[uiIndiceSommetDestination].SOMLireArcArrivant(uiBoucleArc)->ARCLireDestination() == iNumeroSommetDepart)
		{
			bTestPresenceArcArrivant = true;
			uiIndiceArcArrivant = uiBoucleArc;
		}
	}

	if (bTestPresenceArcSortant == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("L'arc n'est pas dans la liste des sortants du sommet!");
		throw EXCLevee;
	}

	if (bTestPresenceArcArrivant == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("L'arc n'est pas dans la liste des sortants du sommet!");
		throw EXCLevee;
	}

	pSOMGRAListeSommet[uiIndiceSommetDepart].SOMSupprimerArcSortant(uiIndiceArcSortant);
	pSOMGRAListeSommet[uiIndiceSommetDestination].SOMSupprimerArcArrivant(uiIndiceArcArrivant);
}

CGraphe CGraphe::GRAInverseGraphe()
{
	CGraphe GRAGraphe;
	return GRAGraphe;
}

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