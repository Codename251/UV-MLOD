#include <stdio.h>
#include <stdlib.h>

enum Mois {
    janvier = 1,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
    };


struct Date{
    int jour;
    enum Mois mois;
    int annee;
};

typedef struct Date Date;
typedef enum Mois Mois;



void initialiseDate(Date *d){
    printf("Jour :");
    scanf("%i", &d->jour);
    printf("Mois :");
    scanf("%i", (int *)&d->mois);
    printf("Annee :");
    scanf("%i", &d->annee);
};

void afficheDate(Date *d){
    
    printf("%d/%d/%d", d->jour, d->mois, d->annee);

};

Date creerDateParCopie(){
    Date d;
    printf("Jour : ");
    scanf("%i", &d.jour);
    printf("Mois : ");
    scanf("%i", (int *)&d.mois);
    printf("Annee : ");
    scanf("%i", &d.annee);

    return d;
}

Date* newDate(){
    Date* pDate = (Date*)malloc(sizeof(Date));
    if(pDate) initialiseDate(pDate);
    return pDate;
}   

int main(void){
    Date d;
    initialiseDate(&d);
    afficheDate(&d);
    d = creerDateParCopie();
    afficheDate(&d);

    Date *date;
    date = newDate();
    afficheDate(date);
    free(date);

    return 0;
}