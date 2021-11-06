#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {

    ArbreBinaire arbre =(ArbreBinaire) malloc(sizeof(Noeud));
    arbre->val = e;
    arbre->filsGauche = NULL;
    arbre->filsDroit = NULL;

	return arbre;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire tmp=a;

	if(estVide(a)){
		a=creer(e);
		return a;
	}

	while(!estVide(tmp)){

		if(tmp->val == e){
			return a;
		}
		
		if(e>tmp->val){
			if(estVide(tmp->filsDroit)){
				tmp->filsDroit=creer(e);
				return a;
			}
			tmp=tmp->filsDroit;
		}
		
		if(e<tmp->val){
			if(estVide(tmp->filsGauche)){
				tmp->filsGauche=creer(e);
				return a;
			}

			tmp=tmp->filsGauche;
		}
	}

	return a;

}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	
	if(a == NULL)
		return creer(e) ;
	
	if(e < a->val)
		a->filsGauche = insere_r(a->filsGauche, e);
	else
		a->filsDroit = insere_r(a->filsDroit, e);
	return a;
	
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){

	if (a == NULL){
		return 0 ;
	}
	
	return (1 + nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit));

}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	int count = 0;
	if(estVide(a))
		return count;
	if(e == a->val)
		return count;
	if(e < a->val ){
		count += 1;
		return profondeur(a->filsGauche, e);
	}
	else{
		count += 1;
		return profondeur(a->filsDroit, e);
	}
}


int maximum(int a, int b){
	if(a>b) return a;
	if(b>a) return b;
	else return 0;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if(estVide(a)) return 0;
	else{
		int hauteurGauche = hauteur(a->filsGauche);
		int hauteurDroit = hauteur(a->filsDroit);
		return 1+ maximum(hauteurDroit, hauteurGauche);
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	if(estVide(a)){
		return NULL;
	}
	
	if(a->val == elem){
		return NULL;
	}
	
	if(!estVide(a->filsGauche)){
		if(a->filsGauche->val == elem){
			return a;
		}
	}

	if(!estVide(a->filsDroit)){
		if(a->filsDroit->val == elem){
			return a;
		}
	}
	
	if(elem<a->val){
		return pere(a->filsGauche,elem);
	}
	if(elem>a->val){
		return pere(a->filsDroit,elem);
	}
	return a;
}


void afficheRGD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("%i", a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheGRD_r(a->filsGauche);
		printf("%i", a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		printf("%i", a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	if(estVide(a)){
		return NULL;
	}

	if(estVide(a->filsGauche)){
		return a;
	}
	return min(a->filsGauche);
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	if(estVide(a)){
		return NULL;
	}

	if(estVide(a->filsDroit)){
		return a;
	}
	return max(a->filsDroit);
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	if(estVide(a)){
		return NULL;
	}
	if(elem==a->val){
		return a;
	}
	else{
		if(elem<a->val){
			return recherche_r(a->filsGauche,elem);
		}
		else{
			return recherche_r(a->filsDroit,elem);
		}
	}
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	
	if( estVide(a)){
		return a;
	}

	
	if(a->val<x){
		a->filsDroit = supprimer_r(a->filsDroit,x);
	}
	else if(a->val>x){
		a->filsGauche = supprimer_r(a->filsGauche,x);
	}
	
	else{

		if(estVide(a->filsDroit)){
			ArbreBinaire tmp = a->filsGauche;
			free(a);
			return tmp;
		}
		else if(estVide(a->filsGauche)){
			ArbreBinaire tmp = a->filsDroit;
			free(a);
			return tmp;
		}
		
		ArbreBinaire tmp = min(a->filsDroit);
		a->val=tmp->val;
		a->filsDroit=supprimer_r(a->filsDroit, tmp->val);

	}
	return a;
}

void detruire_r(ArbreBinaire a){
	if(a == NULL)
		return;
	detruire_r(a->filsGauche);
	detruire_r(a->filsDroit);
	free(a);
}

