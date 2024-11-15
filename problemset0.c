#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(0));
    int size = (rand() % 20) + 1;
    int arr[size]; 

    //Populate the array
    for(int i = 0; i < size; i++){
        arr[i] = (rand() % 100);
    }
    
    //Print every element inside the array
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

int min, b;
    //If the number at index i is smaller than min set min equal to that number
    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
            b = i;
        }
    }

    printf("The lowest number is: %d at %d", min, b );



    
    return 0;
}