#include <stdio.h>
#include <stdlib.h>
#include "tab2.h"
#define TAILLEINITIALE 100

TABLEAU newArray() /* creation de la fonction new array*/
{
	TABLEAU tab;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));//allocation d'une memoire de  n (=TAILLEINITIALE) case de taille = sizeof(int) octet           
	if (tab.elt == NULL)//si l'allocation � �chouer
	{
		return tab;
	}
	for (int i = 0; i < TAILLEINITIALE; i++)
	{
		*((tab.elt) + i) = 0;// Le tableau elt est initialis� avec des 0
	}
	tab.eltsCount = 0;//champ eltsCount initialis� � 0
	tab.size = TAILLEINITIALE;// Taille initiale affect� au champ size  
	return tab;
}

int incrementArraySize(TABLEAU* tab, int  incrementValue)
{   
	int* tmp;
	tmp = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int)); //cherche de l'espace en plus de incrementValue
	if (tmp == 0) { //verifie que le realloc a bien fonctionn�
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
		incrementArraySize(tab, pos - tab->size);//cree une place en plus si l'�l�ment ins�r� n'est pas imm�diatement apr�s le dernier �l�ment et cr�er des �l�ments � z�ros entre les deux.
		for (int i = tab->size; i < pos - tab->size; i++)
			*((tab->elt) + i) = 0;
		*((tab->elt) + pos) = element;  //insere l'element a l'emplacement demand�
		return ((tab->elt) + pos - 1);

	}
	*((tab->elt) + pos) = element; //insere l'element demand�
	return ((tab->elt) + pos - 1);
}


int displayElements(TABLEAU* tab, int startPos, int endPos)
{
	if ((tab->elt) == NULL || startPos >= (tab->size) || endPos >= (tab->size)) { //veirifie que les positions sont correct
		return -1;
	}
	if (startPos >= endPos)//si la fin est sup�rieur au d�but, inverse les bornes 
	{
		int tmp = startPos;
		startPos = endPos;
		endPos = tmp;

	}
	for (int i = startPos; i <= endPos; i++)
	{
		printf("|%d|", *((tab->elt) + i)); //affiche le contenu du champ elt 1 par 1 de startPos � endPos

	}
	printf("\n");
	return 0;
}



int deleteElements(TABLEAU* tab, int startPos, int endPos)
{
	int j = 0; // initialisation de l'indice de la liste raccourcie
	int* ntab = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int)); // on r�alloue la memoire necessaire au traitement
	if (ntab == NULL) { return(-1); }
	for (int i = 0; i <= tab->size - 1; i++) {
		if ((i < startPos) || (i > endPos)) {
			*(ntab + j) = *(tab->elt + i);  //on copie chaque element du tableau dans la copie lorsque son indice correspond aux param�tres d'entr�e
			j++; //quand on rajoute un element on incremente l'indice de la copie pour la remplir au fur et � mesure
		}
	}
	tab->size -= (endPos - startPos) + 1;//on assigne les valeurs aux champs du tableau (size, eltsCount, elt)
	tab->eltsCount -= (endPos - startPos) + 1;
	tab->elt = ntab;
	return(tab->size);

}
