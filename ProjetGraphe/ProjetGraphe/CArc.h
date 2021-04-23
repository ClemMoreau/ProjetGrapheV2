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
	Constructeur par d�faut de la classe CArc
	*********************************************************/
	CArc();

	/*********************************************************
	Constructeur de recopie de la classe CArc
	prenant en param�tre un CArc
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
	 Renvoie le num�ro du sommet de destination
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