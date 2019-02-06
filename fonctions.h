#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

//Declarations des constantes
#define TAILLEX 15 //Abscisse du tableau
#define TAILLEY 15 //Ordonnée du tableau
#define CELL 30 //Nombre de cellules au depart
#define EMPTY '=' //Cellule vide
#define LIVE 'O' //Cellule vivante
#define BORN 'B' //Cellule qui va naitre
#define DEAD 'D' //Cellule qui va mourir

//Type structuré
typedef struct tPosition
{
	int nX;
	int nY;
}tPosition, *ptPosition;

extern void initTab(char cTableau[TAILLEX][TAILLEY]);
extern void afficherTab(char cTableau[TAILLEX][TAILLEY]);
extern void affectCells(char cTableau[TAILLEX][TAILLEY]);
extern int aliveCells (char cTableau[TAILLEX][TAILLEY], ptPosition ptEmplacement);
extern void compte(char cTab[TAILLEX][TAILLEY]);
extern int ecrireFichierTexte(char cTableau[TAILLEX][TAILLEY]);

#endif //FONCTIONS_H_INCLUDED
