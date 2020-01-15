#include <stdio.h>
#include <stdlib.h>

void generationCode(int choix)
{
	FILE* fichier = NULL; 
	fichier = fopen("param.h", "w+"); //on ouvre param.h avec une autorisation de lecture, écriture et une réinitialisation du contenu du fichier au lancement

	if (fichier != NULL) //Si param.h a bien été ouvert
	{
		//on peut lire dans le fichier
		fprintf(fichier, "#define MODE %d", choix); //on écrit dans le fichier param.h
		fclose(fichier); //On ferme le fichier qui a été ouvert
	}
	else
	{
		//on ne peut pas lire dans le fichier, message d'erreur
		printf("Impossible d'ouvrir le fichier Battements.csv");
	}

}