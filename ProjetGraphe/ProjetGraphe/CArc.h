#ifndef ARC
#define ARC 0

#include "CException.h"

#define destination_negatif 201

class CArc
{
private:
			/*************
			 * ATTRIBUTS *
			 *************/
	unsigned int uiARDestination;

public:
			/*****************
			 * CONSTRUCTEURS *
			 *****************/

	/*********************************************************
	Constructeur par défaut de la classe CArc
	*********************************************************/
	CArc();

	/*********************************************************
	Constructeur de recopie de la classe CArc
	prenant en paramètre un CArc
	*********************************************************/
	CArc(CArc &ARCArc);

	/*********************************************************
	Constructeur de la classe CArc
	prenant en paramètre la destination de l'arc créé
	*********************************************************/
	CArc(int iDestination);

			/***************
			 * DESTRUCTEUR *
			 ***************/

	/*********************************************************
	Destructeur de la classe CArc
	*********************************************************/
	~CArc();

			/***********
			 * GETTERS *
			 ***********/

	 /*********************************************************
	 Renvoie le numéro du sommet de destination
	 *********************************************************/
	unsigned int ARCLireDestination();

			/***********
			 * SETTERS *
			 ***********/

	 /*********************************************************
	 Modifie le sommet de destination
	 *********************************************************/
	void ARCModifierDestination(int iDestination);
};

#endif //ARC