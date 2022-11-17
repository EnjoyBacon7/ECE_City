#ifndef STRUCTURES_H
#define STRUCTURES_H


// Structures pour les elements residentiels
typedef struct residentiel {

    int alimEau;
    int alimElectricite;
    int alimRoute;

    int niveau;

    //permet de realiser une file de ces structures a stocker dans la structure de partie
    struct residentiel* precedent;
    struct residentiel* suivant;

} t_residentiel;

typedef struct {

    // Le numero de case utile pour l'affichage de la bonne bitmap
    int numeroCase;
    // Pointeur sur l'instance de residentiel
    t_residentiel* residentiel;

} t_caseResidentiel;

// Structures pour les elements de chateau d'Eau
typedef struct chateauEau {

    int alimRoute;

    //permet de realiser une file de ces structures a stocker dans la structure de partie
    struct chateauEau* precedent;
    struct chateauEau* suivant;

} t_chateauEau;

typedef struct {

    // Le numero de case utile pour l'affichage de la bonne bitmap
    int numeroCase;
    // Pointeur sur l'instance de chateau d'Eau
    t_chateauEau* chateauEau;

} t_caseChateauDEau;

// Structures pour les elements de centrale electrique
typedef struct centraleElectrique {

    int alimRoute;

    //permet de realiser une file de ces structures a stocker dans la structure de partie
    struct centraleElectrique* precedent;
    struct centraleElectrique* suivant;

} t_centraleElectrique;

typedef struct {

    // Le numero de case utile pour l'affichage de la bonne bitmap
    int numeroCase;
    // Pointeur sur l'instance de centrale electrique
    t_centraleElectrique* centreElectrique;

} t_caseCentraleElectrique;

// Structures pour les elements de route
typedef struct route{

    struct route* precedent;
    struct route* suivant;
    /// Ne contient rien. A corriger ou completer

} t_route;

// Structure de partie principale
typedef struct {

    // Infos relative à la partie en tant que sauvegarde
    char* nomPartie;
    int tempsDeJeu;
    /// BITMAP* imgSauvegarde;

    // Infos relative au plateau de jeu
    int lignes;
    int colonnes;

    void**** plateau;
    int*** typeCase;

    int argent;

    // Infos utiles pour les differents elements du jeu. C'est ici qu'il faut rajouter de nouveaux types d'infrastructures
    t_residentiel* file_residentiel;
    t_chateauEau* file_chateauEau;
    t_centraleElectrique* file_centraleElectrique;
    t_route* file_route;

    // Utile pour l'affichage, pour se souvenir du menu sur lequel on est

    int UIActuel;

}t_partie;

#endif // STRUCTURES_H


// Tous les types de cases:

// 0 = case vide
// 1 = route
// 2 = residentiel
// 3 = chateau d'eau
// 4 = centrale electrique
