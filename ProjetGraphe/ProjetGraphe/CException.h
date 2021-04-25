#ifndef EXC
#define EXC 0

#include <iostream>
#define valeur_negative 100

class CException
{
private:
	/*************
	* ATTRIBUTS *
	*************/

	unsigned int uiEXCvaleur;

	char* pcEXCMessage;
		
public:
	/*****************
	 * CONSTRUCTEURS *
	*****************/

	/*********************************************************
	Constructeur par défaut de la classe CException
	*********************************************************
	Entrée: (rien)
	Nécessite:	(rien)
	Sortie: (rien)
	Entraîne :	L'objet est initialisé avec uiEXCValeur = 0
	*********************************************************/
	CException();

	/*********************************************************
	Constructeur de recopie de la classe CException
	prenant en paramètre un objet de la classe CException
	*********************************************************
	Entrée: CException& EXCobjet : L'objet à recopier
	Nécessite:	EXCobjet doit être initialisé
	Sortie: (rien)
	Entraîne :	L'objet est initialisé avec this.uiEXCValeur = EXCobjet.uiEXCValeur
	*********************************************************/
	CException(CException &EXCobjet);

	/***************
	* DESTRUCTEUR *
	***************/

	/*********************************************************
	Destructeur de la classe CException
	*********************************************************
	Entrée: (rien)
	Nécessite:	(rien)
	Sortie: (rien)
	Entraîne :	L'objet est pret à être détruit
	*********************************************************/
	~CException();

	/***********
	* SETTERS *
	***********/

	/*********************************************************
	Attributs le code d'exception correspondant
	*********************************************************
	Entrée: unsigned int uiValeur : le code de l'exception à levé
	Nécessite: (rien)
	Sortie: (rien)
	Entraîne :	this.uiEXCValeur = uiValeur
	*********************************************************/
	void EXCmodifier_valeur(int iValeur);

	/*********************************************************
	Attributs le message d'exception correspondant
	*********************************************************
	Entrée: char* pcMessage : le message de l'exception à levé
	Nécessite: (rien)
	Sortie: (rien)
	Entraîne :	this.pcEXCMessage = pcMessage
	*********************************************************/
	void EXCmodifier_message(const char* pcMessage);

	/***********
	 * GETTERS *
	 ***********/

	 /*********************************************************
	 Lit le code de l'exception levé
	 *********************************************************
	 Entrée: (rien)
	 Nécessite:	(rien)
	 Sortie: unsigned int : le code de l'exception à levé
	 Entraîne :	(rien)
	 *********************************************************/
	unsigned int EXClire_valeur();

	/*********************************************************
	 Lit le message de l'exception
	 *********************************************************
	 Entrée: (rien)
	 Nécessite:	(rien)
	 Sortie: unsigned int : le code de l'exception à levé
	 Entraîne :	(rien)
	 *********************************************************/
	char* EXClire_message();
};
#endif //EXC

