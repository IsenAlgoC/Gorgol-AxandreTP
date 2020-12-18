#include <stdio.h>
#include <stdlib.h>

#define carre(x) x*x
int nb = 5;

int main() {

	printf(" %d",carre(nb));                   
	printf("\n %d", carre((nb+1)));

}