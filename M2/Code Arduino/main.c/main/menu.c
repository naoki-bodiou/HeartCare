#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"

void menu()
{
	int choix;
	printf("\nBonjour,\n\nTapez 1 pour allumer toutes les LEDS simultanement\nTapez 2 pour allumer une LED sur 2\nTapez 3 pour allumer une LED sur 3\nTapez 4 pour allumer en mode chenille\n");
	scanf("%d", &choix);
	
	if (choix >= 1 && choix <= 4)
	{
		generationCode(choix); // si choix est entre ou égal à 1 et 4 la fonction generationCode se lance
	}
	else
	{
		printf("\nNe pas inserer une valeur pour troll merci..:)\n"); //si choix est différent de 1,2,3 ou 4, un message d'erreur s'affiche
		menu(); //le menu se relance
	}
	
}