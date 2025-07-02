#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char caractere, procurado;
    int contador = 0;
    

    arquivo = fopen("teste.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: arquivo teste.txt não encontrado!\n");
        printf("Certifique-se que o arquivo está na mesma pasta.\n");
        
        // Vamos tentar criar o arquivo
        arquivo = fopen("teste.txt", "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "abc abcd ab c bcdef hiabj");
            fclose(arquivo);
            printf("Arquivo criado automaticamente!\n");
        }
        return 1;
    }
    
    printf("Arquivo encontrado! Digite o caractere para contar: ");
    scanf(" %c", &procurado);
    
    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == procurado) {
            contador++;
        }
    }
    
    fclose(arquivo);
    printf("O caractere '%c' aparece %d vezes.\n", procurado, contador);
    
    return 0;
}