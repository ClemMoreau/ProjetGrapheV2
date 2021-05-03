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
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommet; uiBoucle++)
	{
		(pGRAListeSommet + uiBoucle)->~CSommet();
	}

	//ou delete[] pGRAListeSommet;

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
	return *(pGRAListeSommet + iIndice);
}

void CGraphe::GRAAjouterSommet(CSommet& SOMSommet)
{
	CSommet* pSOMListeSommetTempo = new CSommet[uiGRANbSommet + 1];
	if (!pSOMListeSommetTempo)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(echec_malloc);
		EXCLevee.EXCmodifier_message("Echec realloc !");
		throw(EXCLevee);
	}

	if (pGRAListeSommet)
	{
		for (unsigned int iBoucle = 0; iBoucle < uiGRANbSommet + 1; iBoucle++)
		{
			*(pSOMListeSommetTempo + iBoucle) = *(pGRAListeSommet + iBoucle);
		}
		delete[] pGRAListeSommet;
	}
	pGRAListeSommet = pSOMListeSommetTempo;
	*(pGRAListeSommet + uiGRANbSommet) = SOMSommet;
	uiGRANbSommet++;
	pSOMListeSommetTempo = nullptr;
}

void CGraphe::GRAModifierSommet(int iIndice, CSommet SOMSommet)
{

}

void CGraphe::GRASupprimerSommet(int iIndice)
{

}

void CGraphe::GRAAjouterArc(int iNumeroSommetDepart, int iNumeroSommetDestination)
{

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