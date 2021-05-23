#ifndef GRA
#define GRA 0
#include "CSommet.h"

#define sommet_introuvable 401
#define sommet_existant 402


class CGraphe {

private:

			/*************
			 * ATTRIBUTS *
			 *************/
	/*Nombre de sommet dans le graphe*/
	unsigned int uiGRANbSommet;

	/*Liste des sommets du graphe*/
	CSommet* pSOMGRAListeSommet;

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
	 Retourne le nombre de sommets du graphe
	 *********************************************************/
	unsigned int GRALireNombreSommet();

	/*********************************************************
	 Retourne la liste des sommets du graphe
	 *********************************************************/
	CSommet* GRALireListeSommet(); ///surêment a retirer

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
	 Modifie le sommet numero iNumeroSommet 
	 dans la liste des sommets du graphe
	 *********************************************************/
	void GRAModifierSommet(int iNumeroSommet, CSommet& SOMSommet);

	/*********************************************************
	 Supprime le sommet numero iNumeroSommet
	 dans la liste des sommets du graphe
	 *********************************************************/
	void GRASupprimerSommet(int iNumeroSommet);

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

	/*********************************************************
	Recherche si le sommet est présent dans le graphe
	*********************************************************/
	int GRARechercheIndiceSommet(int iNumeroSommet);
					/**************
					 * SURCHARGES *
					 **************/
	/*********************************************************
	Surcharge de l'opérateur d'affectation pour la classe CGraphe
	*********************************************************/
	CGraphe& operator=(CGraphe& GRAGraphe);
};
#endif //GRA

