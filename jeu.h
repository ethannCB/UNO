#ifndef JEU_H
#define JEU_H

#include "carte.h"

extern int sens_jeu;
extern int cartes_a_piocher;
extern char couleur_joker;


int distribuer_carte(int carte_joueur[], int carte_ia[], Carte *jeu, int taille);int distribuer_carte(int carte_joueur[], int carte_ia[], Carte *jeu, int taille);
void Pioche(Carte *jeu, int taille);
int piocherCarte(int *main_joueur, int *taille_main, int *taille_deck, Carte *jeu);
int CartePosee(int index_jeu, int index_joueur, Carte *jeu);
void appliquerEffet(Carte carte, int *tour_suivant_skip);
char choisirCouleur();
int peutContrer(int *main, int taille, Carte *jeu);
#endif