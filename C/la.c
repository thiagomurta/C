#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, j, x;
    srand(time(NULL));
    while(i<6){
        j= 1 + (rand()%60);
            x = j;
            i++;
            printf("%i\n",x);
    }
}
