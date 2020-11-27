#pragma once

#include <stdio.h>



#define _size_ 10
#define _TAB2SIZE_ 100
#define _TAILLEAJOUT_ 50


int initTab(int* tab, int size);  //fonction qui initialise le tableau (rempli le tableau de 0)
int afficheTab(int* tab, int size, int nbElts); //fonction qui affiche les nbElts premi�rs �l�ments du tableau
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element); //fonction qui ajoute un nombre entier au tableau, et met � jour le nombre d'�l�ments stock�s ainsi que la capacit� r�elle du tableau

