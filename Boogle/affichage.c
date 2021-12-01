/*Auteurs : GHAMRI-GUYOLLOT
 *Date de création : 26-03-2020
 *Date de modification : 30-03-2020*/

#include "affichage.h"

void affiche_grille(char grille[4][4], int curseur_x, int curseur_y){
	int i, j;
	init_pair(1, COLOR_WHITE, COLOR_RED);
	mvhline(LINES/2 - 6, COLS/2 - 6, 0, 12);
	mvvline(LINES/2 - 6, COLS/2 - 6, 0, 12);
	mvhline(LINES/2 + 6, COLS/2 - 6, 0, 12);
	mvvline(LINES/2 - 6, COLS/2 + 6, 0, 12);
	for(i = 0; i <= 3; i++)
		mvhline(LINES/2 - 6 + 3*i, COLS/2 - 6, 0, 12);
	for(i = 0; i <= 3; i++)
		mvvline(LINES/2 - 6, COLS/2 - 6 + 3*i, 0, 12);
	mvaddch(LINES/2 - 6, COLS/2 - 6 ,ACS_ULCORNER);
	mvaddch(LINES/2 - 6, COLS/2 + 6, ACS_URCORNER);
	mvaddch(LINES/2 + 6, COLS/2 - 6, ACS_LLCORNER);
	mvaddch(LINES/2 + 6, COLS/2 + 6, ACS_LRCORNER);
	for(i = 0; i <= 3; i++){
		for(j = 0; j <= 3; j++){
			if(i == 0 && j != 0)
				mvaddch(LINES/2 - 6, COLS/2 - 6 + 3*j, ACS_TTEE);
			if(i == 3 && j != 0)
				mvaddch(LINES/2 + 6, COLS/2 - 6 + 3*j, ACS_BTEE);
			if(i != 0 && j != 0)
				mvaddch(LINES/2 - 6 + 3*i, COLS/2 - 6 + 3*j, ACS_PLUS);
			if(j == 0 && i != 0)
				mvaddch(LINES/2 - 6 + 3*i, COLS/2 - 6, ACS_LTEE);
			if(j == 3 && i != 0)
				mvaddch(LINES/2 - 6 + 3*i, COLS/2 + 6, ACS_RTEE);
		}
	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(i == curseur_x && curseur_y == j)
				attron(COLOR_PAIR(1));
			mvprintw(LINES/2 - 6 + 3*i + 1.5, COLS/2 - 6 + 3*j + 1.5, "%c", grille[i][j]);
			attroff(COLOR_PAIR(1));
		}
	}
}


void affiche_score(int score){
	mvprintw(0, 0, "Score = %d", score);
}

void affiche_mot(char *mot){
	mvprintw(2, 0, "Mot actuel : %s", mot);
}

void affiche_tentative_restante(int nb_tentative){
	mvprintw(4, 0, "Tentative restante : %d", nb_tentative);
}

void affiche_score_final(int score){
	mvprintw(LINES/2 - 10, COLS/2 - 9, "FIN DE PARTIE !");
	mvprintw(LINES/2 - 8, COLS/2 - 12, "Votre score est de : %d", score);
}



void affiche_mot_trouve(char mot_trouve[4][256], int nb_mot_trouve){
	int i;
	mvprintw(LINES - 5, 0, "MOT TROUVE : ");
	for(i = 0; i < nb_mot_trouve; i++){
		mvprintw(LINES - 4 + i, 0, "-%s", mot_trouve[i]);
	}
}

void affiche_mot_final(char mot_trouve[4][256], int nb_mot_trouve){
	int i;
	mvprintw(LINES/2 - 6, 20, "Vous avez trouvé les mots suivants :");
	for(i = 0; i < nb_mot_trouve; i++){
		mvprintw(LINES/2 - 4 + i, COLS/2 - 2, "-%s", mot_trouve[i]);
	}
}

void affiche_accueil(){
	mvprintw(0, 0, "Bienvenue dans notre TP de BOOGLE ! \nVeuillez trouver ci-dessous les commandes du jeu :");
	mvprintw(5, 0, "-Deplacez-vous à travers la grilles grace aux flèches directionnelles");
	mvprintw(7, 0, "-Pour selectionner une lettre de la grille, appuyez sur espace");
	mvprintw(9, 0, "-Pour effacer la derniere lettre, appuyez sur A");
	mvprintw(11, 0, "-Pour soumettre un mot, appuyez sur ENTREE");
	mvprintw(13, 0, "-Vous ne pouvez pas soumettre les deux même mot");
	mvprintw(15, 0, "-Vous ne pouvez pas selectionner deux fois la même case pour un même mot");
	mvprintw(17, 0, "-Vous ne pouvez selectionner que des cases voisines");
	mvprintw(LINES - 1, 0, "Une fois les regles lues, veuillez appuyez sur ENTREE pour demarrer !");
}