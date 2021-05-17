#include "CArc.h"

/*********************************************************
Constructeur par d�faut de la classe CArc
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec uiARDestination = 0
*********************************************************/
CArc::CArc()
{
	// Initialisation de l'attribut
	uiARDestination = 0;
}

/*********************************************************
Constructeur de recopie de la classe CArc
prenant en param�tre un CArc
*********************************************************
Entr�e: CArc ARCarc : l'arc � recopier
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec 
uiARDestination = ARCarc.uiARDestination
*********************************************************/
CArc::CArc(CArc &ARCarc)
{
	// Copie de l'attribut 
	uiARDestination = ARCarc.uiARDestination;
}

/*********************************************************
Constructeur de la classe CArc
prenant en param�tre la destination de l'arc cr��
*********************************************************
Entr�e: int iDestination : la destination de l'arc cr��
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec
uiARDestination = iDestination
*********************************************************/
CArc::CArc(int iDestination)
{
	// V�rification param�tre positif
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
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec
uiARDestination = 0
*********************************************************/
CArc::~CArc()
{
	uiARDestination = 0;
}

/*********************************************************
Renvoie le num�ro du sommet de destination
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: unsigned int : la destination de l'arc
Entra�ne :	(rien)
*********************************************************/
unsigned int CArc::ARCLireDestination()
{
	return uiARDestination;
}

/*********************************************************
Modifie le sommet de destination
*********************************************************
Entr�e: iDestination : la nouvelle destination de l'arc
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	uiARDestination = iDestination
*********************************************************/
void CArc::ARCModifierDestination(int iDestination)
{
	// V�rification param�tre positif
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