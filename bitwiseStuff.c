#include <stdio.h>
#include <stdint.h>

int main(){

    uint8_t a = 1; // 0001
    uint8_t b = 4; // 0100
    uint8_t c = 17; // 10001



    printf("\n%d", b >> 1); // Shift to the right by 1, 0100 >> 1 = 0010 or 2
    printf("\n%d", b << 2); // Shift to the left 0100 << 1 = 0100 or 16
    printf("\n%d", c << 1); // Shift to the right 10001 << 1 = 100010 or 32 + 2 = 34
    printf("\n%d", a & b); // Bitwise AND, 0001 | & 0100 = 0000, returns true only if both are true 1 & 1 = 1 but 1 & 0 = 0
    printf("\n%d", a & a); // 0001 & 0001 = 0001 
    printf("\n%d", a | b ); //bitwise OR ->> 0001 | 0100 = 0101, returns true if one of the value is true (1 | 1 = 1) and (1 | 0 = 1)



    return 0;
}