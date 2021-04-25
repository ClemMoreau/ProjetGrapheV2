#include "CGraphe.h"

CGraphe::CGraphe()
{

}

CGraphe::CGraphe(CGraphe& GRAGraphe)
{

}

CGraphe::~CGraphe()
{

}

CSommet* CGraphe::GRALireListeSommet()
{
	CSommet* SOMSommet = new CSommet;
	return SOMSommet;
}

CSommet CGraphe::GRALireSommet(int iIndice)
{
	CSommet SOMSommet;
	return SOMSommet;
}

void CGraphe::GRAAjouterSommet(CSommet SOMSommet)
{

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