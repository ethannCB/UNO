#include "carte.h"
#include "jeu.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
    Carte jeu[108];
    int carte_joueur[20];
    int carte_ia[20];
    int taille_joueur = 7;
    int taille_ia = 7;
    
    int taille_deck = creerJeuUNO(jeu);
    srand((unsigned)time(NULL));
    MelangerJeu(jeu, taille_deck);
    
    taille_deck = distribuer_carte(carte_joueur, carte_ia, jeu, taille_deck);
    
    int carte_pile = taille_deck - 1;
    taille_deck--;
    
    printf("=== JEU UNO ===\n");
    printf("Premiere carte: ");
    affiche_carte(carte_pile, jeu);
    
    int tour_numero = 1;
    int skip_joueur = 0;
    int skip_ia = 0;
    
    while (1) {
        printf("\n--- Tour %d ---\n", tour_numero);
        
        printf("\n** VOTRE TOUR **\n");
        carte_pile = tourJoueur(carte_joueur, &taille_joueur, jeu, carte_pile, &taille_deck, &skip_joueur);
        
        if (win(taille_joueur)) {
            printf("\n*** VOUS GAGNEZ! ***\n");
            break;
        }
        
        printf("\n** TOUR IA **\n");
        carte_pile = tour(carte_ia, &taille_ia, jeu, carte_pile, &taille_deck, &skip_ia);
        
        if (win(taille_ia)) {
            printf("\n*** IA GAGNE! ***\n");
            break;
        }
        
        tour_numero++;
    }
    
    return 0;
}