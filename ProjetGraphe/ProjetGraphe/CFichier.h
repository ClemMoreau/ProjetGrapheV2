#ifndef FIC
#define FIC 0

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stdio.h>
#include "CException.h"
#include "CGraphe.h"

class CFichier
{
private:

				/*************
				 * ATTRIBUTS *
				 *************/

	/*Nom du Fichier*/
	char* psFICNomFichier;

public:

				/*****************
				 * CONSTRUCTEURS *
				 *****************/

	/*********************************************************
	Constructeur par défaut de la classe CFichier
	*********************************************************/
	CFichier();

	/*********************************************************
	Constructeur de recopie de la classe CFichier
	prenant en paramètre un CFichier
	*********************************************************/
	CFichier(CFichier &FICFichier);

				/***************
				 * DESTRUCTEUR *
				 ***************/

	/*********************************************************
	Destructeur de la classe CFichier
	*********************************************************/
	~CFichier();

				/***********
				 * GETTERS *
				 ***********/

	 /*********************************************************
	 Renvoie le nom du fichier
	 *********************************************************/
	char* FICLireNomFichier();


				/***********
				 * SETTERS *
				 ***********/

	/*********************************************************
	Modifie le nom du fichier
	*********************************************************/
	void FICModifierNomFichier(const char * pcNouveauNom);

				/************
				 * METHODES *
				 ************/

	/*********************************************************
	Lecture du fichier et extraction des informations dans le fichier
	*********************************************************/
	CGraphe FICLireFichier();
};

#endif //FIC