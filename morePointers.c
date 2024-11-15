#include <stdio.h>

int main(){

    int arr[] = {1,4,7,123,56,45,57,88,19,10};
    int *ptr = arr;
    //Prints the address
    printf("%p", ptr);
    //Prints the value in the array at index 1, without the +1 it is just index 0, *(ptr + i)
    printf("\n%d", *(ptr +1));




    return 0;
}