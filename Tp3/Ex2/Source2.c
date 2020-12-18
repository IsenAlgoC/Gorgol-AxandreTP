#include <stdio.h>
#include <stdlib.h>

unsigned int a = 2868838400;
int i=0;

int main() {

	int size =0 ;
	size = sizeof(a);

	printf(" nombre de bit = %u", size);
	printf("\n nombre de d'octet = %u", size*8);

	for (i = 0; i <= 32;  i++) {

		if ((1 & a) == 1) {
			printf("\n BIT %d : ON",i);
		}
		else {
			printf("\n BIT %d : OFF", i);
		}
		a = a >> 1;
	}

}