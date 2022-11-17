#include <stdio.h>
#include <stdlib.h>

#include "extras.h"
#include "structures.h"

#include "boucleJeu.h"

void boucleJeu(t_partie* partie) {

    // Recuperation du temps ecoule depuis le debut du programme
    clock_t tempsInitial = clock()/(CLOCKS_PER_SEC/1000) - partie->tempsDeJeu;
    
    while (1)
    {
        /// Mise a jour du temps de jeu
        partie->tempsDeJeu = (clock()/(CLOCKS_PER_SEC/1000)) - tempsInitial;

        printf("Temps de jeu : %d\n", partie->tempsDeJeu);

        // Calculer le temps
        // Afficher les bitmaps
        // Modifier les valeurs
        // Verifier les touches
    }
    


}