#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

int recherche_dicho(int* tab, int taille, int valeur)
{
    int trouve;
    int id;
    int im;
    trouve = FALSE;
    id = 0;
    while(trouve == FALSE && ((taille- id)>1))
    {
        im = (id+taille)/2;
        if(tab[im]==valeur)
        {
            trouve = TRUE;
        }
        if(tab[im]>valeur)
        {
            taille = im;
        }
        else
        {
            id=im;
        }
    }
    if(tab[id]==valeur)
    {
        return(id);
    }
    else
    {
        return(-1);
    }
}

void echanger_couple(int* tab1, int* tab2, int i, int j)
{
     int memoire1;
     int memoire2;
     memoire1=tab1[i];
     tab1[i]=tab1[j];
     tab1[j]=memoire1;
     memoire2=tab2[i];
     tab2[i]=tab2[j];
     tab2[j]=memoire2;
}

int partition_couple(int* tab1, int* tab2, int debut, int fin)
{
    int comptage=debut;
    int pivot=tab1[debut];
    int i;
    for(i=debut+1;i<=fin;i++)
    {
        if(tab1[i]<pivot)
        {
            comptage++;
            echanger_couple(tab1,tab2,comptage,i);
        }

    }
    echanger_couple(tab1,tab2,comptage,debut);
    return(comptage);
}

void tri_rapide_bis_couple(int* tab1, int* tab2, int debut, int fin)
{
    if(debut<fin)
    {
        int pivot=partition_couple(tab1,tab2,debut,fin);
        tri_rapide_bis_couple(tab1,tab2,debut,pivot-1);
        tri_rapide_bis_couple(tab1,tab2,pivot+1,fin);
    }
}

void tri_rapide_couple(int* tab1, int* tab2, int taille)
{
    tri_rapide_bis_couple(tab1,tab2,0,taille-1);
}

void echanger(int* tab, int i, int j)
{
     int memoire;
     memoire=tab[i];
     tab[i]=tab[j];
     tab[j]=memoire;
}

int partition(int* tab, int debut, int fin)
{
    int comptage=debut;
    int pivot=tab[debut];
    int i;
    for(i=debut+1;i<=fin;i++)
    {
        if(tab[i]<pivot)
        {
            comptage++;
            echanger(tab,comptage,i);
        }

    }
    echanger(tab,comptage,debut);
    return(comptage);
}

void tri_rapide_bis(int* tab, int debut, int fin)
{
    if(debut<fin)
    {
        int pivot=partition(tab,debut,fin);
        tri_rapide_bis(tab,debut,pivot-1);
        tri_rapide_bis(tab,pivot+1,fin);
    }
}

void tri_rapide(int* tab, int taille)
{
    tri_rapide_bis(tab,0,taille);
}

void afficher_ordre_fichier(int* tab_pouls, int* tab_temps, int taille)
{
    int i;
    for(i=0;i<taille;i++)
    {
        printf("%d,%d\n", tab_temps[i], tab_pouls[i]);
    }
}

void afficher_ordre_croissant(int* tab_pouls, int* tab_temps, int taille)
{
    int* tab_pouls_copy;
    tab_pouls_copy = tab_pouls;
    int* tab_temps_copy;
    tab_temps_copy = tab_temps;
    tri_rapide_couple(tab_pouls_copy, tab_temps_copy, taille);
    for(int i=0;i<taille;i++)
    {
        printf("%d,%d\n", tab_temps_copy[i], tab_pouls_copy[i]);
    }
}

void afficher_ordre_decroissant(int* tab_pouls, int* tab_temps, int taille)
{
    int i;
    int *tab_pouls_copy = tab_pouls;
    tab_pouls_copy = tab_pouls;
    int *tab_temps_copy = tab_temps;
    tab_temps_copy = tab_temps;
    tri_rapide_couple(tab_pouls_copy, tab_temps_copy, taille);
    for(i=taille-1;i>=0;i--)
    {
        printf("%d,%d\n", tab_temps_copy[i], tab_pouls_copy[i]);
    }
}

void recherche_temps_particulier(int* tab_pouls, int* tab_temps, int taille)
{
    int temps;
    int valeur;
    int indice;
    printf("A quel temps est la valeur que vous voulez ?\n");
    scanf("%d", &temps);
    indice = recherche_dicho(tab_temps, taille, temps);
    valeur = tab_pouls[indice];
    printf("%d", valeur);
}

void moyenne(int* tab_pouls, int* tab_temps, int taille)
{
    int indice_debut;
    int indice_fin;
    int taille_debut;
    int taille_fin;
    float m_haut = 0;
    float m;
    float nombre_indice;
    printf("A quel temps voulez vous commencer la moyenne ?\n");
    scanf("%d", &taille_debut);
    printf("A quel temps voulez vous terminer la moyenne ?\n");
    scanf("%d", &taille_fin);
    indice_debut = recherche_dicho(tab_temps, taille, taille_debut);
    indice_fin = recherche_dicho(tab_temps, taille, taille_fin);
    nombre_indice = (indice_fin - indice_debut) + 1;
    while(indice_debut <= indice_fin)
    {
        m_haut += tab_pouls[indice_debut];
        indice_debut++;
    }
    m = m_haut/nombre_indice;
    printf("La moyenne entre %d et %d est de %lf\n",taille_debut, taille_fin, m);
}

void afficher_nombre_de_lignes(int taille)
{
    printf("La memoire utilise %d lignes", taille);
}

void afficher_pouls_max(int* tab_pouls, int* tab_temps, int taille)
{
    int* tab_pouls_copy = tab_pouls;
    int pouls_max;
    int indice;
    int temps;
    tri_rapide(tab_pouls_copy, taille);
    pouls_max = tab_pouls_copy[taille-1];
    indice = recherche_dicho(tab_pouls, taille, pouls_max);
    temps = tab_temps[indice];
    printf("Le pouls maximum est de %d a la valeur du temps %d", pouls_max, temps);
}

void afficher_pouls_min(int* tab_pouls, int* tab_temps, int taille)
{
    int* tab_pouls_copy = tab_pouls;
    int pouls_min;
    int indice;
    int temps;
    tri_rapide(tab_pouls_copy, taille);
    pouls_min = tab_pouls_copy[0];
    indice = recherche_dicho(tab_pouls, taille, pouls_min);
    temps = tab_temps[indice];
    printf("Le pouls minimum est de %d a la valeur du temps %d", pouls_min, temps);
}

int quitter()
{
    return 0;
}

int	nb_lignes() 
{
	FILE* fichier = NULL;
	int caractereActuel;
	int compteur;
	caractereActuel = 0;
	compteur = 1;
	fichier = fopen("Battements.csv", "r");

	if (fichier != NULL)
	{
		//on peut lire dans le fichier

		while (caractereActuel != EOF)
		{
			caractereActuel = fgetc(fichier);
			if (caractereActuel == '\n')
				compteur++;
		}
		fclose(fichier);
		return compteur;
	}
	else
	{
		//on ne peut pas lire dans le fichier, message d'erreur
		printf("Impossible d'ouvrir le fichier Battements.csv");
		exit(0);
	}
}
