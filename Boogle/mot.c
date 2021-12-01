/*Auteurs : GHAMRI-GUYOLLOT
 *Date de création : 26-03-2020
 *Date de modification : 30-03-2020*/

#include "mot.h"
#include "include.h"

char genere_lettre_aleatoire(char tab[100]){
	int r;
	assert(tab != NULL);
	r = rand() % 100;
	return tab[r];
}

int longueur_mot(char *mot){
	int cpt;
	cpt = 0;
	while(*mot != '\0'){
		cpt += 1;
		mot++;
	}
	return cpt;
}

void calcul_score(int *score, char *mot){
	*score += pow(2, longueur_mot(mot) - 3);
}

void majuscule_vers_min(char *mot){
	assert(mot != NULL);
	while(*mot != '\0'){
		if('A' <= *mot && *mot <= 'Z')
			*mot += 'a' - 'A';
		mot++;
	}
}

void reset_mot(char *mot, int *longueur_mot){
	memset(mot, 0, sizeof(mot));
	*longueur_mot = 0;
}

int recherche_mot_trouve(char mot_trouvee[4][256], int nb_mot_trouve, char *mot){
	int i;
	for(i = 0; i < nb_mot_trouve; i++){
		if(strcmp(mot_trouvee[i], mot) == 0)
			return 1;
	}
	return 0;
}