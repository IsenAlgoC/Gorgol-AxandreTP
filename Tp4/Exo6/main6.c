#include <stdlib.h>
#include <stdio.h>
#define TAILLE 100
int main() {
	int tab[TAILLE];
	int tab_pos[TAILLE];
	int val;
	int n = 0;
	int* curseur = &tab[0];

	for (int i = 0; i < TAILLE; i++) {
		tab[i] = rand() % 21;
		tab_pos[i] = -1;
	}

	printf("Entrer la valeur a rechercher : ");
	scanf_s("%d", &val);

	for (int i = 0; i < TAILLE; i++) {
		curseur++;
		if (*curseur == val) {
			if (n == 0) {
				printf("\nLa valeur a ete trouvee en %d", i);
			}
			else {
				printf(", puis en %d", i);
			}
			n++;
			tab_pos[n] = i;
		}
	}
	if (n == 0) {
		printf("\nLa valeur n'a pas ete trouvee");
	}
}