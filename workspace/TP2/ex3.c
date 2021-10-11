#include <stdio.h>

int mult_matrice(int taille, int matriceResultat[taille][taille], int matrice1[taille][taille],int matrice2[taille][taille]){
    int k =0;
    int somme =0;
    for(int i= 0; i< taille; i++){
        for(int j=0; j<taille;j++){
            matriceResultat[i][j] = 0;
            for(int k=0; k<taille; k++){
                matriceResultat[i][j] += matrice1[i][k]* matrice2[k][j];
            }
        }
    }
    return matriceResultat[5][5];
}

void affiche_matrice(int taille , int matrice[taille][taille]){
     for(int i= 0; i< taille; i++){
        for(int j=0; j<taille;j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
     }
}

int main(void){
    int matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int matriceResultat[5][5];

    mult_matrice(5, matriceResultat,matrice1,matrice2);
    affiche_matrice(5, matriceResultat);

    return 0;
}