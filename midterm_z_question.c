#include <stdio.h>

int main() {
    char symbol = '*';
    char space = ' ';
    int height = 0;

    scanf("%d", &height);

    for(int i = height; i >= 0; i--) {
        if(i == height || i == 0) {
            for(int j = height; j >= 0; j--) {
                printf("%c", symbol);
            }
        } 
        else if(i != 0) {

                for(int y = 0; y <= height; y++) {
                    if(y == i) {
                        printf("%c", symbol);
                    } 
                    else {
                        printf("%c", space);
                    }
                }
            
        }
        printf("\n");
    }

    return 0;
}
