#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "extras.h"
#include "structures.h"

#include "initPartie.h"

// Fonction qui cree une nouvelle partie vierge (avec le nom de partie valide en parametre)
t_partie* nouvellePartie(char* nomPartie, int tailleNom, int lignes, int colonnes) {

    // Allocation de la structure de partie
    t_partie* nouvellePartie = allouerPartie(lignes, colonnes);

    // Initialisation des valeurs de la structure de partie
    /// Toutes ces valeurs sont à verifier
    nouvellePartie->nomPartie = malloc(sizeof(char) * tailleNom);
    strcpy(nouvellePartie->nomPartie, nomPartie);
    nouvellePartie->tempsDeJeu = 0;
    nouvellePartie->lignes = lignes;
    nouvellePartie->colonnes = colonnes;
    for (int i = 0; i < nouvellePartie->lignes; i++) {
        for (int j = 0; j < nouvellePartie->colonnes; j++) {
            for (int k = 0; k < 3; k++) {
                nouvellePartie->plateau[i][j][k] = NULL;
                nouvellePartie->typeCase[i][j][k] = 0;
            }
        }
    }
    nouvellePartie->argent = 1000;
    nouvellePartie->file_centraleElectrique = NULL;
    nouvellePartie->file_chateauEau = NULL;
    nouvellePartie->file_route = NULL;
    nouvellePartie->file_residentiel = NULL;
    nouvellePartie->UIActuel = 0;

    return nouvellePartie;
}
/// taillenom inutile
t_partie* chargerPartie(char* nomPartie, int tailleNom) {

    // Ouverture du fichier de sauvegarde selon le nom de la partie
    char cheminSauvegarde[100]; // Y sera stocke le chemin du fichier de sauvegarde
    sprintf(cheminSauvegarde, "sauvegardes/%s/%s.txt", nomPartie, nomPartie);
    FILE* fichierSauvegarde = fopen(cheminSauvegarde, "r");
    if (fichierSauvegarde == NULL) {
        debug("Erreur lors de l'ouverture du fichier de sauvegarde");
        exit(1);
    }

    // Recuperation des donnees de base de la partie
    char nom[tailleNom];
    int tempsDeJeu;
    int lignes;
    int colonnes;

    fscanf(fichierSauvegarde, "%s", nom);
    fscanf(fichierSauvegarde, "%d", &tempsDeJeu);
    fscanf(fichierSauvegarde, "%d", &lignes);
    fscanf(fichierSauvegarde, "%d", &colonnes);

    // Allocation de la structure de partie
    t_partie* nouvellePartie = allouerPartie(lignes, colonnes);

    // Allocation du nom de la partie
    nouvellePartie->nomPartie = malloc(sizeof(char) * tailleNom);

    // Initialisation des valeurs de base de la structure de partie
    strcpy(nouvellePartie->nomPartie, nom);
    nouvellePartie->tempsDeJeu = tempsDeJeu;
    nouvellePartie->lignes = lignes;
    nouvellePartie->colonnes = colonnes;

    for (int i = 0; i < nouvellePartie->lignes; i++) {
        for (int j = 0; j < nouvellePartie->colonnes; j++) {
            for (int k = 0; k < 3; k++) { /// Nombre de niveaux definis
                fscanf(fichierSauvegarde, "%d", &nouvellePartie->typeCase[i][j][k]); // Sont d'abord lues les valeurs de typeCase
            }
        }
    }
    /// Obtention des valeurs de plateau selon les valeurs de typeCase
    t_route* nouvelleRoute;
    t_centraleElectrique* nouvelleCentraleElectrique;
    t_chateauEau* nouveauChateauEau;
    t_residentiel* nouveauResidentiel;
    for (int i = 0; i < nouvellePartie->lignes; i++) {
        for (int j = 0; j < nouvellePartie->colonnes; j++) {
            for (int k = 0; k < 3; k++)  {/// Nombre de niveaux definis
                switch (nouvellePartie->typeCase[i][j][k]) {
                    case 0:
                        nouvellePartie->plateau[i][j][k] = NULL;
                        break;
                    case 1:
                        nouvelleRoute = malloc(sizeof(t_route));
                        if (nouvelleRoute == NULL) {
                            debug("Erreur lors de l'allocation d'une route");
                            exit(1);
                        }
                        nouvelleRoute->precedent = NULL;
                        if (nouvellePartie->file_route == NULL) {
                            nouvellePartie->file_route = nouvelleRoute;
                            nouvelleRoute->suivant = NULL;
                        }
                        else {
                            nouvelleRoute->suivant = nouvellePartie->file_route;
                            nouvellePartie->file_route->precedent = nouvelleRoute;
                            nouvellePartie->file_route = nouvelleRoute;
                        }
                        break; /// Ajouter au plateau!!!!
                    case 2:
                        nouveauResidentiel = malloc(sizeof(t_residentiel));
                        if (nouveauResidentiel == NULL) {
                            debug("Erreur lors de l'allocation d'un batiment residentiel");
                            exit(1);
                        }
                        nouveauResidentiel->precedent = NULL;
                        if (nouvellePartie->file_residentiel == NULL) {
                            nouvellePartie->file_residentiel = nouveauResidentiel;
                            nouveauResidentiel->suivant = NULL;
                        }
                        else {
                            nouveauResidentiel->suivant = nouvellePartie->file_residentiel;
                            nouvellePartie->file_residentiel->precedent = nouveauResidentiel;
                            nouvellePartie->file_residentiel = nouveauResidentiel;
                        }

                        fscanf(fichierSauvegarde, "%d", &nouveauResidentiel->niveau);
                        nouvellePartie->plateau[i][j][k] = nouveauResidentiel;

                        break;
                    case 3:
                        nouveauChateauEau = malloc(sizeof(t_chateauEau));
                        if (nouveauChateauEau == NULL) {
                            debug("Erreur lors de l'allocation d'un chateau d'eau");
                            exit(1);
                        }
                        nouveauChateauEau->precedent = NULL;
                        if (nouvellePartie->file_chateauEau == NULL) {
                            nouvellePartie->file_chateauEau = nouveauChateauEau;
                            nouveauChateauEau->suivant = NULL;
                        }
                        else {
                            nouveauChateauEau->suivant = nouvellePartie->file_chateauEau;
                            nouvellePartie->file_chateauEau->precedent = nouveauChateauEau;
                            nouvellePartie->file_chateauEau = nouveauChateauEau;
                        }

                        break; /// Ajouter au plateau!!!!
                    case 4:
                        nouvelleCentraleElectrique = malloc(sizeof(t_centraleElectrique));
                        if (nouvelleCentraleElectrique == NULL) {
                            debug("Erreur lors de l'allocation d'une centrale electrique");
                            exit(1);
                        }
                        nouvelleCentraleElectrique->precedent = NULL;
                        if (nouvellePartie->file_centraleElectrique == NULL) {
                            nouvellePartie->file_centraleElectrique = nouvelleCentraleElectrique;
                            nouvelleCentraleElectrique->suivant = NULL;
                        }
                        else {
                            nouvelleCentraleElectrique->suivant = nouvellePartie->file_centraleElectrique;
                            nouvellePartie->file_centraleElectrique->precedent = nouvelleCentraleElectrique;
                            nouvellePartie->file_centraleElectrique = nouvelleCentraleElectrique;
                        }

                        break; /// Ajouter au plateau!!!!
                    default:
                        debug("Erreur lors de la lecture du fichier de sauvegarde (probablement corrompue)");
                        exit(1); /// Retour au menu preferable
                }
            }
        }
    }

    fscanf(fichierSauvegarde, "%d", &nouvellePartie->argent);

    fclose(fichierSauvegarde);

    return nouvellePartie;
}

// Fonction qui alloue la memoire pour une nouvelle partie / une partie chargée
t_partie* allouerPartie(int lignes, int colonnes) {

    // Allocation de la structure de partie
    t_partie* nouvellePartie = (t_partie*) malloc(sizeof(t_partie));
    if (!nouvellePartie) {
        debug("Erreur d'allocation de memoire pour une nouvelle partie");
        exit(1);
    }

    // Allocation du plateau de jeu
    /// Potentiellement a changer
    nouvellePartie->plateau = (void****) malloc(sizeof(void***) * lignes);
    for (int i = 0; i < lignes; i++) {
        nouvellePartie->plateau[i] = (void***) malloc(sizeof(void**) * colonnes);
        for (int j = 0; j < colonnes; j++) {
            nouvellePartie->plateau[i][j] = (void**) malloc(sizeof(void*) * 3); /// Nombres de niveaux (a changer?)
        }
    }
    /*  /// Problemes????
    if (!nouvellePartie->plateau) {
        debug("Erreur d'allocation de memoire pour le plateau de jeu");
        exit(1);
    }
    */

    // Allocation du plateau de type de cases
    /// Potentiellement a changer
    nouvellePartie->typeCase = (int***) malloc(sizeof(int**) * lignes);
    for (int i = 0; i < lignes; i++) {
        nouvellePartie->typeCase[i] = (int**) malloc(sizeof(int*) * colonnes);
        for (int j = 0; j < colonnes; j++) {
            nouvellePartie->typeCase[i][j] = (int*) malloc(sizeof(int) * 3); /// Nombres de niveaux (a changer?)
        }
    }
    /* /// Problemes????
    if (!nouvellePartie->typeCase) {
        debug("Erreur d'allocation de memoire pour le plateau de type de cases");
        exit(1);
    }
    */

    // Mise a zero des pointeurs de file
    nouvellePartie->file_route = NULL;
    nouvellePartie->file_residentiel = NULL;
    nouvellePartie->file_chateauEau = NULL;
    nouvellePartie->file_centraleElectrique = NULL;

    // Mise a zero de l'UI (puisqu'il ne s'agit que de l'affichage)
    nouvellePartie->UIActuel = 0;

    return nouvellePartie;

}