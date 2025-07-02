#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *arq = fopen("testes.txt", "w");
    char t[15];
    if (arq == NULL) printf ("erro");
    fgets(t, 15, stdin);
    fprintf(arq, "%s", t); 
    fclose(arq);


}