#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

int afficher_menus(int* tab_temps, int* tab_pouls, int taille)
{
    int reponse;
	int reponse_compl;
    printf("\nFaire 1 pour afficher les donnees dans l'ordre du fichier .csv\nFaire 2 pour afficher les donnees en ordre croissant\nFaire 3 pour afficher les donnees en ordre decroissant\nFaire 4 pour afficher une donnee pour un temps particulier\nFaire 5 pour afficher la moyenne de pouls dans une plage de temps donnee\nFaire 6 pour afficher le nombre de lignes de donnees actuellement en memoire\nFaire 7 pour afficher le maximum de pouls \nFaire 8 pour afficher le minimum de pouls\nFaire 9 pour quitter\n");
    scanf("%d", &reponse);
    //Lancer les fonctions selon les différentes fonction selon la valeur de réponse
    if(reponse == 1)
    {
        afficher_ordre_fichier(tab_pouls, tab_temps, taille);
		return 1;
    }
    if(reponse == 2)
    {
        printf("Faire 1 pour trier selon le temps\nFaire 2 pour trier selon le pouls\n");
        scanf("%d", &reponse_compl);
        if(reponse_compl==1)
        {
            afficher_ordre_croissant(tab_temps, tab_pouls, taille);
			return 1;
        }
        if(reponse_compl==2)
        {
            afficher_ordre_croissant(tab_pouls, tab_temps, taille);
			return 1;
        }
    }
    if(reponse == 3)
    {
        printf("Faire 1 pour trier selon le temps\nFaire 2 pour trier selon le pouls\n");
        scanf("%d", &reponse_compl);
        if(reponse_compl==1)
        {
            afficher_ordre_decroissant(tab_temps, tab_pouls, taille);
			return 1;
        }
        if(reponse_compl==2)
        {
            afficher_ordre_decroissant(tab_pouls, tab_temps, taille);
			return 1;
        }
    }
    if(reponse == 4)
    {
        recherche_temps_particulier(tab_pouls, tab_temps, taille);
		return 1;
    }
    if(reponse == 5)
    {
        moyenne(tab_pouls, tab_temps, taille);
		return 1;
    }
    if(reponse == 6)
    {
        afficher_nombre_de_lignes(taille);
		return 1;
    }
    if(reponse == 7)
    {
        afficher_pouls_max(tab_pouls, tab_temps, taille);
		return 1;
    }
    if(reponse == 8)
    {
        afficher_pouls_min(tab_pouls, tab_temps, taille);
		return 1;
    }
    if(reponse == 9)
    {
        quitter();
    }
    else
    {
       afficher_menus(tab_temps, tab_pouls, taille); //Sinon relancer le menus
    }
    return 1;
}
