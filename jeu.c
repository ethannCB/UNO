#include "jeu.h"
#include <stdio.h>

int distribuer_carte(int carte_joueur[], int carte_ia[], Carte *jeu, int taille) {
    (void)jeu;
    int index_deck = taille - 1;
    
    for (int i = 0; i < 7; i++) {
        carte_joueur[i] = index_deck--;
        carte_ia[i] = index_deck--;
    }
    
    return index_deck + 1;
}


void Pioche(Carte *jeu, int taille) {
    (void)jeu;
    if (taille <= 0) {
        printf("Le jeu est vide.\n");
    } else {
        printf("Il reste %d cartes.\n", taille);
    }
}

int piocherCarte(int *main_joueur, int *taille_main, int *taille_deck, Carte *jeu) {
    (void)jeu;
    if (*taille_deck <= 0) {
        printf("Plus de cartes!\n");
        return -1;
    }
    
    (*taille_deck)--;
    main_joueur[*taille_main] = *taille_deck;
    (*taille_main)++;
    
    return main_joueur[*taille_main - 1];
}