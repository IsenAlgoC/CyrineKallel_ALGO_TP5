#include "tab.h"


#define _size_ 10
#define _TAB2SIZE_ 100
#define _TAILLEAJOUT_ 50

int main()
{
    int myTab1[_size_];
    initTab(myTab1, _size_);
    afficheTab(myTab1, _size_, 5);
    printf("\n");

    //Créez un tableau MyTab2 de manière dynamique dans le programme principal.
    //La taille de ce tableau sera d’abord définie à l’aide d’une constante TAB2SIZE qui vaut 100.
     // Testez la fonction d’initialisation à zéro du tableau MyTab2.
     // Remplissez les 20 premières valeurs du tableau avec les nombres de 1 à 20.
     //Affichez les 20 premières valeurs du tableau.
     // Détruisez le tableau MyTab2;


    int* MyTab2 = NULL;
    int TabSize = _TAB2SIZE_;
    int nbElts = 0;


    MyTab2 = (int*)malloc(_TAB2SIZE_ * sizeof(int)); //alloue la mémoire grace a la fonction malloc
                                                     //reserve l'espace (_TAB2SIZE_ * sizeof(int)) dans case memoire

    if (MyTab2 != NULL)

    {
        initTab(MyTab2, TabSize);    //Si ponteur non null, la tableau va etre initialisé

    }

    else {
        printf("mémoire insuffisante");  //Sinon pointeur Null alors message d'erreur: memoire insuffisante
        return(-1);
    }



    for (int i = 1; i < 20; i++)
    {
        MyTab2[i] = i + 1; //Boucle for pour remplir les 20 1er valeurs de 1 à 20 

    }

    for (int i = 0; i < 220; i++) { //on parcourt le tableau en ajoutant 220 elements par exemple
        int element = i;
        ajoutElementDansTableau(MyTab2, &TabSize, &nbElts, element);  //On ajoute les elements au tableau grace a la fonction
    }



    afficheTab(MyTab2, TabSize, nbElts);
    printf("\nLe nombre d'elements est de %d", nbElts);


    free(MyTab2);


}