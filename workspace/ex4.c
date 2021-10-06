#include <stdio.h>
typedef short TypeEntier;


TypeEntier factorielle(TypeEntier N){
    if(N>0){

        int somme = 1;
        for(int i=1; i<=N; i++){
             somme = somme *i;
        }
        return somme;
    }

    else return -1;
}





int main(void) {

    printf("resultat = %i\n", factorielle(3));
}