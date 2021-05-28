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
CGraphe& CFichier::FICLireFichier()
{
	CGraphe* pGRAGraphe = new CGraphe();
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

	char *pcNbSommet = NULL,*pcNbArc = NULL;

	char *pcElementsuivS = NULL, *pcElementsuivA = NULL;

	//R�cup�ration des 2 premi�re lignes du fichier
	fFichier >> cNbSommet;
	fFichier >> cNbArc;
	

	char *pctempNbSommet = strtok_s(cNbSommet, cdelim, &pcElementsuivS);
	char *pctempNbArc = strtok_s(cNbArc, cdelim, &pcElementsuivA);

	//on parcours ces lignes pour r�cup�rer le nombre de sommet et d'arc
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
	
	//On ingore cette ligne du fichier
	fFichier >> cIgnore;

	char cSommet[100];
	char *pctempNumeroSommet;
	char *pcNumeroSommet = NULL;
	char *pcElementsuivN = NULL;

	//Conversion en unsigned int pour les it�rations de la boucle 
	unsigned int uiNbSommet = atoi(pcNbSommet);
	unsigned int uiNbArc = atoi(pcNbArc);
	
	unsigned int uiNumeroSommet;
	/*
	 Dans cette boucle, on parcours les lignes contenant les sommet
	 S�pararation des cha�nes de caract�re au niveau du "="
	 Convertion en int du num�ro du sommet
	 Cr�ation d'un nouveau sommet
	 Ajout au graphe
	*/
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiNbSommet; ++uiBoucleSommet)
	{
		fFichier >> cSommet;
		
		pctempNumeroSommet = strtok_s(cSommet, cdelim, &pcElementsuivN);

		while (pctempNumeroSommet != NULL)
		{
			pcNumeroSommet = pctempNumeroSommet;
			pctempNumeroSommet = strtok_s(NULL, cdelim, &pcElementsuivN);
		}

		uiNumeroSommet = atoi(pcNumeroSommet);
		CSommet *pSOMSommet = new CSommet(uiNumeroSommet);
		pGRAGraphe->GRAAjouterSommet(*pSOMSommet);
	}
	fFichier >> cIgnore;
	fFichier >> cIgnore;

	//initilaisation des variables pour la boucle r�cup�rant les donn�es sur les arcs
	char cArc[100];
	char *pctempArcSortant;
	char *pctempArcEntrant;
	char *pcArcSortant = NULL;
	char *pcArcEntrant = NULL;
	unsigned int uiArcSortant;
	unsigned int uiArcEntrant;

	//cr�ation du d�limiteur ","
	char cdelim2[] = ",";

	/*
	Dans cette boucle,
	Le flux >> s�pare au niveau des espace, donc on r�cup�re "Debut=?,"
	S�paration au niveau de la virgule puis au niveau du "="
	Convertion en int de la valeur de l'arc sortant
	R�cup�ration du reste de la ligne
	S�paration au niveau du "="
	Convertion en int de la valeur de l'arc entrant
	Utilisation de la fonction GRAAjouterArc(uiArcSortant, uiArcEntrant) qui 
	cr�� des arcs et les ajoute au graphe
	*/
	for (unsigned int uiBoucleArc = 0; uiBoucleArc < uiNbArc; ++uiBoucleArc)
	{
		fFichier >> cArc;

		pctempArcSortant = strtok_s(cArc, cdelim2, &pcElementsuivA);
		pctempArcSortant = strtok_s(cArc, cdelim, &pcElementsuivA);
		
		while (pctempArcSortant != NULL)
		{
			pcArcSortant = pctempArcSortant;
			pctempArcSortant = strtok_s(NULL, cdelim, &pcElementsuivA);
		}
		
		uiArcSortant = atoi(pcArcSortant);

		fFichier >> cArc;
		
		pctempArcEntrant = strtok_s(cArc, cdelim, &pcElementsuivA);

		while (pctempArcEntrant != NULL)
		{
			pcArcEntrant = pctempArcEntrant;
			pctempArcEntrant = strtok_s(NULL, cdelim, &pcElementsuivA);
		}
		
		uiArcEntrant = atoi(pcArcEntrant);

		pGRAGraphe->GRAAjouterArc(uiArcSortant, uiArcEntrant);
	}
	return *pGRAGraphe;
}