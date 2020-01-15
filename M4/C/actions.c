#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

int recherche_dicho(int* tab, int taille, int valeur)
{
    int trouve;
    int id;
    int im;
    trouve = FALSE; //Initialisation de trouve à la valeur false donc au début de la fonction on n'a pas trouver la valeur
    id = 0;
    while(trouve == FALSE && ((taille- id)>1))
    {
        im = (id+taille)/2; //diviser par deux pour avoir l'indice permettant de savoir ou ce trouve la valeur recherchée
        if(tab[im]==valeur)
        {
            trouve = TRUE; //Si la valeur de comparaison est égal à la valeur recherchée alors on a trouver la valeur
        }
        if(tab[im]>valeur)
        {
            taille = im; //Si la valeur de comparaison est suppérieur alors la taille de recherches prends la valeur de l'indice de comparaison
        }
        else
        {
            id=im; //Sinon l'indice du début prends la valeur de l'indice de comparaison
        }
    }
    if(tab[id]==valeur)
    {
        return(id); //Si la valeur du début est égal à la valeur recherchée alors on retourne la valeur du début
    }
    else
    {
        return(-1); //Sinon la valeur recherchée n'est pas dans le tableau est on retourne -1
    }
}

void echanger_couple(int* tab1, int* tab2, int i, int j) //Fonction permettant d'échanger les valeurs des deux tableaux
{
     int memoire1;
     int memoire2;
     memoire1=tab1[i]; //Fait un échange du permier tableaux dans la mémoire
     tab1[i]=tab1[j];
     tab1[j]=memoire1;
     memoire2=tab2[i]; //fait un échange du deuxième tableaux dans la mémoire
     tab2[i]=tab2[j];
     tab2[j]=memoire2;
}

int partition_couple(int* tab1, int* tab2, int debut, int fin) //Fonction permettant de changer la valeur du pivot
{
    int comptage=debut;
    int pivot=tab1[debut]; //change la valeur du pivot
    int i;
    for(i=debut+1;i<=fin;i++) //Pour toutes les valeurs du tableau
    {
        if(tab1[i]<pivot)
        {
            comptage++;
            echanger_couple(tab1,tab2,comptage,i); //Si le tableau d'indice i est inférieur eu pivot échanger
        }

    }
    echanger_couple(tab1,tab2,comptage,debut); //Echanger les deux tableaux dans tout les cas avec la valeur comptage et début
    return(comptage);
}

void tri_rapide_bis_couple(int* tab1, int* tab2, int debut, int fin)
{
    if(debut<fin)
    {
        int pivot=partition_couple(tab1,tab2,debut,fin); //crée un pivot qui prendra la valeur de la fonction partition
        tri_rapide_bis_couple(tab1,tab2,debut,pivot-1); //Répéte l'action pour modifier le pivot
        tri_rapide_bis_couple(tab1,tab2,pivot+1,fin); //Répéte l'action pour modifier le pivot
    }
}

void tri_rapide_couple(int* tab1, int* tab2, int taille) //Fonction permettant de faire un tri rapide avec deux tableaux
{
    tri_rapide_bis_couple(tab1,tab2,0,taille-1); //Lance la fonction tri rapide bis
}

void echanger(int* tab, int i, int j) //Fonction permettant d'échanger deux valeurs du tableau
{
     int memoire;
     memoire=tab[i]; //Fait un échange du tableau dans la mémoire
     tab[i]=tab[j];
     tab[j]=memoire;
}

int partition(int* tab, int debut, int fin) //Fonction permettant de changer la valeur du pivot
{
    int comptage=debut;
    int pivot=tab[debut]; //change la valeur du pivot
    int i;
    for(i=debut+1;i<=fin;i++) //Pour toutes les valeurs du tableau
    {
        if(tab[i]<pivot)
        {
            comptage++;
            echanger(tab,comptage,i); //Si le tableau d'indice i est inférieur eu pivot échanger
        }

    }
    echanger(tab,comptage,debut); //Echanger dans tout les cas avec la valeur comptage et début
    return(comptage);
}

void tri_rapide_bis(int* tab, int debut, int fin)
{
    if(debut<fin)
    {
        int pivot=partition(tab,debut,fin); //crée un pivot qui prendra la valeur de la fonction partition
        tri_rapide_bis(tab,debut,pivot-1); //Répéte l'action pour modifier le pivot
        tri_rapide_bis(tab,pivot+1,fin);  //Répéte l'action pour modifier le pivot
    }
}

void tri_rapide(int* tab, int taille) //Fonction permettant de faire un tri rapide
{
    tri_rapide_bis(tab,0,taille-1); //Lance la fonction tri rapide bis
}

int recherche_temps_existant(int* tab_temps, int temps, int taille) //Fonction permettant de rechercher si un temps particuliers existe dans le tableau
{
    int i;
    for(i=0;i<taille;i++) //Pour tout le tableau de 0 à taille-1
    {
        if(temps==tab_temps[i])
        {
            return 1; //Retourner 1 si on trouve la valeur dans le tableau
        }
    }
    return 0; //Retourner 0 si on ne trouve pas la valeur
}

void afficher_ordre_fichier(int* tab_pouls, int* tab_temps, int taille) //Fonction permettant d'afficher les valeurs dans l'ordre du fichier .csv
{
    int i;
    for(i=0;i<taille;i++)
    {
        printf("%d,%d\n", tab_temps[i], tab_pouls[i]); //Affiche les deux tableaux de 0 à la taille maximal du tableau
    }
}

void afficher_ordre_croissant(int* tab1, int* tab2, int taille) //Fonction permettant d'afficher des tableaux de façon croissante
{
    tri_rapide_couple(tab1, tab2, taille); //Lance la fonction pour faire un tri rapide
    for(int i=0;i<taille;i++)
    {
        printf("%d,%d\n", tab1[i], tab2[i]); //Affiche les deux tableaux dans l'ordre du tri
    }
}

void afficher_ordre_decroissant(int* tab1, int* tab2, int taille) //Fonction permettant d'afficher des tableaux de façon decroissante
{
    tri_rapide_couple(tab1, tab2, taille); //Lance la fonction pour faire un tri rapide
    for(int i=taille-1;i>0;i--)
    {
        printf("%d,%d\n", tab1[i], tab2[i]); //Affiche les deux tableaux dans l'ordre du tri
    }
}

int recherche_temps_particulier(int* tab_pouls, int* tab_temps, int taille) //Fonction permettant de donner la valur du pouls par rapport à la valeur du temps donnée
{
    int temps;
    int valeur;
    int indice;
    int i;
    printf("A quel temps est la valeur que vous voulez ?\n");
    scanf("%d", &temps);
    for(i=0;i<taille;i++)
    {
        if(temps==tab_temps[i]) //Vérifie si la valeur est dans le tableau temps
        {
            indice = recherche_dicho(tab_temps, taille, temps); //Fait une recherche dichotomique pour trouver l'indice de la valeur du temps dans le tableau
            valeur = tab_pouls[indice]; //Calcule la valeur du pouls par rapport à l'indice du temps donnée
            printf("La valeur correspondante est %d", valeur);
        }
    }
    return 0; //Retourne 0 quand la valeur du temps n'est pas dans le tableau
}

int moyenne(int* tab_pouls, int* tab_temps, int taille) //Fonction permettant de calculer la moyenne de pouls dans une plage de temps donnée
{
    int indice_debut;
    int indice_fin;
    int temps_debut;
    int temps_fin;
    float m_haut = 0;
    float m;
    float nombre_indice;
    printf("A quel temps voulez vous commencer la moyenne ?\n");
    scanf("%d", &temps_debut);
    printf("A quel temps voulez vous terminer la moyenne ?\n");
    scanf("%d", &temps_fin);
    if((recherche_temps_existant(tab_temps, temps_debut, taille)==1)&&(recherche_temps_existant(tab_temps, temps_fin,taille)==1)&&(temps_debut<temps_fin)) //Vérifie si les deux valeurs du temps sont dans le tableau et si la temps donner pour le début est inférieur au temps donnée pour la fin
    {
        indice_debut = recherche_dicho(tab_temps, taille, temps_debut); //On recherche l'indice du temps pour le début de l'opération
        indice_fin = recherche_dicho(tab_temps, taille, temps_fin); //On recherche l'indice du temps pour lea fin de l'opération
        nombre_indice = (indice_fin - indice_debut) + 1; //On calcule ne nombre de donnée utiliser durant l'opération
        while(indice_debut <= indice_fin)
        {
            m_haut += tab_pouls[indice_debut]; //Tant que indice du début est inférieur ou égal à l'indice du début additionner les valeurs du pouls
            indice_debut++;
        }
        m = m_haut/nombre_indice; //diviser cette addition par le nombre de donnée (calcule de la moyenne)
        printf("La moyenne entre %d et %d est de %lf\n",temps_debut, temps_fin, m);
    }
    else
    {
        return 0; //Sinon retouner 0 pour ne pas réaliser l'opération
    }
}

void afficher_nombre_de_lignes(int taille) //Fonction permettant d'afficher le nombre de lignes utlisée dans la mémoire
{
    printf("La memoire utilise %d lignes", taille);
}

void afficher_pouls_max(int* tab_pouls, int* tab_temps, int taille) //Fonction permettant d'afficher le pouls maximum
{
    int pouls_max;
    int temps;
    tri_rapide_couple(tab_pouls, tab_temps, taille); //Faire un tri rapide
    pouls_max = tab_pouls[taille-1]; //Calculer la valeur du pouls maximum
    temps = tab_temps[taille-1]; //Calculer la valeur du temps correspondante
    printf("Le pouls maximum est de %d a la valeur du temps %d", pouls_max, temps);
}

void afficher_pouls_min(int* tab_pouls, int* tab_temps, int taille) //Fonction permettant d'afficher le pouls minimal
{
    int pouls_min;
    int temps;
    tri_rapide_couple(tab_pouls, tab_temps, taille); //Faire un tri rapide
    pouls_min = tab_pouls[0]; //Calculer la valeur du pouls maximum
    temps = tab_temps[0]; //Calculer la valeur du temps correspondante
    printf("Le pouls minimum est de %d a la valeur du temps %d", pouls_min, temps);
}

int quitter()
{
    exit(1);
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
