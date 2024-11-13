#include <stdio.h>

int multiply(int x, int y){
    return x * y;
}

int main(){
    int input0 = 0, input1 = 0;

    printf("\n Enter two numbers to multiply: ");
    scanf("%d%d", &input0, &input1);
    printf("\n Answer: %d", multiply(input0, input1));


}