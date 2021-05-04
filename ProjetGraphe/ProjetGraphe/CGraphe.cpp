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

void CGraphe::GRAAjouterArcArrivant(int iNumeroSommetDepart, int iNumeroSommetDestination)
{
	bool bTestPresenceSommet = false;
	unsigned int iBoucle;

	for (iBoucle = 0; iBoucle < uiGRANbSommet || bTestPresenceSommet == false; iBoucle++)
	{
		if (pGRAListeSommet[iBoucle].SOMLireNumeroSommet() == iNumeroSommetDepart)
		{
			bTestPresenceSommet = true;
		}
	}

	if (bTestPresenceSommet == false)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(sommet_introuvable);
		EXCLevee.EXCmodifier_message("Le sommet n'a pas été trouvé dans la liste !");
		throw EXCLevee;
	}

	CArc* pARCarcAjout = new CArc(iNumeroSommetDestination);
	pGRAListeSommet[iBoucle - 1].SOMAjouterArcArrivant(pARCarcAjout);
}

void CGraphe::GRAModifierArc(int iAncienSommetDepart, int iAncienSommetDestination, int iNouveauSommetDepart, int iNouveauSommetDestination)
{

}

void CGraphe::GRASupprimerArc(int iNumeroSommetDepart, int iNumeroSommetDestination)
{

}

CGraphe CGraphe::GRAInverseGraphe()
{
	CGraphe GRAGraphe;
	return GRAGraphe;
}

void CGraphe::GRAAfficherGraphe()
{

}