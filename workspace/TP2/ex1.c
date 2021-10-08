#include <stdio.h>

void echangeContenu(int *a, int *b){
    int tampon; 
    tampon = (*a);
    (*a) = (*b);
    (*b) = tampon;
}

int main(void){
    int a = 10;
    int b = 20;
    echangeContenu(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}