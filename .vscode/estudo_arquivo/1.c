#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *nome;
    char cpf[15];
    char *curso;
} usuarios;

void cadastrar_nome (usuarios *f){
    char *nome = malloc(sizeof(char)*2);
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        nome[i]=c;
        i++;
        nome = realloc(nome, (i + 1) * sizeof(char));
    }
    
    nome[i] = '\0';

    f->nome = nome; 
}

void cadastrar_cpf(usuarios *f){
    char cpf_[15];
    fgets(cpf_, 15, stdin);
    
    cpf_[strcspn(cpf_, "\n")] = '\0';
    
    strcpy(f->cpf, cpf_);
}



void cadastrar_curso (usuarios *f){
    char *curso = malloc(sizeof(char)*2);
    int i = 0;
    char c;
        while ((c = getchar()) != '\n' && c != EOF) {
        curso[i]=c;
        i++;
        curso = realloc(curso, (i + 1) * sizeof(char));
    }
    
    curso[i] = '\0';

    f->curso = curso; 
}

void cadastrar_usuario(usuarios *f){
    cadastrar_nome(f);
    cadastrar_curso(f);
    cadastrar_cpf(f);
}

int buscar_usuario(usuarios *f, char cpf[15], int c){
    for (int i = 0; i < c; i++){
        if (strcmp(f[i].cpf, cpf) == 0){
            printf("\nUsuario encontrado:\n");
            printf("Nome: %s\n", f[i].nome);
            printf("curso: %s\n", f[i].curso);
            printf("cpf: %s\n", f[i].cpf);
            return (i);
        }
    }
    return -1;
}

void listar_usuarios(usuarios *f, int j, int c) {
    if (j == -2){
        for (int i=0; i < c; i++) {
            printf("Usuario %d \n", i+1);
            printf("%s", f[i].nome);
            printf("\n");
            printf("%s", f[i].cpf);
            printf("\n");
            printf("%s", f[i].curso);
            printf("\n");
        }
    }
    else if (j == -1) {
        printf("\nUsuario nao encontrado\n");
    }
    else {
        printf("Usuario %d \n", j+1);
        printf("%s", f[j].nome);
        printf("\n");
        printf("%s", f[j].curso);
        printf("\n");
        printf("%s", f[j].cpf);
        printf("\n");
    }
}

int excluir_usuario(usuarios *f, int *contador, char cpf[15]){
    for(int i = 0; i < *contador; i++){
        if (strcmp(f[i].cpf, cpf) == 0){

            free(f[i].nome);
            free(f[i].curso);
            
      
            for(int j = i; j < *contador - 1; j++){
                f[j] = f[j + 1];  
            }
            
            (*contador)--;  
            return 1;       
        }
    }
    return 0;  
}


int main (void){
    int contador = 0;
    int capacidade = 1;    
    usuarios *lista = (usuarios*)malloc(sizeof(usuarios));
    cadastrar_usuario(&lista[contador]);
    
    printf("\nUsuario cadastrado:\n");
    printf("Nome: %s\n", lista[contador].nome);
    printf("CPF: %s\n", lista[contador].cpf);
    printf("Curso: %s\n", lista[contador].curso);
    contador++;
    capacidade++;
    
    lista = realloc(lista, sizeof(usuarios)*capacidade);
    getchar();
    cadastrar_usuario(&lista[contador]);
 
    printf("\nUsuario cadastrado:\n");
    printf("Nome: %s\n", lista[contador].nome);
    printf("CPF: %s\n", lista[contador].cpf);
    printf("Curso: %s\n", lista[contador].curso);
    capacidade++;
    contador++;
    lista = realloc(lista, sizeof(usuarios)*capacidade);
    
    
    printf("\nInsira um cpf para buscar usuario: ");
    char cpf1[15];
    
    
    while (getchar() != '\n'); 
    fgets(cpf1, 15, stdin);
    cpf1[strcspn(cpf1, "\n")] = '\0';
    
    listar_usuarios(lista, buscar_usuario(lista, cpf1, contador), contador);

    excluir_usuario(lista, &contador, cpf1);

    listar_usuarios(lista, buscar_usuario(lista, cpf1, contador), contador);

    for (int i = 0; i < contador; i++) {
        free(lista[i].nome);
        free(lista[i].curso);
}
    free(lista);
    
}