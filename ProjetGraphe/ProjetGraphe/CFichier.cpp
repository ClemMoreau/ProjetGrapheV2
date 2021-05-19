#include "CFichier.h"
#include <iostream>

/*********************************************************
Constructeur par défaut de la classe CFichier
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec psNomdeFichier = NULL
*********************************************************/
CFichier::CFichier()
{
	FICModifierNomFichier(NULL);
}

/*********************************************************
Constructeur de recopie de la classe CFichier
prenant en paramètre un CFichier
*********************************************************
Entrée: CFichier &FICFichier : L 'objet fichier à recopier
Nécessite:	CFichier &FICFichier doit être initialisé
Sortie: (rien)
Entraîne :	Modification du nom du fichier
*********************************************************/
CFichier::CFichier(CFichier &FICFichier)
{
	FICModifierNomFichier(FICFichier.FICLireNomFichier());
}

/*********************************************************
Destructeur de la classe CFichier
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est prêt à être détruit
*********************************************************/
CFichier::~CFichier()
{
	free(psFICNomFichier);
}

/*********************************************************
Renvoie le nom du fichier
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: psFICNomFichier : le nom du fichier
Entraîne :	(rien)
*********************************************************/
char* CFichier::FICLireNomFichier()
{
	if (psFICNomFichier == NULL)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(nom_null);
		throw(EXCObjet);

	}
	return psFICNomFichier;
}

/*********************************************************
Modifie le nom du fichier si déja existant
*********************************************************
Entrée: const char* sNomFichier : le nouveau nom de notre fichier
Nécessite:	(sNomFichier ne doit pas contenir d'espace)
Sortie: (rien)
Entraîne : Entraine "libération" de psFICNomFichier
et psFICNomFichier = sNomFichier
*********************************************************/
void CFichier::FICModifierNomFichier(const char* sNomFichier)
{
	if (sNomFichier)
	{
		if (psFICNomFichier)
		{
			free(psFICNomFichier);
		}

		int iConteur = strlen(sNomFichier);
		psFICNomFichier = (char*)malloc(iConteur + 1);
		int iBoucleCopie;
		for (iBoucleCopie = 0; iBoucleCopie < iConteur; iBoucleCopie++)
		{
			psFICNomFichier[iBoucleCopie] = sNomFichier[iBoucleCopie];
		}
		psFICNomFichier[iBoucleCopie] = '\0';
	}
	else
	{
		psFICNomFichier = NULL;
	}
}


/*********************************************************
Lecture du fichier et extraction des informations dans le fichier
*********************************************************
Entrée: (rien)
Nécessite:	(psFICNomFichier != NULL)
Sortie: CGraphe : le graphe lu dans le fichier
Entraîne : Récupération des informations du fichier, création du graphe 
rempli avec le contenu du fichier
*********************************************************/
CGraphe& CFichier::FICLireFichier()
{
	CGraphe* pGRAGraphe = new CGraphe();
	// Ouverture du fichier
	ifstream fFichier(FICLireNomFichier());
	if (!fFichier)
	{
		//On teste si l'ouverture c'est bien déroulé
		CException EXCFichier;
		EXCFichier.EXCmodifier_valeur(ouverture_fichier_impossible);
		throw(EXCFichier);
	}

	//cdelim est notre séparateur, Utilisé pour la fonction strtok_s() 	   
	char cdelim[] = "=";

	char cNbSommet[100], cNbArc[100], cIgnore[200];

	char *pcNbSommet = NULL,*pcNbArc = NULL;

	char *pcElementsuivS = NULL, *pcElementsuivA = NULL;

	fFichier >> cNbSommet;
	fFichier >> cNbArc;
	

	char *pctempNbSommet = strtok_s(cNbSommet, cdelim, &pcElementsuivS);
	char *pctempNbArc = strtok_s(cNbArc, cdelim, &pcElementsuivA);

	while (pctempNbSommet != NULL)
	{
		if (pctempNbSommet != NULL)
		{
			pcNbSommet = pctempNbSommet;
			
			pctempNbSommet = strtok_s(NULL, cdelim, &pcElementsuivS);
		}
		if (pctempNbArc != NULL)
		{
			pcNbArc = pctempNbArc;
			
			pctempNbArc = strtok_s(NULL, cdelim, &pcElementsuivA);
		}
	}
	//cout << "NBSommet : " << pcNbSommet << endl;
	//cout << "NbArc : " << pcNbArc << endl;
	fFichier >> cIgnore;
	char cSommet[100];
	char *pctempNumeroSommet;
	char *pcNumeroSommet = NULL;
	char *pcElementsuivN = NULL;
	unsigned int uiNbSommet = atoi(pcNbSommet);
	unsigned int uiNbArc = atoi(pcNbArc);
	unsigned int uiNumeroSommet;
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiNbSommet; ++uiBoucleSommet)
	{
		fFichier >> cSommet;
		
		pctempNumeroSommet = strtok_s(cSommet, cdelim, &pcElementsuivN);

		while (pctempNumeroSommet != NULL)
		{
			pcNumeroSommet = pctempNumeroSommet;
			pctempNumeroSommet = strtok_s(NULL, cdelim, &pcElementsuivN);
		}
		//cout << "Sommet numéro : "<<pcNumeroSommet;
		uiNumeroSommet = atoi(pcNumeroSommet);
		CSommet *pSOMSommet = new CSommet(uiNumeroSommet);
		pGRAGraphe->GRAAjouterSommet(*pSOMSommet);
		//GRAGraphe.GRAAjouterSommet(SOMSommet);

	}
	fFichier >> cIgnore;
	fFichier >> cIgnore;

	char cArc[100];
	char *pctempArcSortant;
	char *pctempArcEntrant;
	char *pcArcSortant = NULL;
	char *pcArcEntrant = NULL;
	//char *pcElementsuivA;
	unsigned int uiArcSortant;
	unsigned int uiArcEntrant;

	char cdelim2[] = ",";
	for (unsigned int uiBoucleArc = 0; uiBoucleArc < uiNbArc; ++uiBoucleArc)
	{
		fFichier >> cArc;
		//cout << cArc << endl;
		pctempArcSortant = strtok_s(cArc, cdelim2, &pcElementsuivA);
		//cout << cArc << endl;
		pctempArcSortant = strtok_s(cArc, cdelim, &pcElementsuivA);
		//cout << cArc <<endl;
		
		while (pctempArcSortant != NULL)
		{
			pcArcSortant = pctempArcSortant;
			pctempArcSortant = strtok_s(NULL, cdelim, &pcElementsuivA);
		}
		//cout << "arc sortant : " << pcArcSortant << endl;
		uiArcSortant = atoi(pcArcSortant);

		fFichier >> cArc;
		//cout << cArc << endl;
		pctempArcEntrant = strtok_s(cArc, cdelim, &pcElementsuivA);

		while (pctempArcEntrant != NULL)
		{
			pcArcEntrant = pctempArcEntrant;
			pctempArcEntrant = strtok_s(NULL, cdelim, &pcElementsuivA);
		}
		//cout << "arc entrant : " << pcArcEntrant << endl;
		uiArcEntrant = atoi(pcArcEntrant);

		pGRAGraphe->GRAAjouterArc(uiArcSortant, uiArcEntrant);
		//GRAGraphe.GRAAjouterArc(uiArcSortant, uiArcEntrant);

	}
	//GRAGraphe.GRAAfficherGraphe();
	
	return *pGRAGraphe;
}