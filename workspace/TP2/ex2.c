#include <stdio.h>
#include <stdbool.h>

bool estConvexe(bool tab[], int length){
    bool result = true;
    bool *p;
    p = NULL;
    for(int i= 1; i< length; i++){
        if(p == NULL){
            if(tab[i] == true){
            p = &tab[i];
        }
        }
        else{
            if(tab[i] == true){
                if( &tab[i] - p == 1 ){
                    result = true;
                }
                else result = false;
            }
        }
    }

    return result;

    
}

int main(void){
    bool T[5] = {true, false, false, true, true}; 
    bool T2[5] = {true, false, true, false, true}; 
    printf("%s", estConvexe(T, 5)?"OK\n":"ERROR\n");
    printf("%s", estConvexe(T2, 5)?"OK\n":"ERROR\n");

    return 0;
}