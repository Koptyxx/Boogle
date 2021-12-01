/*Auteurs : GHAMRI-GUYOLLOT
 *Date de création : 26-03-2020
 *Date de modification : 30-03-2020*/

#ifndef __GRILLE__
#define __GRILLE__

typedef struct{
	int abscisse;
	int ordonnee;
}Case;

/*Initialise une grille avec lettres aléatoires suivant des chances d'apparitions*/
void creer_grille(char grille[4][4], char tab_proba[100]);

/*Recherche si une case que nous voulons selectionner l'a déjà été, renvoie si c'est le cas, 0 sinon*/
int recherche_selectionnee(Case tab[], int nb_case_selectionnee, int curseur_x, int curseur_y);

/*Vérifie qu'une case est bel et bien considérée comme voisine par rapport à celle qu'on choisi, renvoie 1 si c'est le cas, et 0 sinon*/
int est_case_valide(Case selectionnee[], int curseur_x, int curseur_y, int nb_case_selectionnee);

/*Réinitialise le tableau comprenant les cases selectionnées dans la grille*/
void reset_selectionnee(Case tab[], int *nb_case_selectionnee);

#endif