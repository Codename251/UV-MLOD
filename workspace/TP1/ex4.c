#include <stdio.h>
typedef unsigned long long TypeEntier;


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

void afficheFactorielle(){
    int N = 0;
    printf("Entrez un nombre entier positif: ");
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        printf("factorielle de %i = %llu\n",i, factorielle(i) );
    }

}





int main(void) {

    afficheFactorielle();
}