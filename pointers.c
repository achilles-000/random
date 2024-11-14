#include <stdio.h>

void function(int *x){
    //Derefrences to access the pointer at that memory location
    *x = 100;


}

int main(){

    int num = 1;

    printf("\nOriginal value: %d", num);

    //Pass the address
    function(&num);

    printf("\nAfter: %d", num);

    return 0;

}