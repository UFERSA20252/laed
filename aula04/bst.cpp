#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura do nó da árvore
typedef struct Node {
    int data;
    struct Node* esq;
    struct Node* dir;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = data;
    novo->esq = NULL;
    return novo;
}

int main() {
    Node* raiz = createNode(10);
    printf("Raiz: %d\n", raiz->data);
    return 0;
}

// Função para inserir um novo nó na árvore
Node* insert(Node* raiz, int data) {
    if (raiz == NULL) {
        return createNode(data);
    }
    if (data < raiz->data) {
        raiz->esq = insert(raiz->esq, data);
    } else {
        raiz->dir = insert(raiz->dir, data);
    }
    return raiz;
}

// Função para buscar um valor na árvore
bool search(Node* raiz, int data) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->data == data) {
        return true;
    }
    if (data < raiz->data) {
        return search(raiz->esq, data);
    } else {
        return search(raiz->dir, data);
    }
}

// Função para liberar a memória da árvore
void liberarArvore(Node* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}