#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(0));
    int size = (rand() % 10) + 1;
    int arr[size];

    printf("%d", sizeof(arr));


    return 0;
}