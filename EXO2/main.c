#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//D�finisR la constante suivante pour fixer la taille initiale du tableau d�entiers : 
#define TAILLEINITIALE 100

//Cr�ez un type structur� nomm� TABLEAU pour manipuler les tableaux d'entiers :

typedef struct Tableau
{
	int* elt; // le tableau d�entiers
	int size; // la taille de ce tableau d�entiers
	int eltsCount; // le nombre d��l�ments dans le tableau
} TABLEAU;

//1 - cr�e un nouveau TABLEAU en allouant une taille initiale pour les donn�es.

TABLEAU newArray() //fonction de type tableau  qui renvoie une structure TABLEAU, avec un pointeur elt = NULL si allocation a �chou�.
{
	TABLEAU elt;
	elt.size = TAILLEINITIALE; //initialise la taille initiale du tableau elt
	elt.elt = (int*)malloc(TAILLEINITIALE * sizeof(int)); // alloue la m�moire grace a la fonction malloc
	elt.eltsCount = 0; //le champ eltsCount initialis� � z�ro.

	if (elt.elt == NULL) // pointeur elt = NULL si allocation a �chou�
	{
		return elt;
	}

	for (int i = 0; i < elt.size; i++)
	{
		elt.elt[i] = 0; //Le tableau elt sera initialis� avec des z�ros
	}

	return elt;

}

//2 - modifie la taille du tableau

int incrementArraySize(TABLEAU* tab, int incrementValue) //fonction qui modifie taille du tableau et qui renvoie -1 si erreur, ou la nouvelle taille si OK
{
	if (tab->elt == NULL || tab->size < 0 || incrementValue < 1)
	{
		return -1; //fonction renvoie -1 en cas de parametre erroner
	}


	int* tmp = tab->elt; //introduit pointeur temporaire tmp au cas ou pas d'allocution de la memoire
	tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));		//alloue la nouvelle memoire grace a la fonction realloc
	if (tab->elt == NULL) //bien verifier allocution de la memoire
	{
		tab->elt = tmp;
		return -1;
	}

	for (int i = tab->size; i < ((tab->size + incrementValue) - 1); i++)
	{
		tab->elt[i] = 0; //Initialiser les nouvelles valeurs 0
	}
	
	tab->size = tab->size + incrementValue; //Pour augmenter la taille du tab


	return tab->size;

}

//3 - Ecrit un �l�ment � une position donn�e sans insertion

int setElement(TABLEAU* tab, int pos, int element) //fonction qui ecrit un element a une position donn�e, avec le  param�tre pos qui indique la position d�insertion de la variable
{
	if ((tab->elt == NULL) || (pos < 1) || (tab->size < 0))
	{
		return 0; //en cas de parametre erron�s
	}

	//1er cas: Si l'�l�ment est ins�r� sans probleme apr�s le dernier �l�ment dans le tableau,
	if (pos < tab->size) //cad la memoire allou�e n'est pas depass�:
	{
		tab->elt[pos - 1] = element; //On ecrit l'element a la position donn�e
		return 0;
	}

	//2eme cas: Si l'�l�ment ins�r� n'est pas imm�diatement apr�s le dernier �l�ment,  il faut agrandir le tableau,
	else
		// memoire alou�e est depase et donc pointeur en dehors du tableau
	{
		if (incrementArraySize(tab, pos - (*tab).size) == -1)
		{
			return 0;
		}
		(*tab).elt[pos - 1] = element;

		return pos; //renvoie osition de l��l�ment ins�r�

		//incrementArraySize (tab, pos - tab->size); //on utilise la fonction  definie pr�cedemment pour augmonter la taille 


			/*for (int i = tab->size; i <= pos; i++) 
			{
				tab->elt[i] = 0; //on  r�er des �l�ments � z�ros entre les deux.
			}

			tab->elt[pos - 1] = element; //On ecrit l'element a la position donn�e
			*/
			
	}

	
}

//4 - Affiche une portion du tableau de l�indice d�but � l�indice fin

int displayElements(TABLEAU* tab, int startPos, int endPos)
{
	if ((tab->elt == NULL) || (startPos < 1) || (startPos > tab->size) || (endPos < 1) || (endPos > tab->size))
	{
		return -1; // si erreur
	}
	// startPos >= EndPos n�est pas un cas d�erreur et doit �tre trait�.

	if (startPos == endPos) //comme end et start sont egaux donc un seul element va etre affich�
	{
		printf("pos %d correspond a :%d\n", startPos, tab->elt[startPos - 1]);
		return 0;
	}

	if (startPos > endPos)
	{
		int indice = startPos; //les valeurs des 2 variable vont etre echang� grace a la variable temporaire 'indice'
		startPos = endPos;
		endPos = indice;
	}
	else //dans le cas ou end<start, on affiche les valeurs entre les 2
	{
		for (int i = startPos; i <= endPos; i++)
		{
			printf("%d ", tab->elt[i - 1]);
		}
		return(0);

	}


}

//5 - Supprime des �l�ments avec compactage du tableau

int deleteElements(TABLEAU* tab, int startPos, int endPos) //fonction qui met a jour e nombre d'�l�ments dans le tableau et diminue sa taille du tableau
{
	if (tab->elt == NULL || endPos > tab->size || startPos < 1) //verification 
	{
		return -1; //Si parametre incoh�rents
	}

	// startPos >= endPos n�est pas un cas d�erreur et doit �tre trait�.

	if (startPos == endPos)
	{
		for (int i = startPos - 1; i < (tab->size - 1); i++) // un seul element va etre supprim� et le reste des elments apres ce dernier va etre d�caler vers la gauche
		{
			tab->elt[i] = tab->elt[i + 1];
		}
		return tab->size;
	}

	if (startPos > endPos)
	{
		int indice = startPos; //les valeurs des 2 variable vont etre echang� grace a la variable temporaire 'indice'
		startPos = endPos;
		endPos = indice;
	}

	else
	{
		//on remplce les valeurs de la portion que l'on veut supprimer par les valeurs qui restent 
		for (int i = startPos - 1; i < (*tab).size - (endPos - startPos + 1); i++)
		{
			(*tab).elt[i] = (*tab).elt[i + endPos - startPos + 1];
		}
		tab->size = tab->size - (endPos - startPos); //on met a jour la taille du tableau

		int* tmp; //on introduit un pointeur sur une variable temporaire pour enregistrer le tableau
		tmp = tab->elt;
		tab->elt = (int*)realloc(tab->elt, (tab->size) - ((endPos - startPos + 1)) * sizeof(int));  // On r�alloue la m�moire

			if (tab->elt == NULL) // Pour v�rifier l'allocation la m�moire.
			{
				return -1; //en cas d echec d'allocation
			}

			return tab->size; // renvoie la nouvelle taille du tableau

	}


}


//6 - D�clarez un tableau de type TABLEAU dans la fonction main
//et testez les fonctions

int main()
{
	TABLEAU tab = newArray(); //declaration de tab

	printf("Taille initiale : %d \n", tab.size);
	incrementArraySize(&tab, 3); //Incr�mentation de 3
	printf("taille incrementee est : %d \n", tab.size);
	

	//test: 
	// setElement(TABLEAU *tab, int pos,  int element);
	setElement(&tab, 7, 2); //l'element 2 est mis en position 7
	setElement(&tab, 6, 4); //l'element 4 est mis en position 6
	setElement(&tab, 5, 3); //l'element 3 est mis en position 5
	setElement(&tab, 4, 1); //l'element 1 est mis en position 4	
	setElement(&tab, 16, 10); //l'element 10 est mis en position 16	
	//displayElements(TABLEAU *tab, int startPos, int endPos);
	
	printf("Affichage de la portion du tableau :\n");
	displayElements(&tab, 1, 50); //on affiche la portion 

	deleteElements(&tab, 4, 6); ///on supprime les elments entre pos 4 et 6
	printf("\n");

	printf("Affichage de la portion apres supression des elements du tableau :\n");
	displayElements(&tab, 1, 20); //on affiche une nouvelle fois apres la supression des elements
	printf("\n");

	return EXIT_SUCCESS;


}
