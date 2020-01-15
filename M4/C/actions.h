#ifndef ACTIONS		//si le macro nommé ACTIONS n’est pas défini, lire la suite des instructions
#define ACTIONS 	//Définir le macro nommé ACTIONS

//Prototypes de fonctions ici
void afficher_ordre_fichier(int* tab_pouls, int* tab_temps, int taille);
void afficher_ordre_croissant(int* tab_pouls, int* tab_temps, int taille);
void afficher_ordre_decroissant(int* tab_pouls, int* tab_temps, int taille);
int recherche_temps_particulier(int* tab_pouls, int* tab_temps, int taille);
int moyenne(int* tab_pouls, int* tab_temps, int taille);
void afficher_nombre_de_lignes(int taille);
void afficher_pouls_max(int* tab_pouls, int* tab_temps, int taille);
void afficher_pouls_min(int* tab_pouls, int* tab_temps, int taille);
int	nb_lignes();

#endif			//Fin du ifndef précédent
