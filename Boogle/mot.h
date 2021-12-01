/*Auteurs : GHAMRI-GUYOLLOT
 *Date de création : 26-03-2020
 *Date de modification : 30-03-2020*/

#ifndef __MOT__
#define __MOT__


/*Génère et renvoie une lettre aléatoirement suivant un tableau de probabilités*/
char genere_lettre_aleatoire(char tab[100]);

/*Renvoie la longueur d'un mot (son nombre de lettres)*/
int longueur_mot(char *mot);

/*Met à jour le score suivant la méthode de calcul du Boogle*/
void calcul_score(int *score, char *mot);

/*Converti une chaîne de caractères en minuscules*/
void majuscule_vers_min(char *mot);

/*Réinitialise un mot*/
void reset_mot(char *mot, int *longueur_mot);

/*Parcourt le tableau de mot trouvé par le joueur et renvoie 1 si le joueur a déjà trouvé ce mot, 0 sinon*/
int recherche_mot_trouve(char mot_trouvee[4][256], int nb_mot_trouve, char *mot);


#endif