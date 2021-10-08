#include <stdio.h>

float prixDuBillet(float prix_plein_tarif,unsigned int age){
    if(age<=2){
        return prix_plein_tarif*0.1;
    }
    else if( age<= 12){
        return prix_plein_tarif*0.5;
    }
    else return prix_plein_tarif;
}



int main(void) {

    float prix = prixDuBillet(10,25);
    printf("%.2f \n", prix);
    return 0;
}