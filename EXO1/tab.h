#pragma once

#include <stdio.h>



#define _size_ 10
#define _TAB2SIZE_ 100
#define _TAILLEAJOUT_ 50


int initTab(int* tab, int size);  //fonction qui initialise le tableau (rempli le tableau de 0)
int afficheTab(int* tab, int size, int nbElts); //fonction qui affiche les nbElts premièrs éléments du tableau
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element); //fonction qui ajoute un nombre entier au tableau, et met à jour le nombre d'éléments stockés ainsi que la capacité réelle du tableau

