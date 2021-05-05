#include "CGraphe.h"

/*********************************************************
Constructeur par défaut de la classe CGraphe
*********************************************************
Entrée:(rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	(L'objet est initialisé avec 
uiGRANbSommet = 0 et pGRAListeSommet = nullptr)
*********************************************************/
CGraphe::CGraphe()
{
	// Initialisation des attributs
	uiGRANbSommet = 0;
	pGRAListeSommet = nullptr;
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
et pGRAListeSommet = GRAGraphe.pGRAListeSommet)
*********************************************************/
CGraphe::CGraphe(CGraphe& GRAGraphe)
{
	uiGRANbSommet = GRAGraphe.uiGRANbSommet;

	pGRAListeSommet = new CSommet[uiGRANbSommet];

	for (unsigned int iBoucle = 0; iBoucle < uiGRANbSommet; iBoucle++)
	{
		pGRAListeSommet[uiGRANbSommet] = GRAGraphe.pGRAListeSommet[uiGRANbSommet];
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
et pGRAListeSommet = GRAGraphe.pGRAListeSommet)
*********************************************************/
CGraphe::CGraphe(int iNombreSommet)
{
	uiGRANbSommet = iNombreSommet;

	pGRAListeSommet = new CSommet[uiGRANbSommet];
}///peut être à suppr

CGraphe::~CGraphe()
{
	uiGRANbSommet = 0;

	delete[] pGRAListeSommet;
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
	return pGRAListeSommet;
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

	return pGRAListeSommet[iIndice];
}

//ATTENTION FAIRE GAFFE : MAYBE COMME SOMRAJOUTERARC FAUDRA METTRE DES POINTEURS SINON CA PEUT BUGUER?
void CGraphe::GRAAjouterSommet(CSommet& SOMSommet)
{
	CSommet* pSOMListeSommetTempo = new CSommet[uiGRANbSommet + 1];
	if (pSOMListeSommetTempo == nullptr)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}

	if (pGRAListeSommet != nullptr)
	{
		for (unsigned int iBoucle = 0; iBoucle < uiGRANbSommet + 1; iBoucle++)
		{
			pSOMListeSommetTempo[iBoucle] = pGRAListeSommet[iBoucle];
		}
		delete[] pGRAListeSommet;
	}
	pGRAListeSommet = pSOMListeSommetTempo;
	pGRAListeSommet[uiGRANbSommet] = SOMSommet;
	uiGRANbSommet++;
	pSOMListeSommetTempo = nullptr;
}

void CGraphe::GRAModifierSommet(int iIndice, CSommet SOMSommet)
{
	if (iIndice < 0 || iIndice > int(uiGRANbSommet))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(indice_incorrecte);
		EXCLevee.EXCmodifier_message("Indice hors du tableau !");
		throw(EXCLevee);
	}

	pGRAListeSommet[iIndice] = SOMSommet;
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

	CSommet* pSOMListeSommetTempo = new CSommet[uiGRANbSommet - 1];

	for (unsigned int iBoucle = 0; iBoucle < uiGRANbSommet - 1; iBoucle++)
	{
		if (iBoucle != iIndice)
		{
			pSOMListeSommetTempo[iBoucle] = pGRAListeSommet[iBoucle + 1];
		}
	}
	delete[] pGRAListeSommet;
	pGRAListeSommet = pSOMListeSommetTempo;
	pSOMListeSommetTempo = nullptr;
	
}

//revoir les cas particuliers
void CGraphe::GRAAjouterArc(int iNumeroSommetDepart, int iNumeroSommetDestination)
{
	bool bTestPresenceSommetDepart = false;
	bool bTestPresenceSommetDestination = false;
	unsigned int iBoucle, iIndiceSommetDepart, uiIndiceSommetDestination;

	for (iBoucle = 0; iBoucle < uiGRANbSommet || bTestPresenceSommetDepart == false; iBoucle++)
	{
		if (pGRAListeSommet[iBoucle].SOMLireNumeroSommet() == iNumeroSommetDepart)
		{
			bTestPresenceSommetDepart = true;
			iIndiceSommetDepart = iBoucle;
		}

		if (pGRAListeSommet[iBoucle].SOMLireNumeroSommet() == iNumeroSommetDestination)
		{
			bTestPresenceSommetDestination = true;
			uiIndiceSommetDestination = iBoucle;
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

	CArc* pARCarcAjout = new CArc(iNumeroSommetDestination);
	pGRAListeSommet[iIndiceSommetDepart].SOMAjouterArcSortant(pARCarcAjout);
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
		if (int(pGRAListeSommet[uiBoucleSommet].SOMLireNumeroSommet()) == iNumeroSommetDepart)
		{
			bTestPresenceSommetDepart = true;
			uiIndiceSommetDepart = uiBoucleSommet;
		}
		if (int(pGRAListeSommet[uiBoucleSommet].SOMLireNumeroSommet()) == iNumeroSommetDestination)
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

	bool bTestPresenceArc = false;
	unsigned int uiBoucleArc, uiIndiceArc;

	for (uiBoucleArc = 1; uiBoucleArc <= pGRAListeSommet[uiIndiceSommetDepart].SOMLireNombreArcSortant() || bTestPresenceArc == false; uiBoucleArc++)
	{
		if (pGRAListeSommet[uiIndiceSommetDepart].SOMLireArcSortant(uiBoucleArc)->ARCLireDestination() == iNumeroSommetDestination)
		{
			bTestPresenceArc = true;
			uiIndiceArc = uiBoucleArc;
		}
	}

	if (bTestPresenceArc == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(arc_introuvable);
		EXCLevee.EXCmodifier_message("L'arc n'est pas dans la liste des sortants du sommet!");
		throw EXCLevee;
	}

	pGRAListeSommet[uiIndiceSommetDepart].SOMSupprimerArcArrivant(uiIndiceArc);
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
		std::cout << "    Sommet numero : " << pGRAListeSommet[uiBoucleSommet].SOMLireNumeroSommet() << std::endl;
		std::cout << "Liste arcs arrivant : " << std::endl;
		for (unsigned int uiBoucleArcArrivant = 1; uiBoucleArcArrivant <= pGRAListeSommet[uiBoucleSommet].SOMLireNombreArcArrivant(); uiBoucleArcArrivant++)
		{
			std::cout << "Arc numero : " << uiBoucleArcArrivant << std::endl;
			std::cout << "	Destination : " << pGRAListeSommet[uiBoucleSommet].SOMLireArcArrivant(uiBoucleArcArrivant)->ARCLireDestination() << std::endl;
		}
		std::cout << std::endl << "Liste arcs sortant : " << std::endl;
		for (unsigned int uiBoucleArcSortant = 1; uiBoucleArcSortant <= pGRAListeSommet[uiBoucleSommet].SOMLireNombreArcArrivant(); uiBoucleArcSortant++)
		{
			std::cout << "Arc numero : " << uiBoucleArcSortant << std::endl;
			std::cout << "	Destination : " << pGRAListeSommet[uiBoucleSommet].SOMLireArcArrivant(uiBoucleArcSortant)->ARCLireDestination() << std::endl;
		}
		std::cout << "*************************" << std::endl << std::endl;
	}
}