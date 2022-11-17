#ifndef INITPARTIE_H
#define INITPARTIE_H

t_partie* nouvellePartie(char* nomPartie, int tailleNom, int lignes, int colonnes);
t_partie* chargerPartie(char* nomPartie, int tailleNom);
t_partie* allouerPartie(int lignes, int colonnes);

#endif // INITPARTIE_H