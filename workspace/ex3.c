#include <stdio.h>
#include <stdbool.h>

bool nbParfait(int i){

    int somme = 0;
    for(int j=1; j<i; j++){
        if(i%j == 0){
            somme += j;
        }
    }
    if(somme == i){
        return true;
    }
    else return false;

    
}

void afficheNbParfait(int N){
    for(int i=0; i<=N; i++){
        if(nbParfait(i)){
            printf("nombre parfait = %i\n", i);
        };

    }
    
}



int main(void) {

    afficheNbParfait(30);
    return 0;
}