#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
#define TAILLEAJOUT 5



int initTab(int* tab, int size) {
	if (size < 0 && tab == NULL) { //verifie que les variables d'entr�es sont correct (exploitable pour la suite de la fonction)
		return -1;
	}
	for (int i = 0; i < size; i++) //boucle qui initialise le valeurs du tabeau � 0
	{
		*tab = 0;
		tab++;
	}
	return size;
}

int afficheTab(int* tab, int size, int nbElts) 
{
	if (size < 0 && tab == NULL && size < nbElts)//verifie que les variables d'entr�es sont correct (exploitable pour la suite de la fonction)
	{
		return -1;
}
		for (int k = 0; k < nbElts; k++) {
		printf("\n %d     ", *tab);             //affiche la valeur � l'adresse contenu par le pointeur et incremente l'adresse +1
			tab++;
	}
		return 0;
}

int remplissage(int* tab, int size, int nb) {
	if (size < nb) { 
		return -1;
	}
	for (int i = 0; i < nb; i++) { 
		*tab = i+1; //remplit le tableau avec des valeurs de 1 � nb
		tab++;
	}
	return 0;
}

int* ajouterElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if ((tab != NULL) && (size != NULL) && (nbElts != NULL)) {
		if (*size > * nbElts) {                   // verifiation de la place, pas besoin de realloc on ajoute l'element au dernier element 
			printf("\n Tableau incomplet");
			*(tab + *nbElts) = element;
			*nbElts = *nbElts + 1;
			return(tab);
		}
		else {
			printf(" \n Tableau copmlet, on rajoute %d places", TAILLEAJOUT);
			int var = TAILLEAJOUT + *size;
			int* tmp = tab; //sauvegarde le pointeur en cas d'�chec de la r�alloc
			tab = (int*)realloc(tab, (var) * (sizeof(int)));

			if (tab != NULL) { // Verification  du realloc, on peut d�placer tab � l'adresse pr�vue et modifier les diff�rents compteurs							
				*size = *size + TAILLEAJOUT;
				*(tab + *nbElts) = element;
				*nbElts = *nbElts + 1;
				return(tab);
			}
			else {
				tab = tmp;       // si la r�alloc n'a pas fonctionn�, on r�cup�re la sauvergarde du pointeur
				printf("La reallocation n'a pas fonctionn� correctement");
				return(NULL);
			}
		}
	}
	return(NULL);
}