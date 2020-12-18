#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char prenom[20];
	char nom[20];
	char genre = " ";

	do {
		printf("Entre le sexe H ou F :");
		genre = _getch();
	} while (genre != 'H' && genre != 'F');

	printf("\nEntre le prenom : ");
	scanf_s("%s", prenom, (unsigned int)_countof(prenom));
	printf("Entre le nom : ");
	scanf_s("%s", nom, (unsigned int)_countof(nom));

	if (genre == 'H') {
		printf("Monsieur ");
	}
	else {
		printf("Madame ");
	}
	printf("%s %s", nom, prenom);
}