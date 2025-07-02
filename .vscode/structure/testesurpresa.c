#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct produto{
    char nome[30];
    int codigo;
    float valor;
};

typedef struct produto produto;

int main(void){
    produto *p = NULL;
   
    p = (produto*)malloc(10*sizeof (produto));
    
    strcpy(p->nome, "Pe de Moleque");
    p->codigo = 13205;
    p->valor = 0.20;

    printf("%s ", p->nome);
    printf("%d ", p->codigo);
    printf("%f ", p->valor);
    printf("\n");


    p++;

    strcpy(p->nome, "Cocada Baiana");
    p->codigo = 15202;
    p->valor = 0.50;

    printf("%s ", p->nome);
    printf("%d ", p->codigo);
    printf("%f ", p->valor);
    printf("\n");

}