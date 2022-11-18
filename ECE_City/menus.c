#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <string.h>

#include "extras.h"
#include "structures.h"
#include "initPartie.h"
#include "boucleJeu.h"


#include "menus.h"

void menuPrincipal() {

    // Chargement des images
    t_bitmapsMenus* bitmapsMenus = allouerMenus();

    // Demarrage de la musique et affichage du menu principal
    play_midi(bitmapsMenus->musique, 1);
    blit(bitmapsMenus->menuPrincipal, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    // Lancement de la boucle des menus
    while (1)
    {
        if ( mouse_y>=250 && mouse_y<=335 && mouse_x>=934 && mouse_x<=1075  && mouse_b) // Afficher le menu Play
        {
            while(mouse_b){} // On attend que le joueur relache le clic
            menuPlay(bitmapsMenus);    // PLAY
            blit(bitmapsMenus->menuPrincipal, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }
        if ( mouse_y>=358 && mouse_y<=445 && mouse_x>=934 && mouse_x<=1075  && mouse_b) // Afficher le menu Option
        {
            while(mouse_b){} // On attend que le joueur relache le clic
            menuOptions(bitmapsMenus);  // OPTION
            blit(bitmapsMenus->menuPrincipal, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }
        if ( mouse_y>=468 && mouse_y<=555 && mouse_x>=934 && mouse_x<=1075  && mouse_b) exit(0); // Quitter
    }
}

// Chargement des immages et de la musique
t_bitmapsMenus* allouerMenus() {

    t_bitmapsMenus* bitmapsMenus = malloc(sizeof(t_bitmapsMenus));

    bitmapsMenus->menuPrincipal = load_bitmap("ressourcesMenus/menuPrincipal.bmp", NULL);
    bitmapsMenus->menuPlay = load_bitmap("ressourcesMenus/menuPlay.bmp", NULL);
    bitmapsMenus->menuOption = load_bitmap("ressourcesMenus/menuOption.bmp", NULL);
    bitmapsMenus->menuChargement = load_bitmap("ressourcesMenus/menuChargement.bmp", NULL);

    bitmapsMenus->imgPause = load_bitmap("ressourcesMenus/pause.bmp", NULL);
    bitmapsMenus->imgPlay = load_bitmap("ressourcesMenus/play.bmp", NULL);

    bitmapsMenus->musique = load_midi("ressourcesMenus/jazz4.mid");
    bitmapsMenus->etatMusique = 1; // On lance la musique avec le programme

    if (!bitmapsMenus->menuPrincipal || !bitmapsMenus->menuPlay || !bitmapsMenus->menuOption || !bitmapsMenus->menuChargement || !bitmapsMenus->imgPause || !bitmapsMenus->imgPlay || !bitmapsMenus->musique) {
        debug("Erreur lors du chargement des images et de la musique");
        exit(1);
    }

    return bitmapsMenus;
}

int menuPlay(t_bitmapsMenus* bitmapsMenus) {

    // Affichage initial du menu
    blit(bitmapsMenus->menuPlay, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    t_partie* partieALancer = NULL;

    while (1)
    {
        if ( mouse_y>=280 && mouse_y<=550 && mouse_x>=200 && mouse_x<=400  && mouse_b)
        {
            while(mouse_b){} // On attend que le joueur relache le clic
            partieALancer = newgame(bitmapsMenus);  // Creation d'une nouvelle partie
            blit(bitmapsMenus->menuPlay, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }
        if ( mouse_y>=290 && mouse_y<=500 && mouse_x>=850 && mouse_x<=1125  && mouse_b)
        {
            while(mouse_b){} // On attend que le joueur relache le clic
            partieALancer = menuChargement(bitmapsMenus); // Chargement partie
            blit(bitmapsMenus->menuPlay, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }
        if (partieALancer) {
            boucleJeu(partieALancer);
            return 0;
        }
        if ( mouse_y>=580 && mouse_y<=680 && mouse_x>=565 && mouse_x<=695  && mouse_b) return 0;     // RETOUR EN ARRIERE "BACK"
    }

}
int menuOptions(t_bitmapsMenus* bitmapsMenus)
{
    // Affichage initial du menu
    blit(bitmapsMenus->menuOption,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    if (bitmapsMenus->etatMusique==0) draw_sprite(screen,bitmapsMenus->imgPause,599,380);
    if (bitmapsMenus->etatMusique==1) draw_sprite(screen,bitmapsMenus->imgPlay,589,378);

    while (1)
    {
        if ( mouse_y>=380 && mouse_y<=465 && mouse_x>=600 && mouse_x<=675 && mouse_b)
        {
            bitmapsMenus->etatMusique=!bitmapsMenus->etatMusique;
            blit(bitmapsMenus->menuOption,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            if (bitmapsMenus->etatMusique==0) {
                draw_sprite(screen,bitmapsMenus->imgPause,599,380);
                stop_midi();
            }
            if (bitmapsMenus->etatMusique==1) {
                draw_sprite(screen,bitmapsMenus->imgPlay,589,378);
                play_midi(bitmapsMenus->musique,1);
            }
            while(mouse_b){} // On attend que le joueur relache le clic
        }
        if ( mouse_y>=340 && mouse_y<=440 && mouse_x>=170&& mouse_x<=300 && mouse_b) return 0;     // RETOUR EN ARRIERE "BACK"
    }
}

t_partie* menuChargement(t_bitmapsMenus* bitmapsMenus)
{

    // Affichage initial du menu
    blit(bitmapsMenus->menuChargement, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    FILE*file;
    char nom[100];
    char fichier[200];
    int x,y,nb;
    t_game Temp;

    FILE* NomSave = fopen("sauvegardes/sauvegardesNoms.txt","r+");

    while (1)
    {

        // Affichage des noms des sauvegardes
        /// Reaffichage du menu (mauvais, a traiter)
        rewind(NomSave);
        x=440;
        y=290;
        while (!feof(NomSave))
        {
            fscanf(NomSave,"%s",nom);
            textprintf_ex(screen,font,x-(strlen(nom)/2)*7,y,makecol(255,200,220),-1,"%s",nom);
            x+=210;
            if(x>860)
            {
                x=440;
                y+=140;
            }
        }

        nb = -1;
        rewind(NomSave);

        // Gestion des clics (sur quelle sauvegarde l'utilisateur a clique
        if ( mouse_y >= 250 && mouse_y <= 330 && mouse_x >= 370 && mouse_x <= 510 && mouse_b)   nb=0;
        if ( mouse_y >= 250 && mouse_y <= 330 && mouse_x >= 585 && mouse_x <= 725 && mouse_b)   nb=1;
        if ( mouse_y >= 250 && mouse_y <= 330 && mouse_x >= 800 && mouse_x <= 940 && mouse_b)   nb=2;
        if ( mouse_y >= 390 && mouse_y <= 470 && mouse_x >= 370 && mouse_x <= 510 && mouse_b)   nb=3;
        if ( mouse_y >= 390 && mouse_y <= 470 && mouse_x >= 585 && mouse_x <= 725 && mouse_b)   nb=4;
        if ( mouse_y >= 390 && mouse_y <= 470 && mouse_x >= 800 && mouse_x <= 940 && mouse_b)   nb=5;
        if ( mouse_y >= 530 && mouse_y <= 605 && mouse_x >= 370 && mouse_x <= 510 && mouse_b)   nb=6;
        if ( mouse_y >= 530 && mouse_y <= 605 && mouse_x >= 585 && mouse_x <= 725 && mouse_b)   nb=7;
        if ( mouse_y >= 530 && mouse_y <= 605 && mouse_x >= 800 && mouse_x <= 940 && mouse_b)   nb=8;

        if(nb!=-1)
        {
            strcpy(fichier,"sauvegardes/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,"/");
            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);

            file=fopen(fichier,"r");
            if (!file) {
                debug("Erreur d'ouverture du fichier");
                exit(1);
            }


            fscanf(file,"%s",nom);
            fscanf(file,"%d",&Temp.temps);
            fscanf(file,"%d",&Temp.argent);

            textprintf_ex(screen,font,(140- (strlen(nom)/2)*7),205, makecol(0,0,0),-1,"%s",nom);
            textprintf_ex(screen,font,120,400, makecol(0,0,0),-1,"%d",Temp.temps);
            textprintf_ex(screen,font,120,585, makecol(0,0,0),-1,"%d",Temp.argent);
            fclose(file);

            /// Redondant
            return chargerPartie(nom, strlen(nom));
        }

        // Retour en arriere
        if ( mouse_y >= 35 && mouse_y <= 145 && mouse_x >= 1120 && mouse_x <= 1250 && mouse_b) return NULL;
    }

}

t_partie* newgame(t_bitmapsMenus* bitmapsMenus)
{
    char nom[100] = {'\0'};
    int lignes;
    int colonnes;

    while (!nomValide(nom, strlen(nom)))
    {
        allegro_message("Rentre le nom de ta ville dans la console");
        printf("Nom de ta ville : ");
        gets(nom);
    }

    printf("Lignes de ta ville : ");
    scanf("%d",&lignes);
    printf("Colonnes de ta ville : ");
    scanf("%d",&colonnes);

    return nouvellePartie(nom, strlen(nom), lignes, colonnes);
}

// Verifie la validite d'un nom de sauvegarde: pas vide, pas plus de 16 caracteres, pas de caracteres speciaux
int nomValide(char* nom, int taille)
{
    if (taille == 0 || taille > 16)
        return 0;

    for (int i = 0; i < taille; ++i)
    {
        if (nom[i] == ' ' || nom[i] == '\n' || nom[i] == '\t' || nom[i] == '\r')
            return 0;
    }
    return 1;
}

/// Inutilise
int* convertion(int second)
{
    int* tabHeure;
    tabHeure=malloc(sizeof (int )*3);
    tabHeure[0]=second;
    tabHeure[1]=tabHeure[0]/60;
    tabHeure[2]=tabHeure[1]/60;
    tabHeure[1]=tabHeure[1]-tabHeure[2]*60;
    tabHeure[0]=tabHeure[0]-tabHeure[1]*60-tabHeure[2]*60*60;
    printf("%d\n%d\n%d",tabHeure[0],tabHeure[1],tabHeure[2]);
    return tabHeure;
}

/// Inutilise
t_game* checkSauv(char* fichier)
{
    t_game* Sauv;
    Sauv=malloc(sizeof(t_game));
    FILE* dre=fopen("ressourcesMenus/FreshBeer.txt","r");

    if (dre==NULL)
    {
        printf("Erreur fichier introuvable");
        return NULL;
    }


    fscanf(dre,"%s",Sauv->nom);
    fscanf(dre,"%d",&(Sauv->temps));
    fscanf(dre,"%d",&(Sauv->argent));
    printf("%d\n",Sauv->temps);

    fclose(dre);
    return Sauv;
}