#ifndef MENUS3PROJET_MENU_H
#define MENUS3PROJET_MENU_H

#include <allegro.h>

typedef struct bitmapsMenus {

    BITMAP* menuPrincipal;
    BITMAP* menuPlay;
    BITMAP* menuOption;
    BITMAP* menuChargement;

    BITMAP* imgPause;
    BITMAP* imgPlay;

    MIDI* musique;
    int etatMusique;

}t_bitmapsMenus;

typedef struct game
{
    char* nom;
    int temps;
    int argent;
}t_game;

void menuPrincipal();
t_bitmapsMenus* allouerMenus();
int menuPlay(t_bitmapsMenus* bitmapsMenus);
t_partie* menuChargement(t_bitmapsMenus* bitmapsMenus);
t_partie* newgame(t_bitmapsMenus* bitmapsMenus);
t_game* checkSauv();
int menuOptions(t_bitmapsMenus* bitmapsMenus);
int nomValide(char* nom, int taille);



#endif //MENUS3PROJET_MENU_H
