#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    char cpf[14];
    char *curso;
} usuarios;

typedef struct {
    usuarios *usuario;
    size_t size;
    size_t capacity;
} pessoas;

void exercicio2_lab_criar(pessoas *p) {
    p->capacity = 0;
    p->size = 0;
    p->usuario = NULL;
}

void exercicio2_lab_incluir(pessoas *p, char *nome, char cpf[14], char *curso) {
    p->usuario = realloc(p->usuario, sizeof(usuarios) + sizeof(usuarios) * (p->size));
    p->capacity++;
    p->usuario[p->size].nome = malloc (sizeof(char) * (strlen(nome) + 1));
    strcpy(p->usuario[p->size].nome, nome);
    strcpy(p->usuario[p->size].cpf, cpf);
    p->usuario[p->size].curso = malloc (sizeof(char) * (strlen(curso) + 1));
    strcpy(p->usuario[p->size].curso, curso);
    p->size++;
}

void exercicio2_lab_listar(pessoas *p, int j) {
    if (j == -1){
        for (int i=0; i < p->size; i++) {
            printf("Usuario %d \n", i+1);
            printf("%s", p->usuario[i].nome);
            printf("\n");
            printf("%s", p->usuario[i].cpf);
            printf("\n");
            printf("%s", p->usuario[i].curso);
            printf("\n");
        }
    }
    else if (j == -2) {
        printf("Usuario não encontrado\n");
    }
    else {
        printf("Usuario %d \n", j+1);
        printf("%s", p->usuario[j].nome);
        printf("\n");
        printf("%s", p->usuario[j].cpf);
        printf("\n");
        printf("%s", p->usuario[j].curso);
        printf("\n");
    }
}

int  exercicio2_lab_buscar(pessoas *p, char cpf[14]) {
    for (int i = 0; i < p->size; i++) {
        if (strcmp(p->usuario[i].cpf, cpf) == 0) {
            return i;
        };
    }
    return -2;
}

void exercicio2_lab_excluir(pessoas *p, char cpf[14]) {
    int i = exercicio2_lab_buscar(p, cpf);
    if (i == -2) {
        return;
    }
    free(p->usuario[i].nome);
    free(p->usuario[i].curso);
    for (int j = i; j < p->size; j++) {
        p->usuario[j] = p->usuario[j+1];
    }
    p->size--;
    p->usuario = realloc(p->usuario, p->size * sizeof(usuarios));
    p->capacity--;
}

void exercicio2_lab() {
    pessoas chamada;
    exercicio2_lab_criar(&chamada);
    exercicio2_lab_incluir(&chamada, "edson arantes", "123.456.789-00", "Computaria");
    exercicio2_lab_incluir(&chamada, "edson arantes 2", "133.456.789-00", "Computaria");
    // exercicio2_lab_listar(&chamada, -1);
    exercicio2_lab_excluir(&chamada, "123.456.789-00");
    exercicio2_lab_listar(&chamada, exercicio2_lab_buscar(&chamada, "133.456.789-00"));
    exercicio2_lab_listar(&chamada, exercicio2_lab_buscar(&chamada, "123.456.789-00"));
    printf("%d\n", chamada.size);
   
    for (int i = 0; i < chamada.size; i++) {
        free (chamada.usuario[i].nome);
        free (chamada.usuario[i].curso);
    }
   
    free (chamada.usuario);
}

int main() {
    exercicio2_lab();
    return 0;
}