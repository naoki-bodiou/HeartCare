int TestPoul()
{
  int a;
  a = random(1,7); //une valeur aléatoire est affecté à la variable a
  if (a == 6)
    MonitorDisplay(temps(), RandomPoul()); //si la valeur de a est égale à 6, on lance la fonction MonitorDisplay avec des arguments donné par deux fonctions
}

//Fonction renvoyant une valeur de poul aléatoire entre 70 et 90.
int RandomPoul() 
{
 int pouls;
 pouls = random(70,91); //affecte à pouls un valeur aléatoire
 return pouls;
}

//Fonction affichant le temps passé depuis le démarrage de l'Arduino en miliseconde
long temps() 
{
// On utilise uint32_t pour assurer suffisamment d'espace mémoire
  uint32_t temps = millis();
  return temps;
}

//Fonction permettant d'afficher des valeurs dans le Moniteur Série
void MonitorDisplay(long temps, int pouls) {
  Serial.print(temps);
  Serial.print(",");
  Serial.println(pouls);
}
