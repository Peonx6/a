#include <stdio.h>
#include <string.h>

int main() {
    char stringA[50];
    char stringB[50];

    fgets(stringA, 50, stdin);
    fgets(stringB, 50, stdin);

    stringA[strcspn(stringA, "\n")] = 0;
    stringB[strcspn(stringB, "\n")] = 0;

    int lenA = strlen(stringA);
    int lenB = strlen(stringB);
    int encontrado = 0;

    if (lenB > lenA) {
        printf("Nao e substring\n");
        return 0;
    }

    for (int i = 0; i <= lenA - lenB; i++) {
        int j;
        for (j = 0; j < lenB; j++) {
            if (stringA[i + j] != stringB[j]) {
                break;
            }
        }
        if (j == lenB) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("E substring\n");
    } else {
        printf("Nao e substring\n");
    }

    return 0;
}