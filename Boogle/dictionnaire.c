/*Auteurs : GHAMRI-GUYOLLOT
 *Date de création : 26-03-2020
 *Date de modification : 30-03-2020*/

#include "dictionnaire.h"
#define NB_LETTRES_MAX 256

Arbre alloueNoeud(char lettre){
	Arbre tmp;
	tmp = (Noeud *)malloc(sizeof(Noeud));
	if(tmp != NULL){
		tmp->lettre = lettre;
		tmp->filsg = NULL;
		tmp->frered = NULL;
	}
	return tmp;
}

void ajouteBranche(Arbre *A, char *mot){
	assert(mot != NULL);
	if((*A = alloueNoeud(*mot)) != NULL){
		if(*mot != '\0')
			ajouteBranche(&((*A)->filsg), mot + 1);
	}
}

void ajoutMot(Arbre *a, char *mot){
	assert(mot != NULL);
	if(*a == NULL){
		ajouteBranche(a, mot);
	}
	else{
		if((*a)->lettre < *mot)
			ajoutMot(&((*a)->frered), mot);
		else{
			if(((*a)->lettre == *mot) && (*mot != '\0'))
				ajoutMot(&((*a)->filsg), mot + 1);
			else{
				if(*mot != '\0'){
					Arbre tmp = NULL;
					ajouteBranche(&tmp, mot);
					tmp->frered = *a;
					*a = tmp;
				}
			}
		}
	}
}

int recherche(Arbre a, char *mot){
	assert(mot != NULL);
	if(a == NULL)
		return 0;
	if(*mot < a->lettre)
		return 0;
	if(*mot == a->lettre){
		if(*mot == '\0')
			return 1;
		return recherche(a->filsg, mot + 1);
	}
	return recherche(a->frered, mot);
}


void creer_dictionnaire(Arbre *a, FILE *fichier){
	int i;
	char mot[NB_LETTRES_MAX];
	assert(fichier != NULL);
	while(!feof(fichier)){
		fgets(mot, NB_LETTRES_MAX, fichier);
		for(i = 0; i < NB_LETTRES_MAX; i++){
			if(!('a' <= mot[i] && mot[i] <= 'z')){
				mot[i] = '\0';
				break;
			}
		}
		ajoutMot(a, mot);
	}
}