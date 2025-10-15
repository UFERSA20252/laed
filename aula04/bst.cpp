#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




// Definição da estrutura do nó da árvore
typedef struct Node {
    int data;
    struct Node* esq;
    struct Node* dir;
} Node;

typedef struct Fila{
    Node *N[100];
    int pos = 0;
    int ini = 0;
    int tam = 100;
}fila;
// Função para criar um novo nó
Node* createNode(int data) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = data;
    novo->esq = NULL;
    return novo;
}

/** Protótipos das funções */
Node* createNode(int);
Node* inserir(Node*, int);
bool busca(Node*, int);
void liberarArvore(Node*);
void emOrdem(Node*);
void preOrdem(Node*);
void posOrdem(Node*);
int altura(Node*);
void inserir(fila*, Node *no);
Node* remover(fila*, Node *no);
void travessiaNivel(Node*);

int main() {
    struct Node* raiz = 0;
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 42);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 31);
    raiz = inserir(raiz, 17);
    raiz = inserir(raiz, 19);

    Fila *f = (Fila*)malloc(sizeof(Fila));
    inserir(f, raiz);
    inserir(f, raiz->dir);
    inserir(f, raiz->esq);
}

void inserir(fila, Node *no);
Node* remover(fila, Node *no);
// Função para inserir um novo nó na árvore
Node* inserir(Node* raiz, int data) {
    if (raiz == NULL) {
        return createNode(data);
    }
    if (data < raiz->data) {
        raiz->esq = inserir(raiz->esq, data);
    } else {
        raiz->dir = inserir(raiz->dir, data);
    }
    return raiz;
}

// Função para buscar um valor na árvore
bool busca(Node* raiz, int data) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->data == data) {
        return true;
    }
    if (data < raiz->data) {
        return busca(raiz->esq, data);
    } else {
        return busca(raiz->dir, data);
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

void inserir(Fila *f, Node *N){
    f->tam++;   
    f->N[f->pos++] = N;
}

Node* remover(fila *f){
    f->tam--;
    return f->N[f->ini++];
}