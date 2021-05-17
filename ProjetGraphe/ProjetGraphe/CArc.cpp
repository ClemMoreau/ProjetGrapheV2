#include "CArc.h"

/*********************************************************
Constructeur par défaut de la classe CArc
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec uiARDestination = 0
*********************************************************/
CArc::CArc()
{
	// Initialisation de l'attribut
	uiARDestination = 0;
}

/*********************************************************
Constructeur de recopie de la classe CArc
prenant en paramètre un CArc
*********************************************************
Entrée: CArc ARCarc : l'arc à recopier
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec 
uiARDestination = ARCarc.uiARDestination
*********************************************************/
CArc::CArc(CArc &ARCarc)
{
	// Copie de l'attribut 
	uiARDestination = ARCarc.uiARDestination;
}

/*********************************************************
Constructeur de la classe CArc
prenant en paramètre la destination de l'arc créé
*********************************************************
Entrée: int iDestination : la destination de l'arc créé
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec
uiARDestination = iDestination
*********************************************************/
CArc::CArc(int iDestination)
{
	// Vérification paramètre positif
	if (iDestination < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_negatif);
		EXCLevee.EXCmodifier_message("Destination negative !");
		throw(EXCLevee);
	}

	// Initialisation de l'attribut
	uiARDestination = iDestination;
}

/*********************************************************
Destructeur de la classe CArc
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec
uiARDestination = 0
*********************************************************/
CArc::~CArc()
{
	uiARDestination = 0;
}

/*********************************************************
Renvoie le numéro du sommet de destination
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: unsigned int : la destination de l'arc
Entraîne :	(rien)
*********************************************************/
unsigned int CArc::ARCLireDestination()
{
	return uiARDestination;
}

/*********************************************************
Modifie le sommet de destination
*********************************************************
Entrée: iDestination : la nouvelle destination de l'arc
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	uiARDestination = iDestination
*********************************************************/
void CArc::ARCModifierDestination(int iDestination)
{
	// Vérification paramètre positif
	if (iDestination < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_negatif);
		EXCLevee.EXCmodifier_message("Destination negative !");
		throw(EXCLevee);
	}

	// Modification destination
	uiARDestination = iDestination;
}