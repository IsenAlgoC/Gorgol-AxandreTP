#include <stdio.h>
#include <stdlib.h>
#include "tab2.h"
#define TAILLEINITIALE 100

TABLEAU newArray() /* creation de la fonction new array*/
{
	TABLEAU tab;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));//allocation d'une memoire de  n (=TAILLEINITIALE) case de taille = sizeof(int) octet           
	if (tab.elt == NULL)//si l'allocation à échouer
	{
		return tab;
	}
	for (int i = 0; i < TAILLEINITIALE; i++)
	{
		*((tab.elt) + i) = 0;// Le tableau elt est initialisé avec des 0
	}
	tab.eltsCount = 0;//champ eltsCount initialisé à 0
	tab.size = TAILLEINITIALE;// Taille initiale affecté au champ size  
	return tab;
}

int incrementArraySize(TABLEAU* tab, int  incrementValue)
{   
	int* tmp;
	tmp = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int)); //cherche de l'espace en plus de incrementValue
	if (tmp == 0) { //verifie que le realloc a bien fonctionné
		return -1;
	}
	(*tab).elt = tmp; //augmente le nombre d'element du tableau de incrementValue
	(*tab).size += incrementValue; //calcul de la nouvelle taille
	return (*tab).size; 

}


int setElement(TABLEAU* tab, int pos, int element) 
{
	
	if (pos < 0)//verifie que la position donne "existe" (pas negative)
		return 0;
	if ((tab->size) <= pos) {
		incrementArraySize(tab, pos - tab->size);//cree une place en plus si l'élément inséré n'est pas immédiatement après le dernier élément et créer des éléments à zéros entre les deux.
		for (int i = tab->size; i < pos - tab->size; i++)
			*((tab->elt) + i) = 0;
		*((tab->elt) + pos) = element;  //insere l'element a l'emplacement demandé
		return ((tab->elt) + pos - 1);

	}
	*((tab->elt) + pos) = element; //insere l'element demandé
	return ((tab->elt) + pos - 1);
}


int displayElements(TABLEAU* tab, int startPos, int endPos)
{
	if ((tab->elt) == NULL || startPos >= (tab->size) || endPos >= (tab->size)) { //veirifie que les positions sont correct
		return -1;
	}
	if (startPos >= endPos)//si la fin est supérieur au début, inverse les bornes 
	{
		int tmp = startPos;
		startPos = endPos;
		endPos = tmp;

	}
	for (int i = startPos; i <= endPos; i++)
	{
		printf("|%d|", *((tab->elt) + i)); //affiche le contenu du champ elt 1 par 1 de startPos à endPos

	}
	printf("\n");
	return 0;
}



int deleteElements(TABLEAU* tab, int startPos, int endPos)
{
	int j = 0; // initialisation de l'indice de la liste raccourcie
	int* ntab = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int)); // on réalloue la memoire necessaire au traitement
	if (ntab == NULL) { return(-1); }
	for (int i = 0; i <= tab->size - 1; i++) {
		if ((i < startPos) || (i > endPos)) {
			*(ntab + j) = *(tab->elt + i);  //on copie chaque element du tableau dans la copie lorsque son indice correspond aux paramètres d'entrée
			j++; //quand on rajoute un element on incremente l'indice de la copie pour la remplir au fur et à mesure
		}
	}
	tab->size -= (endPos - startPos) + 1;//on assigne les valeurs aux champs du tableau (size, eltsCount, elt)
	tab->eltsCount -= (endPos - startPos) + 1;
	tab->elt = ntab;
	return(tab->size);

}
