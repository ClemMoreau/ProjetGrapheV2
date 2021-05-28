#include <iostream>
#include "CGraphe.h"
#include "CFichier.h"
using namespace std;

int main(int argc, char* argv[])
{
	char a[] = "C:/Users/cleme/OneDrive/Bureau/test.txt";
	argv[1] = a;
	argc++;

	double dFin;

	if (argc < 2)
	{
		cerr << "Vous n'avez pas passer de parametre lors de l'appel du programme. " << endl;
		cout << "Pour fermer la fenetre, veuillez entrer quelque chose puis appuyer sur entree." << endl;
		cin >> dFin;
		return 1;
	}

	else if (argc == 2)
	{
		// Création des variables locales
		CGraphe GRAGraphe;
		CFichier FICFichier;

		//Lecture du fichier
		try
		{
			FICFichier.FICModifierNomFichier(argv[1]);
			/*GRAGraphe = FICFichier.FICLireFichier();
			si bug*/
			cout << "AFFICHAGE DU GRAPHE LU " << endl;
			FICFichier.FICLireFichier().GRAAfficherGraphe();
			cout << endl << endl;
		}
		catch (CException EXCLevee)
		{
			cerr << "L'exception " << EXCLevee.EXClire_valeur() << " a ete levee avec le message " << EXCLevee.EXClire_message() << endl;
			cout << "Pour fermer la fenetre, veuillez entrer quelque chose puis appuyer sur entree." << endl;
			cin >> dFin;
			return 1;
		}

		//Affichage du graphe 
		/*cout << "AFFICHAGE DU GRAPHE LU " << endl;
		GRAGraphe.GRAAfficherGraphe();
		cout << endl << endl;*/

		//Inversion du graphe

		CGraphe GRAGrapheInverse;
		try
		{
			
			/*GRAGrapheInverse = GRAGraphe.GRAInverseGraphe();
			si bug*/
			cout << "AFFICHAGE DU GRAPHE INVERSE " << endl;
			FICFichier.FICLireFichier().GRAInverseGraphe().GRAAfficherGraphe();
			cout << endl << endl;
		}
		catch (CException EXCLevee)
		{
			cerr << "L'exception " << EXCLevee.EXClire_valeur() << " a ete levee avec le message " << EXCLevee.EXClire_message() << endl;
			cout << "Pour fermer la fenetre, veuillez entrer quelque chose puis appuyer sur entree." << endl;
			cin >> dFin;
			return 1;
		}

		/*cout << "AFFICHAGE DU GRAPHE LU " << endl;
		GRAGrapheInverse.GRAAfficherGraphe();
		cout << endl << endl;*/

	}
	else if (argc > 2)
	{
		cerr << "Vous avez passe trop d'arguments lors de l'appel au programme, il ne faut passer qu'un seul fichier à la fois." << endl;
		cout << "Pour fermer la fenetre, veuillez entrer quelque chose puis appuyer sur entree." << endl;
		cin >> dFin;
		return 1;
	}

}
