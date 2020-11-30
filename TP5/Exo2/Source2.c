#include <stdio.h>
#include <stdlib.h>
#include "tab2.h"

#define TAILLEINITIALE 100

int main() {

	int octet_ajt; //nombre d'octet à ajouter
	int element;//element à insérer

	int pos;//position de l'element à insérer
	int startPos1, endPos1;//intervalle pour affichage
	int startPos2, endPos2;//intervalle compression

	TABLEAU tableau = newArray();

	printf("\n Entrez le nombre d'octet a ajouter :");
	scanf_s("%d", &octet_ajt);//demande la valeur de octet_ajt
	incrementArraySize(&tableau, octet_ajt);//appel de la fonction pour ajouter des octets

	printf("\n Entrer la position et l'element :");
	scanf_s("%i %i", &pos, &element);//demande la valeur de la posotion et de l'element
	setElement(&tableau, pos, element); //appel de la fonction qui ajoute l'element

	printf("\n Entrez l'intervalle a afficher :");
	scanf_s("%d %d", &startPos1, &endPos1);//demande la valeur des bornes 
	displayElements(&tableau, startPos1, endPos1); //appel de la fonction pour l'affichage
	printf("L'ancienne taille du tableau etait de %d", tableau.size);

	printf("\n Entrez l'intervalle a supprimer :");
	scanf_s("%d %d", &startPos2, &endPos2);//demande la valeur de bornes 2
	printf("La nouvelle taille du tableau est de %d", deleteElements(&tableau, startPos2, endPos2)); //appel de la fonction dans le printf car elle renvoie la valeur de la nouvelle taille
	

}