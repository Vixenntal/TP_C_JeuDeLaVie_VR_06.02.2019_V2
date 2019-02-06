#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "fonctions.h"

//**********************************************
//BUT : Initialisation du tableau de caracteres
//ENTREES : Tableau
//SORTIES : Tableau initialisé à 0
//**********************************************
void initTab(char cTableau[TAILLEX][TAILLEY])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < TAILLEX; i++)
    {
        for(j = 0; j < TAILLEY; j++)
        {
            cTableau[i][j] = EMPTY;//les cellules EMPTYs deviennet des 'X'
        }
    }
}

//*****************************************
//BUT : Affichage du tableau de caracteres
//ENTREES : Tableau
//SORTIES : Tableau affiché
//*****************************************
void afficherTab(char cTableau[TAILLEX][TAILLEY])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < TAILLEX; i++)
    {
        for(j = 0; j < TAILLEY; j++)
        {
            printf("%c ", cTableau[i][j]);
        }
        printf("\n");
    }
}


//**********************************************************************************
//BUT : Affectation des cellules, LIVE pour cellule vivante et EMPTnY pour case EMPTY
//ENTREES : Tableau
//SORTIES : Tableau + cellules aléatoire
//**********************************************************************************
void affectCells(char cTableau[TAILLEX][TAILLEY])
{
    int nRand1 = 0;
    int nRand2 = 0;
    int nCpt = 0;

    for(nCpt = 0; nCpt<CELL; nCpt++)//Génération de CELL (= 30 au départ) cellules
    {
        nRand1 = (rand() % (TAILLEX));
        nRand2 = (rand() % (TAILLEY));
        cTableau[nRand1][nRand2] = LIVE;
    }
}



//****************************************************
//BUT : Verification des cellules en etat DEAD ou LIVE
//ENTREES : Tableau + coordonnées
//SORTIES : Cellules DEAD et LIVE autour de la case
//****************************************************
int aliveCells (char cTableau[TAILLEX][TAILLEY], ptPosition ptEmplacement)
{
	int nCptCellLive = 0;

    if(((cTableau[(*ptEmplacement).nX-1][(*ptEmplacement).nY-1]) == LIVE) || ((cTableau[(*ptEmplacement).nX-1][(*ptEmplacement).nY-1]) == DEAD))
	    {
	        nCptCellLive += 1;
	    }

    if(((cTableau[(*ptEmplacement).nX-1][(*ptEmplacement).nY]) == LIVE) || ((cTableau[(*ptEmplacement).nX-1][(*ptEmplacement).nY]) == DEAD))
	    {
	        nCptCellLive += 1;
	    }

    if(((cTableau[(*ptEmplacement).nX-1][(*ptEmplacement).nY+1]) == LIVE) || ((cTableau[(*ptEmplacement).nX-1][(*ptEmplacement).nY+1]) == DEAD))
	    {
	        nCptCellLive += 1;
	    }

    if(((cTableau[(*ptEmplacement).nX][(*ptEmplacement).nY-1]) == LIVE) || ((cTableau[(*ptEmplacement).nX][(*ptEmplacement).nY-1]) == DEAD))
	    {
	        nCptCellLive += 1;
	    }

    if(((cTableau[(*ptEmplacement).nX][(*ptEmplacement).nY+1]) == LIVE) || ((cTableau[(*ptEmplacement).nX][(*ptEmplacement).nY+1]) == DEAD))
	    {
	        nCptCellLive += 1;
	    }

    if(((cTableau[(*ptEmplacement).nX+1][(*ptEmplacement).nY-1]) == LIVE) || ((cTableau[(*ptEmplacement).nX+1][(*ptEmplacement).nY-1]) == DEAD))
	    {
	        nCptCellLive += 1;
	    }

    if(((cTableau[(*ptEmplacement).nX+1][(*ptEmplacement).nY]) == LIVE) || ((cTableau[(*ptEmplacement).nX+1][(*ptEmplacement).nY]) == DEAD))
	    {
	        nCptCellLive += 1;
	    }

    if(((cTableau[(*ptEmplacement).nX+1][(*ptEmplacement).nY+1]) == LIVE) || ((cTableau[(*ptEmplacement).nX+1][(*ptEmplacement).nY+1]) == DEAD))
    	{
    	    nCptCellLive += 1;
    	}

    return nCptCellLive;
}

void compte(char cTableau[TAILLEX][TAILLEY])
{
    //*****************************************************************************
    //  BUT : Affiche le nombre de cellules mortes et vivante pendant le programme
    //  ENTREES : Tableau
    //  SORTIES : Tombre de cellules mortes et vivantes
    //*****************************************************************************
    int i = 0;
    int j = 0;
    int nLive = 0;
    int nDead = 0;

    for(i = 0; i < TAILLEX; i++)
    {
        for(j = 0; j < TAILLEY; j++)
        {
            if(cTableau[i][j]==LIVE)
            {
                nLive += 1;
            }

            if(cTableau[i][j]==EMPTY)
            {
                nDead += 1;
            }

        }
    }
    printf("Nombre de cellules mortes : %d\nNombre de cellules vivantes : %d\n\n", nDead, nLive);
}

int ecrireFichierTexte(char cTableau[TAILLEX][TAILLEY])
{
	FILE* fichierTexte = NULL;

	int i = 0;
    int j = 0;
    int nLive = 0;
    int nDead = 0;

    for(i = 0; i < TAILLEX; i++)
    {
        for(j = 0; j < TAILLEY; j++)
        {
            if(cTableau[i][j]==LIVE)
            {
                nLive += 1;
            }

            if(cTableau[i][j]==EMPTY)
            {
                nDead += 1;
            }
        }
    }

    fichierTexte = fopen("Cellules vivantes-mortes.txt", "a");
    fprintf(fichierTexte, "Nombre de cellules mortes : %d\nNombre de cellules vivantes : %d\n\n", nDead, nLive);
    fclose(fichierTexte);

    return 0;
}
