#include <stdio.h>


int factor(int x){
    int r = 0;
    for(int i = 1; i <= x; i++){
        if( x % i == 0){
            r += i;
        }
    }
    return r;
}

int main(){

    int n = 1;

    while(n < 100000){
        
        if((factor(n) - n) == 1){
            printf(" %d", n);
        }
        n++;
    }


    return 0;
}