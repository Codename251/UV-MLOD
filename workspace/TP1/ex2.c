#include <stdio.h>

void sommeDes(int N){
    if(N<=18 && N>=3){
        for(int i=1; i<=6; i++){
            for(int j=1; j<=6; j++){
                for(int k=1; k<=6; k++){

                    if(i+j+k == N){
                        printf("%i%i%i \n",i,j,k);
                    }

                }
            }
        }
    }
    
    else printf("Veuillez choisir un nombre entre 3 et 18\n");
}



int main(void) {

    sommeDes(4);
    return 0;
}