#ifndef  SOM
#define SOM 0
#include "CArc.h"

#define numero_negatif 301
#define indice_incorrecte 302
#define destination_incoh�rente 303
#define argument_null 304
#define echec_malloc 305

class CSommet {

private:
			/*************
			 * ATTRIBUTS *
			 *************/

	/*Numero du sommet*/
	unsigned int uiSOMNumero;

	/*Nombre d'arrivant au sommet*/
	unsigned int uiSOMNbArcArrivant;

	/*Liste des arcs arrivant au sommet*/
	CArc** ppARCSOMArcArrivant;

	/*Nombre sortant du sommet*/
	unsigned int uiSOMNbArcSortant;

	/*Liste des arcs sortant au sommet*/
	CArc** ppARCSOMArcSortant;

public:

			/*****************
			 * CONSTRUCTEURS *
			 *****************/
	
	/*********************************************************
	Constructeur par d�faut de la classe CSommet
	*********************************************************/
	CSommet();

	/*********************************************************
	Constructeur de recopie de la classe CSommet
	prenant en param�tre un CSommet
	*********************************************************/
	CSommet(CSommet& SOMSommet);

	/*********************************************************
	Constructeur de recopie de la classe CSommet
	prenant en param�tre un CSommet
	*********************************************************/
	CSommet(int iNumeroSommet);

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
	Retourne le nombre d'arc arrivant du sommet
	*********************************************************/
	int SOMLireNombreArcArrivant();

	/*********************************************************
	Retourne l'arc arrivant � l'indice iIndice 
	du tableau des arcs arrivant
	*********************************************************/
	CArc* SOMLireArcArrivant(int iIndice);

	/*********************************************************
	Retourne le nombre d'arc sortant du sommet
	*********************************************************/
	int SOMLireNombreArcSortant();

	/*********************************************************
	Retourne l'arc sortant � l'indice iIndice
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
	Modifie l'arc � l'indice iIndice dans la liste des arcs arrivants
	*********************************************************/
	void SOMModifierArcArrivant(int iIndice, int iDestination);

	/*********************************************************
	Supprime l'arc � l'indice iIndice dans la liste des arcs arrivants
	*********************************************************/
	void SOMSupprimerArcArrivant(int iIndice);

	/*********************************************************
	Ajoute un arc dans la liste des arcs sortants
	*********************************************************/
	void SOMAjouterArcSortant(CArc* pARCArc);

	/*********************************************************
	Modifie l'arc � l'indice iIndice dans la liste des arcs sortants
	*********************************************************/
	void SOMModifierArcSortant(int iIndice, int iDestination);

	/*********************************************************
	Supprime l'arc � l'indice iIndice dans la liste des arcs sortants
	*********************************************************/
	void SOMSupprimerArcSortant(int iIndice);

			/************
			 * METHODES *
			 ************/


	/*********************************************************
	Inverse l'orientation de tous les arcs reli�s au sommet
	*********************************************************/
	void SOMInverserArrivantPartant();
};

#endif // SOM