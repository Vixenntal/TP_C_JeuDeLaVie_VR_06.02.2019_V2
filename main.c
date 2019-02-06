#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "fonctions.h"

int main()
{
    //VAR
    srand(time(NULL));//initialisation de l'aléatoire
    char cTableau[TAILLEX][TAILLEY];//le tableau de caracteres
    int nChoix = 0;

    tPosition position;
    ptPosition ptEmplacement = &position;
        position.nX = 0;
        position.nY = 0;
    initTab(cTableau);
    affectCells(cTableau);

    printf("Tableau initialise\n\n");
    afficherTab(cTableau);
    printf("Combien de generations ?\n");
    scanf("%d", &nChoix);

    for(int i = 0; i < nChoix; i++)//Debut du traitement en boucle de l'evolution des cellules
    {

        for(position.nX = 0; position.nX < TAILLEX; position.nX++) //double boucle pour, afin d'appliquer l'etat BORN a une cellule
        {
            for(position.nY = 0; position.nY < TAILLEY; position.nY++)
            {
                if((aliveCells(cTableau, ptEmplacement)==3) && (cTableau[position.nX][position.nY] == EMPTY))
                {
                    cTableau[position.nX][position.nY] = BORN;
                }
            }
        }
        for(position.nX = 0; position.nX < TAILLEX; position.nX++)//double boucle pour, afin d'appliquer l'etat DEAD a une cellule
        {
            for(position.nY = 0; position.nY < TAILLEY; position.nY++)
            {
                if((cTableau[position.nX][position.nY]==LIVE)&&((aliveCells(cTableau, ptEmplacement)<2) || (aliveCells(cTableau, ptEmplacement)>3)))
                {
                    cTableau[position.nX][position.nY] = DEAD;
                }
            }
        }
        for(position.nX = 0; position.nX < TAILLEX; position.nX++)//double boucle pour, afin de convertir les cellules DEADs et BORNs en LIVE ou EMPTY
        {
            for(position.nY = 0; position.nY < TAILLEY; position.nY++)
            {
                if(cTableau[position.nX][position.nY]==DEAD)
                {
                    cTableau[position.nX][position.nY] = EMPTY;
                }
                else if(cTableau[position.nX][position.nY]==BORN)
                {
                    cTableau[position.nX][position.nY] = LIVE;
                }
            }
        }
        afficherTab(cTableau);

        compte(cTableau);
        ecrireFichierTexte(cTableau);

        system("pause");
        system("cls");
    }


    return 0;
}
