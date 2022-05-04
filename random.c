#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

int i;
int x = 5;
srand(x);
    for(i=0;i<20;i++){
        //srand(x);

        x = rand();

        printf("%d,",x);

    }
    



    return 0;
}