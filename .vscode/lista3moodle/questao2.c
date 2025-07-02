#include <stdio.h>
#include <stdlib.h>

int par = 0;
int impar = 0;

struct NUMERO{
    int *vet;
    int tam;
};

typedef struct NUMERO NUMERO;

void INIC(NUMERO *L){
    for (int i = 0; i < L->tam; i++){
        L->vet[i]=0;
    }  
}

void INSERIR(NUMERO *J, int i){
    
    if (impar >= J->tam){
        impar = 0;
    }
    
    if (par <= 0){
        par = J->tam;
    }
    
    if (i%2 != 0){
        J->vet[impar]=i;
        impar++;
    }

    else {
        par--;
        J->vet[par]=i;
        
    }
}

void RETIRAR(NUMERO *L, int j){
    int mem = 0;
    for(int i =0; i<L->tam; i++){
            if(L->vet[i]==j){
                for (int k=i; k<(L->tam); k++){
                    mem=L->vet[k+1];
                    L->vet[k]=mem;
                }
                L->vet[(L->tam)-1]=0;
                break;
            }
    }
}

void LISTAR(NUMERO *L){
    for(int i =0; i<L->tam; i++){
        printf("%d ", L->vet[i]);
    }
}

int main (void){
   
    int valor = 0;
    
    int valor1 = 0;
    
    NUMERO n;
   
    scanf("%d", &n.tam);
   
    par = n.tam;
    
    n.vet = (int*)malloc(n.tam * sizeof(int));
    
    INIC(&n);
    
    for (int i = 0; i < n.tam; i++) {
        scanf("%d", &valor);
        INSERIR(&n, valor);
    }
    
    LISTAR(&n);
    
    scanf("%d", &valor1);
    
    RETIRAR(&n, valor1);
    
    LISTAR(&n);
    
    free(n.vet);
    return 0;
}