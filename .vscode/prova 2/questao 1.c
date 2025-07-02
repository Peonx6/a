#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Inverte(int *v, int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    int temp = v[inicio];
    v[inicio] = v[fim];
    v[fim] = temp;

    Inverte(v, inicio + 1, fim - 1);

  
    printf("%d ", v[inicio]); 
    if (inicio != fim) {
        printf("%d ", v[fim]);
    }
}

int main() {
    int vet[10];

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        vet[i] = rand() % 100;
        printf("%d ", vet[i]);
    }
    printf("\n");

    Inverte(vet, 0, 9);
    printf("\n");

    return 0;
}