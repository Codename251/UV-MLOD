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
	Liste p;

	while(!estVide(l)){
		p = l;
		l = l->suiv;
		detruireElement(p->val);
		free(p);
	}

}

// version récursive
void detruire_r(Liste l) {

	if(!estVide(l->suiv)){
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
		
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste temp = l;

	if(estVide(l))
		return creer(v);

	//temp != NULL
	while(!estVide(temp->suiv)){
		temp = temp->suiv;
	}

	//temp!=NULL && temp->suiv == NULL
	temp->suiv = creer(v);

	return l;


}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l)){
		return creer(v);
	}
	else{
		l->suiv = ajoutFin_r(v, l->suiv);
	}

	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {

	while(!estVide(l) && !equalsElement(v, l->val) ){
		l = l ->suiv;
	}
	// l== NULL || l->val == v
	return l;

}

// version récursive
Liste cherche_r(Element v,Liste l) {

	if(estVide(l)){
		return NULL;
	}
		
	
	if(equalsElement(v, l->val)){
		return l;
	}
		
	else{
		return cherche_r(v, l->suiv);
	} 
	
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste precedent, p;

	if(estVide(l)){
		return l;
	}
	if(equalsElement(l->val,v)){
		p = l->suiv;
		l->suiv == NULL;
		detruire_r(l);
		return p;
	}

	precedent = l;
	p = l->suiv;
	while(!estVide(p) && !equalsElement(p->val,v)){
		precedent = p;
		p = p->suiv;
	}

	if(!estVide(p)){
		//on a trouvé v
		precedent->suiv = p->suiv;
		p->suiv = NULL;
		detruire_r(p);
	}

	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	Liste p;
	if(estVide(l)){
		return l;
	}
	if(equalsElement(l->val,v)){
		p = l->suiv;
		l->suiv == NULL;
		detruire_r(l);
		return p;
	}

	l->suiv = retirePremier_r(v, l->suiv);
	return l;

}


void afficheEnvers_r(Liste l) {
	Liste p = l;

	if(!estVide(p)){
		
		afficheEnvers_r(p->suiv);
		afficheElement(p->val);
		
	}
	else{
		printf("\n");
	}
}



