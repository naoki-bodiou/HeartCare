#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "actions.h"

int	ft_donnees()
{
	FILE* fichier = NULL;
	int* TabTemps;
	int* TabPouls;
	int compteur;
	compteur = nb_lignes();
	fichier = fopen("Battements.csv", "r");
	if (fichier != NULL)
	{
		//on peut lire dans le fichier

		if (!(TabTemps = malloc(sizeof(int) * (compteur + 1))))
			exit (0);
		if (!(TabPouls = malloc(sizeof(int) * (compteur + 1))))
			exit (0);
		for (int i = 0; i < compteur; i++)
        {
            fscanf(fichier, "%d,%d", &TabTemps[i], &TabPouls[i]);
        }
		fclose(fichier); //On ferme le fichier qui a été ouvert
	}
	else
	{
		//on ne peut pas lire dans le fichier, message d'erreur
		printf("Impossible d'ouvrir le fichier Battements.csv");
		exit(0);
	}
	if (afficher_menus(TabTemps, TabPouls, compteur) == 0)
    {
		free(TabTemps);
		free(TabPouls);
        return 0;
    }
	else
	{
		free(TabTemps);
		free(TabPouls);
		return 1;
	}
}
