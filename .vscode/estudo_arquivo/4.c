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
    printf("Digite o nome: ");
    cadastrar_nome(f);
    printf("Digite o curso: ");
    cadastrar_curso(f);
    printf("Digite o CPF: ");
    cadastrar_cpf(f);
}

int buscar_usuario(usuarios *f, char cpf[15], int c){
    for (int i = 0; i < c; i++){
        if (strcmp(f[i].cpf, cpf) == 0){
            printf("\nUsuario encontrado:\n");
            printf("Nome: %s\n", f[i].nome);
            printf("Curso: %s\n", f[i].curso);
            printf("CPF: %s\n", f[i].cpf);
            return (i);
        }
    }
    return -1;
}

void listar_usuarios(usuarios *f, int j, int c) {
    if (j == -2){
        printf("\n=== LISTA DE TODOS OS USUÁRIOS ===\n");
        for (int i=0; i < c; i++) {
            printf("Usuario %d:\n", i+1);
            printf("Nome: %s\n", f[i].nome);
            printf("CPF: %s\n", f[i].cpf);
            printf("Curso: %s\n", f[i].curso);
            printf("------------------------\n");
        }
    }
    else if (j == -1) {
        printf("\nUsuario nao encontrado!\n");
    }
    else {
        printf("\n=== USUARIO ENCONTRADO ===\n");
        printf("Usuario %d:\n", j+1);
        printf("Nome: %s\n", f[j].nome);
        printf("Curso: %s\n", f[j].curso);
        printf("CPF: %s\n", f[j].cpf);
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
            printf("Usuario excluido com sucesso!\n");
            return 1;       
        }
    }
    printf("Usuario nao encontrado para exclusao!\n");
    return 0;  
}

void mostrar_menu() {
    printf("\n=== SISTEMA DE GERENCIAMENTO DE USUÁRIOS ===\n");
    printf("1. Cadastrar usuario\n");
    printf("2. Buscar usuario por CPF\n");
    printf("3. Listar todos os usuarios\n");
    printf("4. Excluir usuario\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

void escrever_arquivo(usuarios *f, int c){
    FILE *arq = fopen("usuarios.txt", "w");

    for (int i = 0; i < c; i++){
        fprintf(arq, "%s", f[i].nome);
        fprintf(arq, "\n");
        fprintf(arq, "%s", f[i].cpf);
        fprintf(arq, "\n");
        fprintf(arq, "%s", f[i].curso);
        fprintf(arq, "\n");
    }
    fclose(arq);

}

int main (void){
    int contador = 0;
    int capacidade = 1;    
    usuarios *lista = (usuarios*)malloc(sizeof(usuarios));
    int opcao;
    char cpf_busca[15];
    
    if (lista == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    do {
        mostrar_menu();
        scanf("%d", &opcao);
        while (getchar() != '\n'); 
        
        switch(opcao) {
            case 1: 
                if (contador >= capacidade) {
                    capacidade++;
                    lista = realloc(lista, sizeof(usuarios) * capacidade);
                    if (lista == NULL) {
                        printf("Erro ao realocar memoria!\n");
                        return 1;
                    }
                }
                
                cadastrar_usuario(&lista[contador]);
                printf("\nUsuario cadastrado com sucesso!\n");
                printf("Nome: %s\n", lista[contador].nome);
                printf("CPF: %s\n", lista[contador].cpf);
                printf("Curso: %s\n", lista[contador].curso);
                contador++;
                break;
                
            case 2: 
                if (contador == 0) {
                    printf("Nenhum usuario cadastrado!\n");
                    break;
                }
                
                printf("Digite o CPF para buscar: ");
                fgets(cpf_busca, 15, stdin);
                cpf_busca[strcspn(cpf_busca, "\n")] = '\0';
                
                int resultado = buscar_usuario(lista, cpf_busca, contador);
                if (resultado == -1) {
                    printf("Usuario nao encontrado!\n");
                }
                break;
                
            case 3: 
                if (contador == 0) {
                    printf("Nenhum usuario cadastrado!\n");
                } else {
                    listar_usuarios(lista, -2, contador);
                }
                break;
                
            case 4: 
                if (contador == 0) {
                    printf("Nenhum usuario cadastrado!\n");
                    break;
                }
                
                printf("Digite o CPF do usuario a ser excluido: ");
                fgets(cpf_busca, 15, stdin);
                cpf_busca[strcspn(cpf_busca, "\n")] = '\0';
                
                excluir_usuario(lista, &contador, cpf_busca);
                break;
                
            case 5: 
                printf("Saindo do sistema...\n");
                break;
                
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        
    } while(opcao != 5);
    
    escrever_arquivo(lista, contador);

    for (int i = 0; i < contador; i++) {
        free(lista[i].nome);
        free(lista[i].curso);
    }
    free(lista);
    
    return 0;
}