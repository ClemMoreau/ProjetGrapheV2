#ifndef EXC
#define EXC 0
#define valeur_negative 100

class CException
{
private:
	/*************
	* ATTRIBUTS *
	*************/

	unsigned int uiEXCvaleur;

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
	Nécessite:	uiValeur > 0
	Sortie: (rien)
	Entraîne :	this.uiEXCValeur = uiValeur
	*********************************************************/
	void EXCmodifier_valeur(int iValeur);

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
};
#endif //EXC

