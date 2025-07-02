#include <stdio.h>
#include <stdlib.h>

int par = 0;
int impar = 0;

struct NUMERO {
    int *vet;
    int tam;
};

typedef struct NUMERO NUMERO;

void INIC(NUMERO *L) {
    for (int i = 0; i < L->tam; i++) {
        L->vet[i] = 0;
    }
}

void INSERIR(NUMERO *J, int i) {
    if (i % 2 != 0) { // Ímpar
        if (impar >= J->tam) return;
        J->vet[impar] = i;
        impar++;
    } else { // Par
        par--;
        if (par < 0) return;
        J->vet[par] = i;
    }
}

void LISTAR(NUMERO *L) {
    for (int i = 0; i < L->tam; i++) {
        printf("%d ", L->vet[i]);
    }
    printf("\n");
}

int main(void) {
    int valor = 0;
    NUMERO n;

    scanf("%d", &n.tam);

    if (n.tam <= 0) {
        printf("Tamanho inválido.\n");
        return 1;
    }

    par = n.tam;
    impar = 0;

    n.vet = (int *)malloc(n.tam * sizeof(int));
    if (!n.vet) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    INIC(&n);

    for (int i = 0; i < n.tam; i++) {
        scanf("%d", &valor);
        INSERIR(&n, valor);
    }

    LISTAR(&n);
    free(n.vet);

    return 0;
}
