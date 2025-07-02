#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  

    char maiores[100];
    
    for (int i = 0; maiores[i] != '\0'; i++){
                maiores[i]=' ';
            
    }
    
    int cont2 = 0;
    int M = 0;

    for (char A = 32; A <= 126; A++) {  
        int cont1 = 0;

        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] == A) {
                cont1++;
            }
        }
         
        if (cont1 == cont2) {
            maiores[M]=A;
            M++;
        }
        if (cont1 > cont2) {
            M=0;
            for (int i = 0; maiores[i] != '\0'; i++){
                maiores[i]=' ';
            }
            cont2 = cont1;
            maiores[M]=A;
            M++;
        }
    }
    for (int i = 0; maiores[i] != '\0'; i++ ){
        if (maiores[i]!=' '){
            printf("'%c' aparece %d vez(es)\n", maiores[i], cont2);
        }
    }

    return 0;
}