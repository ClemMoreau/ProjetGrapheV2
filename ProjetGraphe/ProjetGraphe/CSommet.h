#ifndef  SOM
#define SOM 0
#include "CArc.h"

class CSommet {

private:
			/*************
			 * ATTRIBUTS *
			 *************/

	/*Numero du sommet*/
	unsigned int uiSOMNumero;

	/*Liste des arcs arrivant au sommet*/
	CArc** ppARCSOMArcArrivant;

	/*Liste des arcs sortant au sommet*/
	CArc** ppARCSOMArcSortant;

public:

			/*****************
			 * CONSTRUCTEURS *
			 *****************/
	
	/*********************************************************
	Constructeur par défaut de la classe CSommet
	*********************************************************/
	CSommet();

	/*********************************************************
	Constructeur de recopie de la classe CSommet
	prenant en paramètre un CSommet
	*********************************************************/
	CSommet(CSommet& SOMSommet);

			/***************
			 * DESTRUCTEUR *
			 ***************/

	/*********************************************************
	Destructeur de la classe CFichier
	*********************************************************/
	~CSommet();

			/***********
			 * GETTERS *
			 ***********/

	/*********************************************************
	Retourne le numero du sommet
	*********************************************************/
	unsigned int SOMLireNumeroSommet();

	/*********************************************************
	Retourne l'arc arrivant à l'indice iIndice 
	du tableau des arcs arrivant
	*********************************************************/
	CArc* SOMLireArcArrivant(int iIndice);

	/*********************************************************
	Retourne l'arc sortant à l'indice iIndice
	du tableau des arcs sortant
	*********************************************************/
	CArc* SOMLireArcSortant(int iIndice);

			/***********
			 * SETTERS *
			 ***********/

	/*********************************************************
	Modifie le numero du sommet
	*********************************************************/
	void SOMModifierNumeroSommet(int iNumero);

	/*********************************************************
	Ajoute un arc dans la liste des arcs arrivants
	*********************************************************/
	void SOMAjouterArcArrivant(CArc* pARCArc);

	/*********************************************************
	Modifie l'arc à l'indice iIndice dans la liste des arcs arrivants
	*********************************************************/
	void SOMModifierArcArrivant(int iIndice, int iDestination);

	/*********************************************************
	Supprime l'arc à l'indice iIndice dans la liste des arcs arrivants
	*********************************************************/
	void SOMSupprimerArcArrivant(int iIndice);

	/*********************************************************
	Ajoute un arc dans la liste des arcs sortants
	*********************************************************/
	void SOMAjouterArcSortant(CArc* pARCArc);

	/*********************************************************
	Modifie l'arc à l'indice iIndice dans la liste des arcs sortants
	*********************************************************/
	void SOMModifierArcSortant(int iIndice, int iDestination);

	/*********************************************************
	Supprime l'arc à l'indice iIndice dans la liste des arcs sortants
	*********************************************************/
	void SOMSupprimerArcSortant(int iIndice);

			/************
			 * METHODES *
			 ************/

	/*********************************************************
	Inverse l'orientation de tous les arcs reliés au sommet
	*********************************************************/
	void SOMInverserArrivantPartant();
};

#endif // SOM