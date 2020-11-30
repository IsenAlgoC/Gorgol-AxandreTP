typedef struct Tableau {
	int* elt; // Tableau d’entiers
	int size; // Taille du tableau d’entiers
	int eltsCount; // Nombre d’éléments du tableau
} TABLEAU;

TABLEAU newArray();
//protoype des fonctions du code source.
int incrementArraySize(TABLEAU* tab, int incrementValue);

int setElement(TABLEAU* tab, int pos, int element);

int displayElements(TABLEAU* tab, int startPos, int endPos);

int deleteElements(TABLEAU* tab, int startPos, int endPos);
