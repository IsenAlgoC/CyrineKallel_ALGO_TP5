#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

//Elles pr�voient la r�ception d'arguments erron�s et renvoient un code d'erreur 
//(Par d�faut 0, n�gatif ou NULL s�il y a une erreur, ou, positif pour un code de retour sp�cifique.

// Fonction avec passage d'un tableau en argument

//1.D�clarer dans la fonction main() un tableau nomm� myTab1 de 10 valeurs de type int.

//2.Ecrire une fonction qui remplit un tableau d�entiers de taille size avec des z�ros. 
//int initTab( int * tab, int size) Valeur de retour : -1 si tab est un pointeur NULL 
//ou size < 0, la taille du tableau sinon.

//3.Ecrire une fonction qui affiche les nbElts premi�rs �l�ments du tableau tab sur une ligne de la console.
//int afficheTab(int *tab, int size, int nbElts) Valeur de retour : -1 si tab est un pointeur NULL 
//ou size <0 ou size < nbElts, 0 sinon.


int initTab(int* tab, int size) //fonction qui remplit un tableau d�entiers de taille size avec des z�ros. 
{

	if ((tab == NULL) || (size < 0)) //Si r�ception d'arguments erron�s
	{
		return -1; //renvoit -1: code d'erreur 
	}

	else
	{
		for (int i = 0; i < size; i++)
		{
			tab[i] = 0; //boucle for pour remplir le tableau de 0
		}
		return size;
	}

}

int afficheTab(int* tab, int size, int nbElts) //fonction qui affiche les nbElts premi�rs �l�ments du tableau
{
	if ((tab == NULL) || (size < 0) || (size < nbElts)) // si r�ception d'arguments erron�s
	{
		return -1; //-1  en cas d'erreur
	}
	else
	{
		for (int i = 0; i < nbElts; i++)
		{
			printf(" %d ", tab[i]); //Boucle for pour afficher les  premi�rs �l�ments du tableau
		}
		printf("\n");
		return 0;
	}


}

//Ecrire la fonction : int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element); 
 //Elle ajoute un nombre entier � la suite des valeurs d�j� entr�es 
 //et met � jour le nombre d'�l�ments stock�s ainsi que la capacit� r�elle du tableau. 
 //Si le tableau est trop petit, il doit �tre agrandi de TAILLEAJOUT �l�ments.



int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element)  //Fonction qui ajoute un element dans le tableau et augmonte la memoire allouee si necessaire
																			//tab reprensente le tableau a remplir/modifier
																			//size reprensente la taille initiale de tab
																			//nbElts reprensente le nombre d'elements qu'on a
																			//element reprensente ce qu'on veut ajouter
{

	if (tab == NULL || size < 0)
	{
		return NULL;
	}

	if (*nbElts >= *size)
	{

		int* tabBis = tab;
		tab = (int*)realloc(tab, (*size + _TAILLEAJOUT_) * sizeof(int)); //si taille insuffisante, on realloue de l'espace au tableau

		if (tab != NULL)
		{
			tab[*nbElts] = element;
			*nbElts = *nbElts + 1;
			*size = *size + _TAILLEAJOUT_;
			return (tab);
		}
		else
		{
			return (NULL);
		}


	}
	else //dans le cas ou la taille est suffisante et donc tableau pas encore rempli
	{
		tab[*nbElts] = element;
		*nbElts = *nbElts + 1;
		return (tab);
	}
}