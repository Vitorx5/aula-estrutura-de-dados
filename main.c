// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct No {
    int dado;
    struct No* proximo;
};

void inserirInicio (struct No** cabeca, int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = valor;
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
};

void inserirFim (struct No** cabeca, int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = valor;
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
    
    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }
    
    struct No* temp = *cabeca;
    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }
    
    temp->proximo = novoNo;
};

void remover (struct No** cabeca, int valor) {
    struct No* temp = *cabeca, *anterior = NULL;
    
    if (temp != NULL && temp->dado == valor) {
        *cabeca = temp->proximo;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->dado != valor) {
        anterior = temp;
        temp = temp->proximo;
    }
    
    if (temp == NULL) return;
    
    anterior->proximo = temp->proximo;
    free(temp);
}

void imprimirLista (struct No* cabeca) {
    struct No* temp = cabeca;
    
    if (temp == NULL) {
        printf("A lista está fazia. \n");
        return;
    }
    
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d ->", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    struct No* lista = NULL;
    
    printf("Antes das operações:\n");
    imprimirLista(lista);
    
    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirFim(&lista, 30);
    inserirFim(&lista, 40);
    
    printf("\nApós inserções:\n");
    imprimirLista(lista);
    
    remover(&lista, 20);
    
    printf("\nApós remoção do 20:\n");
    imprimirLista(lista);
    
    return 0;
}