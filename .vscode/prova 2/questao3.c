#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  

    int ind = 0;

    for (char A = 32; A <= 126; A++) {  
        int cont1 = 0;

        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] == A) {
                cont1++;
            }
        }
         
        if (cont1 == 2) {
            ind=0;
        }
        if (cont1 != 2 && cont1 != 0) {
            ind = 1;
        }
        
    }

    if (ind == 0){
        printf("0");
    }

    if (ind == 1){
        printf("1");
    }
 
    return 0;
}