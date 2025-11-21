#ifndef CARTE_H
#define CARTE_H

#include <stdio.h>

typedef struct {
    char type[4];
    char couleur;
} Carte;

void afficherCarte(Carte carte);
int creerJeuUNO(Carte *jeu);
void MelangerJeu(Carte *jeu, int taille);
void affiche_carte(int index_jeu, Carte *jeu);

#endif