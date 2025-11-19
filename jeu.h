#ifndef JEU_H
#define JEU_H

#include "carte.h"

int distribuer_carte(int carte_joueur[], int carte_ia[], Carte *jeu, int taille);int distribuer_carte(int carte_joueur[], int carte_ia[], Carte *jeu, int taille);
void Pioche(Carte *jeu, int taille);
int piocherCarte(int *main_joueur, int *taille_main, int *taille_deck, Carte *jeu);

#endif