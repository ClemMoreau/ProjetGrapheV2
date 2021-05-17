#include "CFichier.h"
#include <iostream>

/*********************************************************
Constructeur par d�faut de la classe CFichier
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec psNomdeFichier = NULL
*********************************************************/
CFichier::CFichier()
{
	FICModifierNomFichier(NULL);
}

/*********************************************************
Constructeur de recopie de la classe CFichier
prenant en param�tre un CFichier
*********************************************************
Entr�e: CFichier &FICFichier : L 'objet fichier � recopier
N�cessite:	CFichier &FICFichier doit �tre initialis�
Sortie: (rien)
Entra�ne :	Modification du nom du fichier
*********************************************************/
CFichier::CFichier(CFichier &FICFichier)
{
	FICModifierNomFichier(FICFichier.FICLireNomFichier());
}

/*********************************************************
Destructeur de la classe CFichier
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est pr�t � �tre d�truit
*********************************************************/
CFichier::~CFichier()
{
	free(psFICNomFichier);
}

/*********************************************************
Renvoie le nom du fichier
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: psFICNomFichier : le nom du fichier
Entra�ne :	(rien)
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
Modifie le nom du fichier si d�ja existant
*********************************************************
Entr�e: const char* sNomFichier : le nouveau nom de notre fichier
N�cessite:	(sNomFichier ne doit pas contenir d'espace)
Sortie: (rien)
Entra�ne : Entraine "lib�ration" de psFICNomFichier
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
Entr�e: (rien)
N�cessite:	(psFICNomFichier != NULL)
Sortie: CGraphe : le graphe lu dans le fichier
Entra�ne : R�cup�ration des informations du fichier, cr�ation du graphe 
rempli avec le contenu du fichier
*********************************************************/
CGraphe CFichier::FICLireFichier()
{
	/*
	// Ouverture du fichier
	ifstream fFichier(FICLireNomFichier());
	if (!fFichier)
	{
		//On teste si l'ouverture c'est bien d�roul�
		CException EXCFichier;
		EXCFichier.EXCmodifier_valeur(ouverture_fichier_impossible);
		throw(EXCFichier);
	}

	//cdelim est notre s�parateur, Utilis� pour la fonction strtok_s() 	   
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