#include <stdio.h>
#include <stdlib.h>

#define SEPARATEUR '/'
#define TAILLETAB1 20

int main() {
	int myTab[TAILLETAB1];
	for (int i = 0; i < 20; i++) {
		myTab[i] = i+1;
		printf("%d %c", myTab[i], SEPARATEUR);
	}
	int* ptr = &myTab[19];
	for (int k = 20; k > 0; k--) {
		printf("%d %c", *ptr, SEPARATEUR);
		ptr--;
	}
}