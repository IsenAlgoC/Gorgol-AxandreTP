#include "tp4.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

HEURE HeureDebut, HeureFin, Duree;
HeureDebut.heure= 12;
HeureDebut.minute = 30;
Duree.heure = 0;
Duree.minute = 45;
int c = 0;

HeureFin.minute = (HeureDebut.minute + Duree.minute) % 60;
if (HeureDebut.minute + Duree.minute >= 60) {
	c = 1;
}
else {
	c = 0;
}
HeureFin.heure = HeureDebut.heure + Duree.heure + c;
printf("%d : %d",HeureFin.heure , HeureFin.minute);


}

