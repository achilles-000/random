#include <stdio.h>
#include <stdint.h>

int main(){

    uint8_t a = 1; // 0001
    uint8_t b = 4; // 0100
    uint8_t c = 17; // 10001



    printf("\n%d", b >> 1); // Shift to the right by 1, 0100 >> 1 = 0010 or 2
    printf("\n%d", b << 2); // Shift to the left 0100 << 1 = 0100 or 16
    printf("\n%d", c << 1); // Shift to the right 10001 << 1 = 100010 or 32 + 2 = 34



    return 0;
}