#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(0));
    int size = (rand() % 10) + 1;
    int arr[size];

    //Populate the array
    for(int i = 0; i < size; i++){
        arr[i] = (rand() % 100);
    }
    //Print every element inside the array
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }


    
    return 0;
}