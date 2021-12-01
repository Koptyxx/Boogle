/*Auteurs : GHAMRI-GUYOLLOT
 *Date de création : 26-03-2020
 *Date de modification : 30-03-2020*/

#include "grille.h"
#include "include.h"
#include "mot.h"

void creer_grille(char grille[4][4], char tab_proba[100]){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++)
			grille[i][j] = genere_lettre_aleatoire(tab_proba);
	}
}


int recherche_selectionnee(Case tab[], int nb_case_selectionnee, int curseur_x, int curseur_y){
	int i;
	for(i = 0; i < nb_case_selectionnee; i++){
		if(tab[i].abscisse == curseur_x && tab[i].ordonnee == curseur_y)
			return 0;
	}
	return 1;
}

int est_case_valide(Case selectionnee[], int curseur_x, int curseur_y, int nb_case_selectionnee){
	if((selectionnee[nb_case_selectionnee - 1].abscisse == curseur_x + 1 && selectionnee[nb_case_selectionnee - 1].ordonnee == curseur_y + 1)
		|| (selectionnee[nb_case_selectionnee - 1].abscisse == curseur_x + 1 && selectionnee[nb_case_selectionnee - 1].ordonnee == curseur_y) 
		|| (selectionnee[nb_case_selectionnee - 1].abscisse == curseur_x + 1 && selectionnee[nb_case_selectionnee - 1].ordonnee == curseur_y - 1)
		|| (selectionnee[nb_case_selectionnee - 1].abscisse == curseur_x && selectionnee[nb_case_selectionnee - 1].ordonnee == curseur_y + 1)
		|| (selectionnee[nb_case_selectionnee - 1].abscisse == curseur_x && selectionnee[nb_case_selectionnee - 1].ordonnee == curseur_y - 1)
		|| (selectionnee[nb_case_selectionnee - 1].abscisse == curseur_x - 1 && selectionnee[nb_case_selectionnee - 1].ordonnee == curseur_y + 1)
		|| (selectionnee[nb_case_selectionnee - 1].abscisse == curseur_x - 1 && selectionnee[nb_case_selectionnee - 1].ordonnee == curseur_y)
		|| (selectionnee[nb_case_selectionnee - 1].abscisse == curseur_x - 1 && selectionnee[nb_case_selectionnee - 1].ordonnee == curseur_y - 1))
		return 1;
	else
		return 0;
}

void reset_selectionnee(Case tab[], int *nb_case_selectionnee){
	int i;
	for(i = 0; i < *nb_case_selectionnee; i++){
		tab[i].abscisse = -1;
		tab[i].ordonnee = -1;
	}
	*nb_case_selectionnee = 0;
}