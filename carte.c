#include "carte.h"
#include <stdlib.h>
#include <string.h>

void afficherCarte(Carte carte) {
    printf("%s %c\n", carte.type, carte.couleur);
}

int creerJeuUNO(Carte *jeu) {
    int index = 0;
    char couleurs[4] = {'R', 'J', 'B', 'V'};
    
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