#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define NBMAXNOTES 30
#define carre(x) x*x

int tab[NBMAXNOTES];

float a = 0;
int ch = 0;
float valide = 0;
int absence = 0;
float somme = 0;
float Max = 0;
float Min = 20;
float moyenne = 0;
float ecart = 0;
float s = 0;

int main() {
	for (int p = 0; p <= 29; p++) {
		tab[p] = -2;
	}
	for (int i = 0; i <= 29; i++) {
		printf("\nentrez une valeur %d =", i);
		scanf_s("%f.2", &a);
		
		if (a < 0 || a>20) {
			printf("Eleve absent ? ou voulez vous arrêter la saisie des notes ? A / O / N");
			
			do {
				 ch = _getch();
			} while (ch != 'A' && ch != 'O' && ch != 'N');
			
			switch (ch) {

			case 'A':
				tab[i] = -1;
				absence += 1;
				break;

			case 'O':
				goto fini;

			case 'N':
				goto continu;
			}
		} 
		else {
			valide += 1;
			tab[i] = a;
			if (Max < a) {
				Max = a;
			}
			if (Min > a) {
				Min = a;
			}
			somme += a;
		}


	continu:;
		
	}
fini:;
	moyenne = somme / valide;
	printf("\nle nombre de note valide est %f", valide);
	printf("\nle nombre d'adsent est de %d", absence);
	printf("\nla note max est %f", Max);
	printf("\nla note minimum est %f", Min);
	printf("\nla moyenne est %.2f", moyenne);
	for (int k = 0; k <= 29 ; k++) {
		printf("\n tab[%d] = %d", k, tab[k]);
	}
	for (int j = 0; j <= valide; j++) {
		if (tab[j] != -1) {
			s += carre((tab[j] - moyenne));
			
		}
		
	}
	ecart = sqrt(((s/(valide-1))));
	printf("\n ecart type = %.2f", ecart);

 } 