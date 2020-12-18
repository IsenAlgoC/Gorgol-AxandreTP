#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main() {
	unsigned int w = 192, x = 168, y = 129, z = 10, adresse, adresse_reseau, adresse_broadcast;
	unsigned long long int IPv4MaskLenght = pow(2, 32) - 1, notmask;
	int n = 24, i;

	for (i = 0; i < (32 - n); i++) {
		IPv4MaskLenght -= pow(2, i);
	}
	notmask = ~IPv4MaskLenght;

	adresse = w;
	adresse <<= 8;
	adresse += x;
	adresse <<= 8;
	adresse += y;
	adresse <<= 8;
	adresse += z;

	w = adresse;
	w >>= 24;

	x = adresse;
	x >>= 16;
	x -= w * pow(2, 8);

	y = adresse;
	y >>= 8;
	y -= (w * pow(2, 16) + x * pow(2, 8));

	z = adresse;
	z -= (w * pow(2, 24) + x * pow(2, 16) + y * pow(2, 8));

	printf("Adresse Machine = %u.%u.%u.%u\n", w, x, y, z);

	adresse_reseau = (adresse) & (IPv4MaskLenght);

	w = adresse_reseau;
	w >>= 24;

	x = adresse_reseau;
	x <<= 8;
	x >>= 24;

	y = adresse_reseau;
	y <<= 16;
	y >>= 24;

	z = adresse_reseau;
	z <<= 24;
	z >>= 24;

	printf("Adresse Reseau = %u.%u.%u.%u\n", w, x, y, z);

	adresse_broadcast = adresse_reseau | notmask;

	w = adresse_broadcast;
	w >>= 24;

	x = adresse_broadcast;
	x <<= 8;
	x >>= 24;

	y = adresse_broadcast;
	y <<= 16;
	y >>= 24;

	z = adresse_broadcast;
	z <<= 24;
	z >>= 24;

	printf("Adresse Broadcast : %u,%u,%u,%u", w, x, y, z);

	
	










	


}