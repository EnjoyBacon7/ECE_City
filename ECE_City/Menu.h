//
// Created by codos on 12/11/2022.
//

#ifndef MENUS3PROJET_MENU_H
#define MENUS3PROJET_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <string.h>

typedef struct game
{
    char* nom;
    int temps;
    int argent;
}t_game;

void init();
void menu1();
void menup();
void menuch(FILE*NomSave);
void newgame(FILE*NomSave);
t_game* checkSauv();
int option(int niveau);
int checkname(char* nom, int taille);



#endif //MENUS3PROJET_MENU_H
