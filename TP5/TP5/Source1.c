#include <stdio.h>
#include <stdlib.h>
#include "tab.h"

#define TAILLEINITIALE 20
#define TAILLEAJOUT 5

int main() {
	int* myTab2 = NULL;
	int tabSize2 = TAILLEINITIALE;
	int nbElts = 20;
	int myTab1[10];

	myTab2 = (int*)malloc(TAILLEINITIALE * sizeof(int)); //allocation de la mémoire
	if (myTab2 != NULL) {
		initTab(myTab2, tabSize2);
	}
	else {
		printf("memoire insuffisante");
		return -1;
	}

    initTab(myTab1, 10);
	printf("\n Tab1=");
	afficheTab( myTab1,10,4); //affiche les 4 premiers elements du tableau

    remplissage(myTab2, tabSize2, nbElts); //remplit le tableau avec des valeurs de 1 à 20
	printf("\n Tab2=");
    afficheTab(myTab2, tabSize2, nbElts); //affiche le tableau2 en entier

	printf("\nle tableau contient %d elements", nbElts);
	ajouterElementDansTableau(myTab2, &tabSize2, &nbElts, 9);
	printf(" \n Dernier element du tableau apres l'ajout : %d", *(myTab2 + nbElts - 1));
	printf(" \n La taille du tableau est maintenant de %d", tabSize2);
	printf("\nle tableau contient %d elements", nbElts);

	ajouterElementDansTableau(myTab2, &tabSize2, &nbElts, 6);
	printf(" \n Dernier element du tableau apres l'ajout : %d", *(myTab2 + nbElts - 1));
	printf(" \n La taille du tableau est maintenant de %d", tabSize2);
	printf("\nle tableau contient %d elements", nbElts);
	afficheTab(myTab2, tabSize2, nbElts); //affiche le tableau

	free(myTab2); //libere l'espace du tableau

	return 0;
}



