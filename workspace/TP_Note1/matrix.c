#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Matrix{
    int nombreDeLignes;
    int nombreDeColonnes;
    int valeurs[1000];
};

typedef struct Matrix Matrix;
typedef Matrix* MatrixArray;

Matrix readMatrix(){
    Matrix matrice;
    scanf("%i %i", &matrice.nombreDeLignes, &matrice.nombreDeColonnes);
    for(int i=0; i< matrice.nombreDeLignes; i++){
        if(matrice.nombreDeColonnes == 1){
            scanf("%i", &matrice.valeurs[i]);
        };
        if(matrice.nombreDeColonnes == 2){
            scanf("%i %i", &matrice.valeurs[2*i], &matrice.valeurs[(2*i)+1]);
        };

        if(matrice.nombreDeColonnes == 3){
            scanf("%i %i %i", &matrice.valeurs[3*i], &matrice.valeurs[(3*i)+1], &matrice.valeurs[(3*i)+2] );
        };

        if(matrice.nombreDeColonnes == 4){
            scanf("%i %i %i %i", &matrice.valeurs[4*i], &matrice.valeurs[(4*i)+1], &matrice.valeurs[(4*i)+2], &matrice.valeurs[(4*i)+3] );
        };

        if(matrice.nombreDeColonnes == 5){
             scanf("%i %i %i %i %i", &matrice.valeurs[5*i], &matrice.valeurs[(5*i)+1], &matrice.valeurs[(5*i)+2], &matrice.valeurs[(5*i)+3], &matrice.valeurs[(5*i)+4] );
        };

    };
    return matrice;
};


void readMatrixArray(MatrixArray *matrices, int nombreMatrices){
    *matrices = (Matrix*)calloc(nombreMatrices, sizeof(Matrix));
    for(int i=0; i<nombreMatrices; i++){
        (*matrices)[i] = readMatrix();
    }
};

void AfficheMatrix(MatrixArray matrices, int nombreMatrices){
    printf("%i\n", nombreMatrices);
    for(int i=0; i<nombreMatrices; i++){
        printf("%i %i\n", matrices[i].nombreDeLignes, matrices[i].nombreDeColonnes);
        for(int j=0; j< matrices[i].nombreDeLignes; j++){
            for(int k=0; k< matrices[i].nombreDeColonnes; k++){

                printf("%i ", matrices[i].valeurs[(matrices[i].nombreDeColonnes*j)+k]);

            };
            printf("\n");
        };
    };
};

int main(void){
    int nombreMatrices;
    scanf("%i", &nombreMatrices);
    //printf("%i", nombreMatrices);
    MatrixArray matrices;
    readMatrixArray(&matrices, nombreMatrices);
    AfficheMatrix(matrices, nombreMatrices);
    free(matrices);
    return EXIT_SUCCESS;
}