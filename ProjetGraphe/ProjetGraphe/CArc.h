#ifndef ARC
#define ARC 0;

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
	CArc(CArc &Carc);

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

#endif // !ARC