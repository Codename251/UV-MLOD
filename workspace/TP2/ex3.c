#include <stdio.h>

int mult_matrice(int matriceResultat[5][5], int matrice1[5][5],int matrice2[5][5]){
    int k =0;
    int somme =0;
    for(int i= 0; i< 5; i++){
        for(int j=0; j<5;j++){
            matriceResultat[i][j] = 0;
            for(int k=0; k<5; k++){
                matriceResultat[i][j] += matrice1[i][k]* matrice2[k][j];
            }
        }
    }
    return matriceResultat[5][5];
}

void affiche_matrice(int matrice[5][5]){
     for(int i= 0; i< 5; i++){
        for(int j=0; j<5;j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
     }
}

int main(void){
    int matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int matriceResultat[5][5];

    mult_matrice(matriceResultat,matrice1,matrice2);
    affiche_matrice(matriceResultat);

    return 0;
}