/*Auteurs : GHAMRI-GUYOLLOT
 *Date de création : 26-03-2020
 *Date de modification : 30-03-2020*/

#ifndef __AFFICHAGE__
#define __AFFICHAGE__

#include "include.h"

/*Affiche via l'interface ncurses la grille de lettres au milieu de l'écran*/
void affiche_grille(char grille[4][4], int curseur_x, int curseur_y);

/*Affiche le score actuel du joueur*/
void affiche_score(int score);

/*Affiche le mot que le joueur est en train de former*/
void affiche_mot(char *mot);

/*Affiche le nombre de tentative restant au joueur*/
void affiche_tentative_restante(int nb_tentative);

/*Une fois la partie terminée, affiche le score final du joueur*/
void affiche_score_final(int score);

/*Affiche les mots trouvés pour le joueur*/
void affiche_mot_trouve(char mot_trouve[4][256], int nb_mot_trouve);

/*Une fois la partie terminée, affiche tout les mots trouvés par le joueur*/
void affiche_mot_final(char mot_trouve[4][256], int nb_mot_trouve);

/*Affiche l'accueil prévue pour le joueur*/
void affiche_accueil();

#endif