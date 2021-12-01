/*Auteurs : GHAMRI-GUYOLLOT
 *Date de création : 26-03-2020
 *Date de modification : 30-03-2020*/

#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__

#include "include.h"

typedef struct noeud{
	char lettre;
	struct noeud *filsg, *frered;
}Noeud, *Arbre;

/*Fonction allouant et renvoyant l'adresse d'un noeud pour la lettre passée en paramètre*/
Arbre alloueNoeud(char lettre);

/*Fonction qui ajoute à l'arbre passé en paramètre une branche pour le mot passé en paramètre*/
void ajouteBranche(Arbre *A, char *mot);

/*Fonction ajoutant un mot passé en paramètre dans l'arbre lexicographique passé en paramètre*/
void ajoutMot(Arbre *a, char *mot);

/*Recherche si le mot passé en paramètre est présent dans notre dictionnaire, renvoie 1 si c'est le cas, 0 sinon*/
int recherche(Arbre a, char *mot);

/*Parcourt un fichier et place tout ses mots dans notre arbre lexicogrpahique*/
void creer_dictionnaire(Arbre *a, FILE *fichier);

#endif
