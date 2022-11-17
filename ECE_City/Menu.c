//
// Created by codos on 12/11/2022.
//
#include "Menu.h"

void init()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1280,720,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }  ///INITIALISATION D'ALLEGRO

    show_mouse(screen);

}
void menu1()
{
    int done=0;
    int niveau=0; ///Etat de la musique
    BITMAP* buffer; /// CREATION DU BUFFER
    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* menu;
    menu=load_bitmap("C:/Users/codos/CLionProjects/MenuS3projet/menu1.bmp",NULL);


    while (!done)
    {

        blit(menu,buffer,0,0,0,0,SCREEN_W,SCREEN_H);

        show_mouse(buffer);

        textprintf_ex(buffer,font,300,100,makecol(0,128,203),-1,"%d   x   %d", mouse_x,mouse_y);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if ( mouse_y>=250 && mouse_y<=335 && mouse_x>=934 && mouse_x<=1075  && mouse_b)
        {
            rest(200);
            menup();    ///PLAY

        }
        if ( mouse_y>=358 && mouse_y<=445 && mouse_x>=934 && mouse_x<=1075  && mouse_b)
        {
            rest(150);
            niveau=option(niveau);  ///OPTION

        }
        if ( mouse_y>=468 && mouse_y<=555 && mouse_x>=934 && mouse_x<=1075  && mouse_b)
        {
            done=1;  /// QUIT
        }
    }

}
void menup()
{
    int done=0;
    BITMAP* buffer; /// CREATION DU BUFFER
    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* menu;
    menu=load_bitmap("C:/Users/codos/CLionProjects/MenuS3projet/menup.bmp",NULL);
    FILE* NomSave= fopen("C:/Users/codos/CLionProjects/MenuS3projet/Sauvegardes.txt","r+");


    while (!done)
    {

        blit(menu,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        show_mouse(buffer);
        textprintf_ex(buffer,font,300,100,makecol(0,128,203),-1,"%d   x   %d", mouse_x,mouse_y);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        if ( mouse_y>=580 && mouse_y<=680 && mouse_x>=565 && mouse_x<=695  && mouse_b)
        {
            done=1;     ///RETOUR EN ARRIERE "BACK"
        }
        if ( mouse_y>=280 && mouse_y<=550 && mouse_x>=200 && mouse_x<=400  && mouse_b)
        {
            rest(150);
            newgame(NomSave);  ///Creation d'une nouvelle partie
        }
        if ( mouse_y>=290 && mouse_y<=500 && mouse_x>=850 && mouse_x<=1125  && mouse_b)
        {
            rest(150);
            printf("%s\n",NomSave);
            menuch(NomSave); /// Chargement partie
        }
    }
}
int option(int niveau)
{
    int done=0;

    BITMAP* buffer; /// CREATION DU BUFFER
    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* menu;
    menu=load_bitmap("C:/Users/codos/CLionProjects/MenuS3projet/menuopt.bmp",NULL);
    MIDI*musique=load_midi("C:/Users/codos/CLionProjects/MenuS3projet/jazz4.mid");
    BITMAP* coche;
    coche=load_bitmap("C:/Users/codos/CLionProjects/MenuS3projet/cochep.bmp",NULL);
    BITMAP* coches;
    coches=load_bitmap("C:/Users/codos/CLionProjects/MenuS3projet/coche.bmp",NULL);



    while (!done)
    {

        blit(menu,buffer,0,0,0,0,SCREEN_W,SCREEN_H);

        show_mouse(buffer);

        textprintf_ex(buffer,font,300,100,makecol(0,128,203),-1,"%d   x   %d", mouse_x,mouse_y);


        if ( mouse_y>=340 && mouse_y<=440 && mouse_x>=170&& mouse_x<=300 && mouse_b)
        {
            return niveau;      ///RETOUR EN ARRIERE "BACK"
        }
        if ( mouse_y>=380 && mouse_y<=465 && mouse_x>=600 && mouse_x<=675 && mouse_b&&niveau==0)
        {
            play_midi(musique, TRUE);
            niveau=1;
            rest(150);     ///ACTIVATION de la musique
        }
        if ( mouse_y>=380 && mouse_y<=465 && mouse_x>=600 && mouse_x<=675 && mouse_b&&niveau==1)
        {
            stop_midi();
            niveau=0;
            rest(150);     ///DESACTIVATION de la musique
        }
        if (niveau==0)
        {
            draw_sprite(buffer,coche,599,380);
        }
        if (niveau==1)
        {
            draw_sprite(buffer,coches,589,378);
        }

        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    }
}
void menuch(FILE*NomSave)
{
    FILE*file;
    int done=0;
    char nom[100];
    char* fichier;
    int x,y,i=0,nb=-1;
    t_game Temp;


    BITMAP* buffer; /// CREATION DU BUFFER
    buffer=create_bitmap(SCREEN_W,SCREEN_H);

    BITMAP* menu;
    menu=load_bitmap("C:/Users/codos/CLionProjects/MenuS3projet/menuch.bmp",NULL);


    while (!done)
    {

        blit(menu,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        show_mouse(buffer);

        textprintf_ex(buffer,font,300,100,makecol(0,128,203),-1,"%d   x   %d", mouse_x,mouse_y);

        x=440;
        y=290;
        rewind(NomSave);
        while (!feof(NomSave))
        {
            fscanf(NomSave,"%s",nom);


            textprintf_ex(buffer,font,x-(strlen(nom)/2)*7,y,makecol(255,200,220),-1,"%s",nom);
            x+=210;
            if(x>860)
            {
                x=440;
                y+=140;
            }

        }
        if(mouse_b)
        {
            nb=-1;
        }

        rewind(NomSave);
        if ( mouse_y>=250 && mouse_y<=330 && mouse_x>=370&& mouse_x<=510 && mouse_b)
        {
            nb=0;
            strcpy(fichier,"C:/Users/codos/CLionProjects/MenuS3projet/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);
        }
        if ( mouse_y>=250 && mouse_y<=330 && mouse_x>=585&& mouse_x<=725&& mouse_b){
            nb=1;
            strcpy(fichier,"C:/Users/codos/CLionProjects/MenuS3projet/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);
        }
        if ( mouse_y>=250 && mouse_y<=330 && mouse_x>=800&& mouse_x<=940 && mouse_b){
            nb=2;
            strcpy(fichier,"C:/Users/codos/CLionProjects/MenuS3projet/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);
        }
        if ( mouse_y>=390 && mouse_y<=470 &&  mouse_x>=370&& mouse_x<=510  && mouse_b){
            nb=3;
            strcpy(fichier,"C:/Users/codos/CLionProjects/MenuS3projet/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);
        }
        if ( mouse_y>=390 && mouse_y<=470 && mouse_x>=585&& mouse_x<=725 && mouse_b){
            nb=4;
            strcpy(fichier,"C:/Users/codos/CLionProjects/MenuS3projet/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);
        }
        if ( mouse_y>=390 && mouse_y<=470 && mouse_x>=800&& mouse_x<=940 && mouse_b){
            nb=5;
            strcpy(fichier,"C:/Users/codos/CLionProjects/MenuS3projet/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);
        }
        if ( mouse_y>=530 && mouse_y<=605 &&  mouse_x>=370&& mouse_x<=510 && mouse_b){
            nb=6;
            strcpy(fichier,"C:/Users/codos/CLionProjects/MenuS3projet/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);
        }
        if ( mouse_y>=530 && mouse_y<=605 && mouse_x>=585&& mouse_x<=725 && mouse_b){
            nb=7;
            strcpy(fichier,"C:/Users/codos/CLionProjects/MenuS3projet/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);
        }
        if (mouse_y>=530 && mouse_y<=605 && mouse_x>=800&& mouse_x<=940 && mouse_b){
            nb=8;
            strcpy(fichier,"C:/Users/codos/CLionProjects/MenuS3projet/");
            for (int j = 0; j < nb; ++j)
            {
                fscanf(NomSave,"%s",nom);
            }
            fscanf(NomSave,"%s",nom);

            strcat(fichier,nom);
            strcat(fichier,".txt");
            printf("%s\n",fichier);
            rest(150);
        }

        if(nb!=-1)
        {
            file=fopen(fichier,"r");
            if(!file)
            { printf("civ");}


            fscanf(file,"%s",nom);
            fscanf(file,"%d",&Temp.temps);
            fscanf(file,"%d",&Temp.argent);

            textprintf_ex(buffer,font,(140- (strlen(nom)/2)*7),205, makecol(0,0,0),-1,"%s",nom);
            textprintf_ex(buffer,font,120,400, makecol(0,0,0),-1,"%d",Temp.temps);
            textprintf_ex(buffer,font,120,585, makecol(0,0,0),-1,"%d",Temp.argent);
            fclose(file);
        }

        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        if ( mouse_y>=35 && mouse_y<=145 && mouse_x>=1120&& mouse_x<=1250 && mouse_b)
        {
            done=1;
        }
    }
}

void newgame(FILE* NomSave)
{
    int valide=0;
    char nom[100];
    char* nomville;

    while (valide==0)
    {
        allegro_message("Rentre le nom de ta ville dans la console");
        printf("Nom de ta ville : \n");
        gets(nom);
        nomville= malloc(sizeof (char)*strlen(nom));
        strcpy(nomville,nom);
        valide=checkname(nomville,strlen(nom));


    }
    printf("%s",nomville);
    fseek(NomSave,0,SEEK_END);
    fprintf(NomSave,"\n%s",nomville);
    fclose(NomSave);
    allegro_message("Lets the game begin");
}


int checkname(char* nom, int taille)
{
    if(nom[0]=='\0')
    {
        printf("Nom invalide : nom vide \n");
        return 0;
    }
    for (int i = 0; i < taille; ++i)
    {
        if (nom[i]=='/')
        {
            printf("Nom invalide : présence de /\n");
            return 0;
        }

    }
    return 1;
}

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


t_game* checkSauv(char* fichier)
{
    t_game* Sauv;
    Sauv=malloc(sizeof(t_game));
    FILE* dre=fopen("C:/Users/codos/CLionProjects/MenuS3projet/FreshBeer.txt","r");

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