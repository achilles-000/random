#include <stdio.h>



struct Features{
    int width;
    char symbol;
    int height;
};
//aa
int main(){

//Creates the variable features1
struct Features features1;

features1.width = 1;
features1.symbol = 'x';

printf("\n%d", features1.width );
printf("\n%c", features1.symbol );




    return 0;
}