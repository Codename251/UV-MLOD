#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l = (Liste) malloc(sizeof(Cellule));	
	l->val = v;
    l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {

	Liste n = creer(v);
	n->suiv = l;
	return n;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	if(l==NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	Liste p = l;

	while(!estVide(p)){
		afficheElement(p->val);
		p = p->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	Liste p = l;

	if(estVide(p)){
		printf("\n");
	}
		
	else{
		afficheElement(p->val);	
		return afficheListe_r(p->suiv);
	}
		
}

void detruireElement(Element e) {
	
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste p = l;

	while(!estVide(p)){
		Cellule *aSupprimer = p;
		p = p->suiv;
		free(aSupprimer);
	}

}

// version récursive
void detruire_r(Liste l) {
	Liste p = l;

	if(estVide(p)){
	}
		
	else{
		Cellule *aSupprimer = p;
		Liste suivante = p->suiv;
		free(aSupprimer);
		return detruire_r(suivante);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste p = l;

	while(!estVide(p)){
		if(p->suiv == NULL){
			Liste f = creer(v);
			p->suiv = f;
		}
		p = p->suiv;
	}

	return p;

}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	return TODO;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste p = l;

	while(!estVide(p)){
		if(v == p->val) return p;
		else p = p->suiv;
	}

	return NULL;

}

// version récursive
Liste cherche_r(Element v,Liste l) {
	Liste p = l;

	if(estVide(p)){
		return NULL;
	}
		
	else{
		if(v == p->val) return p;
		else return cherche_r(v, p->suiv);
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	return TODO;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	return TODO;
}


void afficheEnvers_r(Liste l) {
	TODO;
}



