#include "carte.h"
#include <stdlib.h>
#include <string.h>

void afficherCarte(Carte carte) {
    //Fonction qui affiche la carte
    printf("%s %c\n", carte.type, carte.couleur);
}

int creerJeuUNO(Carte *jeu) {
    //Fonction qui crée le deck du uno
    int index = 0;
    char couleurs[4] = {'R', 'J', 'B', 'V'};
    
    //Création des cartes de base
    for (int c = 0; c < 4; c++) {
        jeu[index].type[0] = '0';
        jeu[index].type[1] = '\0';
        jeu[index].couleur = couleurs[c];
        index++;

        for (int numero = 1; numero <= 9; numero++) {
            for (int ex = 0; ex < 2; ex++) {
                jeu[index].type[0] = '0' + numero;
                jeu[index].type[1] = '\0';
                jeu[index].couleur = couleurs[c];
                index++;
            }
        }
        //Création des cartes spéciales
        const char *speciaux[] = {"+2", "RV", "PS"};
        for (int j = 0; j < 3; j++) {
            for (int ex = 0; ex < 2; ex++) {
                strcpy(jeu[index].type, speciaux[j]);
                jeu[index].couleur = couleurs[c];
                index++;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        strcpy(jeu[index].type, "JJ");
        jeu[index].couleur = 'N';
        index++;
    }
    for (int i = 0; i < 4; i++) {
        strcpy(jeu[index].type, "+4");
        jeu[index].couleur = 'N';
        index++;
    }

    return index;
}


void MelangerJeu(Carte *jeu, int taille) {
    //fonction qui return la fonction mélangé
    for (int i = taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carte temp = jeu[i];
        jeu[i] = jeu[j];
        jeu[j] = temp;
    }
}

void affiche_carte(int index_jeu, Carte *jeu) {
    //fonction qui affiche une carte à un index donné   
    printf("%s %c\n", jeu[index_jeu].type, jeu[index_jeu].couleur);
}