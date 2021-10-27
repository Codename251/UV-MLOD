#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListeOfMusic.h"



Music * lireLigneMusique(char *ligne){
    Music* musique=(Music*) malloc(sizeof(Music));
    char *p;
    char *str=strdup(ligne);
    char *tmp=str;
    

    p=strsep(&str,",");
    musique->name=calloc(sizeof(char),strlen(p)+1);
    strcpy(musique->name,p);

    p=strsep(&str,",");
    musique->artist=calloc(sizeof(char),strlen(p)+1);
    strcpy(musique->artist,p);

    p=strsep(&str,",");
    musique->album=calloc(sizeof(char),strlen(p)+1);
    strcpy(musique->album,p);

    p=strsep(&str,",");
    musique->genre=calloc(sizeof(char),strlen(p)+1);
    strcpy(musique->genre,p);

    p=strsep(&str,",");
    musique->discNumber=atoi(p);

    p=strsep(&str,",");
    musique->trackNumber=atoi(p);

    p=strsep(&str,",");
    musique->year=atoi(p);

    free(tmp);

    return musique;
}


Liste creationListeMusique(FILE* f,Liste l){
    char *ligne=calloc(255,sizeof(char));
    fgets(ligne,255,f);

    l=creer(lireLigneMusique(ligne));
    free(ligne);
    ligne=NULL;
    for (int i=0;;i++){
        ligne=calloc(255,sizeof(char));
        fgets(ligne,255,f);

        if(strlen(ligne)==0){
            free(ligne);
            ligne=NULL;
            break;
        }

        l=ajoutFin_i(lireLigneMusique(ligne),l);
        free(ligne);
        ligne=NULL;
    }
    return l;

}

void afficheElement(Element e){
    Music * m=(Music *)e;
    printf("%s",m->name);
    printf("%s",m->artist);
    printf("%s",m->album);
    printf("%s",m->genre);
    printf("%i",m->discNumber);
    printf("%i",m->trackNumber);
    printf("%i",m->year);
}

void detruireElement(Element e){
    Music *m = (Music*)e;
    free(m);
    e = NULL;
}

bool equalsElement(Element e1, Element e2){
    Music * m1=(Music *)e1;
    Music * m2=(Music *)e2;
    if(strcmp(m1->name,m2->name)!=0){
        return 0;
    }
    if(strcmp(m1->artist,m2->artist)!=0){
        return 0;
    }
    if(strcmp(m1->album,m2->album)!=0){
        return 0;
    }
    if(strcmp(m1->genre,m2->genre)!=0){
        return 0;
    }
    return 1;
}

Liste triMusique(Liste l){
	
    if(estVide(l)){
        return NULL;
    }

    Liste precedent  = l;
    Liste suivant = NULL;

    while(!estVide(precedent)){
        suivant = precedent->suiv;

        while(!estVide(suivant)){
            if( ((Music*)(suivant->val))->year < ((Music*)(precedent->val))->year ){
                void *p;
                p = suivant->val;
                suivant->val = precedent->val;
                precedent->val = p;
            }
            suivant = suivant->suiv;
        }
        precedent = precedent->suiv;
    }
    return l;

}