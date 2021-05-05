#ifndef GRA
#define GRA 0
#include "CSommet.h"

#define sommet_introuvable 401
#define arc_introuvable 402

class CGraphe {

private:

			/*************
			 * ATTRIBUTS *
			 *************/
	/*Nombre de sommet dans le graphe*/
	unsigned int uiGRANbSommet;

	/*Liste des sommets du graphe*/
	CSommet* pGRAListeSommet;

public :

			/*****************
			 * CONSTRUCTEURS *
			 *****************/

	/*********************************************************
	Constructeur par défaut de la classe CGraphe
	*********************************************************/
	CGraphe();

	/*********************************************************
	Constructeur de recopie de la classe CGraphe
	prenant en paramètre un CGraphe
	*********************************************************/
	CGraphe(CGraphe& GRAGraphe);

	/*********************************************************
	Constructeur de la classe CGraphe
	prenant en paramètre un entier
	*********************************************************/
	CGraphe(int iNombreSommet);

			/***************
			 * DESTRUCTEUR *
			 ***************/

	/*********************************************************
	Destructeur de la classe CFichier
	*********************************************************/
	~CGraphe();

			/***********
			 * GETTERS *
			 ***********/

	/*********************************************************
	Retourne la liste des sommets du graphe
	*********************************************************/
	unsigned int GRALireNombreSommet();

	/*********************************************************
	 Retourne la liste des sommets du graphe
	 *********************************************************/
	CSommet* GRALireListeSommet();

	/*********************************************************
	 Retourne le sommet d'indice iIndice 
	 dans la liste des sommets du graphe
	 *********************************************************/
	CSommet GRALireSommet(int iIndice);

			/***********
			 * SETTERS *
			 ***********/

	/*********************************************************
	 Ajoute un sommet au graphe
	 *********************************************************/
	void GRAAjouterSommet(CSommet& SOMSommet);

	/*********************************************************
	 Modifie le sommet d'indice iIndice 
	 dans la liste des sommets du graphe
	 *********************************************************/
	void GRAModifierSommet(int iIndice, CSommet SOMSommet);

	/*********************************************************
	 Supprime le sommet d'indice iIndice
	 dans la liste des sommets du graphe
	 *********************************************************/
	void GRASupprimerSommet(int iIndice);

	/*********************************************************
	 Ajoute un arc au graphe 
	 entre les sommets iNumeroSommetDepart et iNumeroSommetDestination
	 *********************************************************/
	void GRAAjouterArc(int iNumeroSommetDepart, int iNumeroSommetDestination);

	/*********************************************************
	 Modifie l'arc allant de iAncienSommetDepart à iAncienSommetDestination
	*********************************************************/
	void GRAModifierArc(int iAncienSommetDepart, int iAncienSommetDestination, int iNouveauSommetDepart, int iNouveauSommetDestination);

	/*********************************************************
	 Supprime l'arc allant de iNumeroSommetDepart à iNumeroSommetDestination
	 *********************************************************/
	void GRASupprimerArc(int iNumeroSommetDepart, int iNumeroSommetDestination);

			/************
			 * METHODES *
			 ************/

	/*********************************************************
	Inverse l'orientation de tous les arcs de chaque sommets du graphe
	*********************************************************/
	CGraphe GRAInverseGraphe();

	/*********************************************************
	Affiche le graphe dans le console
	*********************************************************/
	void GRAAfficherGraphe();
};
#endif //GRA

