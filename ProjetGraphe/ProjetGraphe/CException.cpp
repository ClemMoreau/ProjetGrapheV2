#include "Cexception.h"

/*********************************************************
Constructeur par défaut de la classe CException
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec uiEXCValeur = 0
*********************************************************/
CException::CException()
{
	EXCmodifier_valeur(0);
}

/*********************************************************
Constructeur de recopie de la classe CException
prenant en paramètre un objet de la classe CException
*********************************************************
Entrée: CException& EXCobjet : L'objet à recopier
Nécessite:	EXCobjet doit être initialisé
Sortie: (rien)
Entraîne :	L'objet est initialisé avec this.uiEXCValeur = EXCobjet.uiEXCValeur
*********************************************************/
CException::CException(CException& EXCobjet)
{
	if (EXCobjet.EXClire_valeur() < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(valeur_negative);
		throw(EXCObjet);
	}
	EXCmodifier_valeur(EXCobjet.EXClire_valeur());
}

/*********************************************************
Destructeur de la classe CException
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est pret à être détruit
*********************************************************/
CException::~CException()
{
	EXCmodifier_valeur(0);
}

/*********************************************************
Destructeur de la classe CException
*********************************************************
Entrée: unsigned int uiValeur : le code de l'exception
Nécessite: (rien)
Sortie: (rien)
Entraîne :	this.uiEXCValeur = uiValeur
*********************************************************/
void CException::EXCmodifier_valeur(int iValeur)
{
	if (iValeur < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(valeur_negative);
		throw(EXCObjet);
	}
	uiEXCvaleur = iValeur;
}

/*********************************************************
Attribut le message d'exception correspondant
*********************************************************
Entrée: char* pcMessage : le message de l'exception à levé
Nécessite: (rien)
Sortie: (rien)
Entraîne :	this.pcEXCMessage = pcMessage
*********************************************************/
void CException::EXCmodifier_message(const char* pcMessage)
{
	if (pcMessage)
	{
		if (!EXClire_message())
		{
			free(pcEXCMessage);
		}

		int iConteur = strlen(pcMessage);
		pcEXCMessage = (char*)malloc(iConteur + 1);
		int iBoucleCopie;
		for (iBoucleCopie = 0; iBoucleCopie < iConteur; iBoucleCopie++)
		{
			pcEXCMessage[iBoucleCopie] = pcMessage[iBoucleCopie];
		}
		pcEXCMessage[iBoucleCopie] = '\0';
	}
	else
	{
		pcEXCMessage = NULL;
	}
}

/*********************************************************
Destructeur de la classe CException
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: unsigned int : le code de l'exception
Entraîne :	(rien)
*********************************************************/
unsigned int CException::EXClire_valeur()
{
	return uiEXCvaleur;
}

/*********************************************************
Lit le message de l'exception
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: unsigned int : le code de l'exception à levé
Entraîne :	(rien)
*********************************************************/
char* CException::EXClire_message()
{
	return pcEXCMessage;
}