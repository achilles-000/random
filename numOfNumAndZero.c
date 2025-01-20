#include <stdio.h>


int NumZeros(int input){
    int count = 0;


    for(int i = 0; i < (sizeof(int) * 8); i++){
        if((input & 1) == 0){
            count++;
        }
        input >>= 1;
    }
    return count;

}

int NumOnes(int input){
    int count = 0;

    for(int i = 0; i < (sizeof(int) * 8); i++){
        if((input & 1) == 1){
            count++;
        }
        input >>= 1;
    }
    return count;
    
}

int main(){
    int input;
    int ones;
    int zeros;

    printf("\n Enter a number: ");
    scanf("%d", &input);

    zeros = NumZeros(input);
    ones = NumOnes(input);

    printf("\n Zeros: %d", zeros);
    printf("\n Ones: %d", ones);


    return 0;
}