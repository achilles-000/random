#include <stdio.h>
#include <stdint.h> //Lets me us uint8_t (8 bits), no matter the system its run on it will be 8 bits

int main(){

    uint8_t a = 1; // 0001      //Unsigned integer of 8 bits
    uint8_t b = 4; // 0100      //Should be used when using bitwise operations
    uint8_t c = 17; // 10001



    printf("\n%d", b >> 1); // Shift to the right by 1, 0100 >> 1 = 0010 or 2
    printf("\n%d", b << 2); // Shift to the left 0100 << 1 = 0100 or 16
    printf("\n%d", c << 1); // Shift to the right 10001 << 1 = 100010 or 32 + 2 = 34
    printf("\n%d", a & b); // Bitwise AND, 0001 | & 0100 = 0000, returns true only if both are true 1 & 1 = 1 but 1 & 0 = 0
    printf("\n%d", a & a); // 0001 & 0001 = 0001 
    printf("\n%d", a | b ); //bitwise OR ->> 0001 | 0100 = 0101, returns true if one of the value is true (1 | 1 = 1) and (1 | 0 = 1)
    printf("\n%d", b ^ c); //Bitwise XOR operator,  returns true (1) if the corresponding bits are different and false (0) if the are the same
    //Output of 00100 ^ 10001 should be 01010 or 21

    printf("\n%u", (uint8_t)~c); // bitwise NOT operator ~, should change 0 to 1 and 1 to 0... ~0001 0001 since this is uint8_t ( 8 bits) there is 8 zeros
    // so ~17 / ~0001 0001 should be 1110 1110 or 238
    //Also it is typecasted otherwise it returns an int which is 32 bits or 4 bytes

    return 0;
}