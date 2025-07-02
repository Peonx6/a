#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (void){
    char frase [50];
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';
    
    int j = 0;
    for(char *i = frase; *i != '\0'; i++, j++){
        if (*i == ' '){
            printf(" ");
            j--;
        }
        if (j%2==0){
            if (islower(*i)){
                *i-=32;
                printf("%c", *i);
            }
            else {
                printf("%c", *i);
                }
        }
        
        if (j%2!=0) {
            if (isupper(*i)){
                *i+=32;
                printf("%c", *i);
            }
            else {
                printf("%c", *i);
                }
        }
    }

    printf("\n");
    return 0;
}