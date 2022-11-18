#include <stdio.h>
#include <stdlib.h>

#include "extras.h"
#include "structures.h"
#include "initPartie.h"
#include "boucleJeu.h"
#include "menus.h"

#include <allegro.h>

// main function

int main() {

    // ----- Standard allegro stuff -----
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1280,720,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_mouse();
    show_mouse(screen);
    install_keyboard();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    // ----------------------------------

    menuPrincipal();

    printf("Hello World!\n");

    // Test de chargement de partie
    t_partie* partie = chargerPartie("test", 4);

    // Boucle de jeu
    boucleJeu(partie);

    /* /// TESTING
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
    */

    // Boucle infinie
    //for(;;);

    return 0;
}END_OF_MAIN()