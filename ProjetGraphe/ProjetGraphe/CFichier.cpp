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
CGraphe CFichier::FICLireFichier()
{
	/*
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

	char *pcNbSommet,*pcNbArc;

	char *pcElementsuivS = NULL, *pcElementsuivA = NULL;

	fFichier >> cNbSommet;
	fFichier >> cNbArc;
	fFichier >> cIgnore;

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

	char cSommet[100];
	char *pctempNumeroSommet;
	char *pcNumeroSommet;
	char *pcElementsuivN;
	unsigned int uiNbSommet = atoi(pcNbSommet);
	unsigned int uiNbArc = atoi(pcNbArc);
	unsigned int uiNumeroSommet;
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiNbSommet; ++uiBoucleSommet)
	{
		fFichier >> cSommet;
		
		char *pctempNumeroSommet = strtok_s(cSommet, cdelim, &pcElementsuivN);

		while (pctempNumeroSommet != NULL)
		{
			pcNumeroSommet = pctempNumeroSommet;
			pctempNumeroSommet = strtok_s(NULL, cdelim, &pcElementsuivN);
		}
		uiNumeroSommet = atoi(pcNumeroSommet);
		CSommet SOMSommet(uiNumeroSommet);
	}
	for (unsigned int uiBoucleArc = 0; uiBoucleArc < uiNbArc; ++uiBoucleArc)
	{

	}
	*/
	CGraphe GRAGraphe;
	return GRAGraphe;
}