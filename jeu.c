#include "jeu.h"
#include <stdio.h>
#include <string.h>


int cartes_a_piocher = 0;
char couleur_joker = 'N';



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

int CartePosee(int index_jeu, int index_joueur, Carte *jeu) {
    // Jokers peuvent toujours être posés
    if (strcmp(jeu[index_joueur].type, "JJ") == 0 || 
        strcmp(jeu[index_joueur].type, "+4") == 0) {
        return 1;
    }
    
    // Si un joker a été joué, vérifier la couleur choisie
    char couleur_a_battre = jeu[index_jeu].couleur;
    if (couleur_joker != 'N') {
        couleur_a_battre = couleur_joker;
    }
    
    // Si on doit contrer un +2, seul un +2 peut être joué
    if (cartes_a_piocher > 0 && strcmp(jeu[index_jeu].type, "+2") == 0) {
        return strcmp(jeu[index_joueur].type, "+2") == 0;
    }
    
    if (jeu[index_joueur].couleur == couleur_a_battre) {
        return 1;
    }
    if (strcmp(jeu[index_joueur].type, jeu[index_jeu].type) == 0) {
        return 1;
    }
    return 0;
}



void appliquerEffet(Carte carte, int *tour_suivant_skip) {
    if (strcmp(carte.type, "+2") == 0) {
        cartes_a_piocher += 2;
        printf(">> +2! Total a piocher: %d cartes.\n", cartes_a_piocher);
    }
    else if (strcmp(carte.type, "PS") == 0) {
        *tour_suivant_skip = 1;
        printf(">> Passer! Le joueur suivant passe son tour.\n");
    }
    else if (strcmp(carte.type, "RV") == 0) {
        sens_jeu *= -1;
        printf(">> Inversion! Le sens change.\n");
    }
}

char choisirCouleur() {
    char choix;
    printf("Choisissez une couleur (R/J/B/V): ");
    scanf(" %c", &choix);
    while (getchar() != '\n');
    
    if (choix != 'R' && choix != 'J' && choix != 'B' && choix != 'V') {
        printf("Couleur invalide, rouge par defaut.\n");
        return 'R';
    }
    return choix;
}

int peutContrer(int *main, int taille, Carte *jeu) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(jeu[main[i]].type, "+2") == 0) {
            return 1;
        }
    }
    return 0;
}
