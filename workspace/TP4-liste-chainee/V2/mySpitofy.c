#include "linkedListeOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]){

    if(argc==2){
        Liste l=NULL;
        char * fileName =argv[1];
        FILE* f=fopen(fileName,"r");
        char *ligne=calloc(sizeof(char),255);
        fgets(ligne,255,f);
        l=creationListeMusique(f,l);

        printf("%s",ligne);
        free(ligne);
        
        triMusique(l);
        afficheListe_i(l);
        fclose(f);
        detruire_i(l);
    }

    else if(argc==3 && (strcmp(argv[1],"trier")==0)){
        Liste l=NULL;
        char * fileName =argv[2];
        FILE* f=fopen(fileName,"r");
        char *ligne=calloc(sizeof(char),255);


        fgets(ligne,255,f);
        l=creationListeMusique(f,l);

        printf("%s",ligne);
        free(ligne);

        triMusique(l);
        afficheListe_i(l);
        fclose(f);
        detruire_i(l);

    }

    else{
        printf("Trop ou trop peu de paramètres");
    }


    return 0;
}