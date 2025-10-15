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

/** Protótipos das funções */
Node* createNode(int);
Node* insert(Node*, int);
bool search(Node*, int);
void liberarArvore(Node*);
void emOrdem(Node*);
void preOrdem(Node*);
void posOrdem(Node*);
int altura(Node*);
void travessiaNivel(Node*);

int main() {

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

void emOrdem(Node* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->data);
        emOrdem(raiz->dir);
    }
}

void preOrdem(Node* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->data);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(Node* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->data);
    }
}

int maior(int a, int b) {
    return (a > b) ? a : b;
}
int altura(Node* raiz) {
    if (raiz == NULL) {
        return -1; // Altura de árvore vazia é -1
    }
    int alturaEsq = altura(raiz->esq);
    int alturaDir = altura(raiz->dir);
    return 1 + maior(alturaEsq, alturaDir);
}