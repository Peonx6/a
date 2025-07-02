#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Escreva sua frase:\n");

    char *original = NULL;
    int i = 0;
    char c;

    while ((c = getchar()) != '\n' && c != EOF) {
        original = realloc(original, (i + 1) * sizeof(char));
        
        original[i] = c;
        i++;
    }

    original = realloc(original, (i + 1) * sizeof(char));
    original[i] = '\0';

    char *semEspacos = malloc((i + 1) * sizeof(char));
    

    int k = 0;
    for (int j = 0; j < i; j++) {
        if (original[j] != ' ') {
            semEspacos[k] = original[j];
            k++;
        }
    }
    semEspacos[k] = '\0';

    printf("Frase sem espacos: %s\n", semEspacos);

    free(original);
    free(semEspacos);

    return 0;
}