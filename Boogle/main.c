/*Auteurs : GHAMRI-GUYOLLOT
 *Date de création : 26-03-2020
 *Date de modification : 30-03-2020*/

#include "dictionnaire.h"
#include "grille.h"
#include "affichage.h"
#include "mot.h"

#define NB_LETTRES_MAX 256


int main(){
	Arbre a = NULL;
	int touche;
	int nb_case_selectionnee;
	int nb_tentative;
	char mot_trouve[4][NB_LETTRES_MAX];
	int nb_mot_trouve;
	Case selectionnee[16];
	char tab_proba[100] = {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'T', 'T', 'T', 'T','T', 'T', 'T', 'T', 'A', 'A', 'A',
	'A', 'A', 'A', 'A', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'S', 'S', 'S', 'S',
	'S', 'S', 'S', 'R', 'R', 'R', 'R', 'R', 'R', 'H', 'H', 'H', 'H', 'H', 'D', 'D', 'D', 'D', 'L', 'L', 'L', 'L', 'C', 'C', 'C', 'M', 'M', 'M',
	'U', 'U', 'U', 'B', 'B', 'F', 'F', 'G', 'G', 'P', 'P', 'W', 'W', 'Y', 'Y', 'J', 'K', 'Q', 'V', 'X', 'Z'};
	FILE *fichier = fopen("Mots", "r");
	char grille[4][4];
	char mot[NB_LETTRES_MAX];
	int longueur_mot;
	int score;
	int curseur_x, curseur_y;


	nb_case_selectionnee = 0;
	nb_tentative = 4;
	score = 0;
	curseur_x = 0;
	curseur_y = 0;
	nb_mot_trouve = 0;
	longueur_mot = 0;
	creer_dictionnaire(&a, fichier);
	creer_grille(grille, tab_proba);


	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();
	affiche_accueil();


	while(touche != 10)
		touche = getch();
	clear();

	while(1){
		affiche_grille(grille, curseur_x, curseur_y);
		touche = getch();

		if(touche == KEY_UP){
			if(curseur_x == 0)
				curseur_x = 3;
			else
				curseur_x -= 1;
		}

		if(touche == KEY_DOWN){
			if(curseur_x == 3)
				curseur_x = 0;
			else
				curseur_x += 1;
		}

		if(touche == KEY_LEFT){
			if(curseur_y == 0)
				curseur_y = 3;
			else
				curseur_y -= 1;
		}

		if(touche == KEY_RIGHT){
			if(curseur_y == 3)
				curseur_y = 0;
			else
				curseur_y += 1;
		}

		if(touche == 32 && (nb_case_selectionnee == 0 || est_case_valide(selectionnee, curseur_x, curseur_y, nb_case_selectionnee) == 1)){ /*TOUCHE ESPACE*/
			if(recherche_selectionnee(selectionnee, nb_case_selectionnee, curseur_x, curseur_y) == 1){
				mot[longueur_mot] = grille[curseur_x][curseur_y];
				mot[longueur_mot + 1] = '\0';
				longueur_mot += 1;
				selectionnee[nb_case_selectionnee].abscisse = curseur_x;
				selectionnee[nb_case_selectionnee].ordonnee = curseur_y;
				nb_case_selectionnee += 1;
			}

			else{
				mvprintw(LINES - 1, 0, "Vous avez déjà selectionné cette case !");
				refresh();
				usleep(1000000);
				clear();
			}
		}

		if(touche == 'a' && longueur_mot > 0 && nb_case_selectionnee > 0){ /*TOUCHE A*/
			mot[longueur_mot - 1] = '\0';
			longueur_mot -= 1;
			nb_case_selectionnee -= 1;
			selectionnee[nb_case_selectionnee].abscisse = -1;
			selectionnee[nb_case_selectionnee].ordonnee = -1;
			clear();
		}

		if(touche == 10){ /*TOUCHE ENTREE*/
			nb_tentative -= 1;
			majuscule_vers_min(mot);

			if(recherche(a, mot) == 1 && recherche_mot_trouve(mot_trouve, nb_mot_trouve, mot) == 0){
				calcul_score(&score, mot);
				strcpy(mot_trouve[nb_mot_trouve], mot);
				nb_mot_trouve += 1;
			}

			reset_selectionnee(selectionnee, &nb_case_selectionnee);
			reset_mot(mot, &longueur_mot);
			clear();
		}

		if(nb_tentative == 0)
			break;

		affiche_mot_trouve(mot_trouve, nb_mot_trouve);
		affiche_score(score);
		affiche_mot(mot);
		affiche_tentative_restante(nb_tentative);
		refresh();

	}
	clear();
	affiche_score_final(score);
	affiche_mot_final(mot_trouve, nb_mot_trouve);
	refresh();
	usleep(10000000);
	endwin();
	return 1;
}
