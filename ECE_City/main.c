#include <stdio.h>
#include <stdlib.h>

#include "extras.h"
#include "structures.h"
#include "initPartie.h"

// main function

int main() {

    printf("Hello World!\n");

    // Test de chargement de partie
    t_partie* partie = chargerPartie("test", 4);

    // Affichage de la partie ----------------------------------

    // Nom de la partie
    printf("Nom de la partie : %s\n", partie->nomPartie);

    // Temps de jeu
    printf("Temps de jeu : %d\n", partie->tempsDeJeu);

    // Taille du plateau
    printf("Taille du plateau : %d x %d\n", partie->lignes, partie->colonnes);

    // Argent
    printf("Argent : %d\n", partie->argent);

    // Types
    for (int i = 0; i < partie->lignes; i++) {
        for (int j = 0; j < partie->colonnes; j++) {
            for (int k = 0; k < 3; k++) {
                printf("Type de la case (%d, %d, %d) : %d\n", i, j, k, partie->typeCase[i][j][k]);
            }
        }
    }

    // Affichage des elements
    for (int i = 0; i < partie->lignes; i++)
    {
        for (int j = 0; j < partie->colonnes; j++) {
            for (int k = 0; k < 3; k++) {
                if (partie->typeCase[i][j][k] == 2) {
                    t_residentiel* residentiel = (t_residentiel*)partie->plateau[i][j][k];
                    printf("Residentiel (%d, %d, %d) : niveau %d\n", i, j, k, residentiel->niveau);
                }
            }
        }
    }
    

    // UI
    printf("UI actuel : %d\n", partie->UIActuel);

    // Fin de l'affichage de la partie --------------------------

    // Boucle infinie
    for(;;);

    return 0;
}