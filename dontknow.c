#include <stdio.h>
#include <string.h>

int isVowel(char letter){
    char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for(int i = 0; i < 10; i++){
        if (vowel[i] == letter){
            return 1;
            break;
        }
        //return 0;
    }
    return 0;
}

int main(){

    char sentence[1000];
    int counter = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    for(int i = 0; i < strlen(sentence); i++){
        if ( isVowel(sentence[i])){
            counter++;
        }
    }
    printf("\n%d", counter);

    return 0;
}