#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct Node {
  int data;
  struct Node *esq;
  struct Node *dir;
} Node;

typedef struct Fila {
  Node *N[100];
  int fim = 0;
  int ini = 0;
  int tam = 0;
  int cap = 100;
} fila;
// Função para criar um novo nó
Node *createNode(int data) {
  Node *novo = (Node *)malloc(sizeof(Node));
  novo->data = data;
  novo->esq = NULL;
  return novo;
}

/** Protótifim das funções */
Node *createNode(int);
Node *inserir(Node *, int);
bool busca(Node *, int);
void liberarArvore(Node *);
void emOrdem(Node *);
void preOrdem(Node *);
void fimOrdem(Node *);
int altura(Node *);
void inserirFila(fila *, Node *no);
Node *removerFila(fila *, Node *no);
Node *remove(Node *, int);
void travessiaNivel(Node *);

int main() {
  struct Node *raiz = 0;
  raiz = inserir(raiz, 30);
  raiz = inserir(raiz, 20);
  raiz = inserir(raiz, 40);
  raiz = inserir(raiz, 10);
  raiz = inserir(raiz, 25);
  raiz = inserir(raiz, 35);
  raiz = inserir(raiz, 50);
  raiz = inserir(raiz, 5);
  raiz = inserir(raiz, 28);
  raiz = inserir(raiz, 22);
  raiz = inserir(raiz, 23);
  raiz = inserir(raiz, 24);

//   travessiaNivel(raiz);

  raiz = remove(raiz, 25);
}

void inserir(fila, Node *no);
Node *remover(fila, Node *no);
// Função para inserir um novo nó na árvore
Node *inserir(Node *raiz, int data) {
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
bool busca(Node *raiz, int data) {
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
void liberarArvore(Node *raiz) {
  if (raiz != NULL) {
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
  }
}

void emOrdem(Node *raiz) {
  if (raiz != NULL) {
    emOrdem(raiz->esq);
    printf("%d ", raiz->data);
    emOrdem(raiz->dir);
  }
}

void preOrdem(Node *raiz) {
  if (raiz != NULL) {
    printf("%d ", raiz->data);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
  }
}

void fimOrdem(Node *raiz) {
  if (raiz != NULL) {
    fimOrdem(raiz->esq);
    fimOrdem(raiz->dir);
    printf("%d ", raiz->data);
  }
}

int maior(int a, int b) { return (a > b) ? a : b; }
int altura(Node *raiz) {
  if (raiz == NULL) {
    return -1; // Altura de árvore vazia é -1
  }
  int alturaEsq = altura(raiz->esq);
  int alturaDir = altura(raiz->dir);
  return 1 + maior(alturaEsq, alturaDir);
}

void inserirFila(Fila *f, Node *N) {
  f->tam++;
  f->N[f->fim++] = N;
}

Node *removerFila(fila *f) {
  if (f->ini == f->fim)
    return 0;
  f->tam--;
  return f->N[f->ini++];
}

void travessiaNivel(Node *raiz) {
  Fila *f = (Fila *)malloc(sizeof(fila));
  inserirFila(f, raiz);
  Node *n;
  while (f->fim != f->ini) {
    n = removerFila(f);
    printf("%d ", n->data);
    if (n->esq != 0) {
      inserirFila(f, n->esq);
    }
    if (n->dir != 0) {
      inserirFila(f, n->dir);
    }
  }
  printf("\n");
}

Node *remove(Node *raiz, int v) {
  Node *aux;
  //   Caso 01:
  if (raiz == 0) {
    return raiz;
  }
  // Caso 02a:
  if (v < raiz->data) {
    raiz->esq = remove(raiz->esq, v);

  } // Caso 02b:
  else if (v > raiz->data) {
    raiz->dir = remove(raiz->dir, v);
  }
  // Caso 03: 
  else {
    if (raiz->dir == 0 && raiz->esq == 0) {
      free(raiz);
      return 0;
    }
    if (raiz->dir == 0 && raiz->esq != 0) {
      aux = raiz->esq;
      free(raiz);
      return aux;
    }
    if (raiz->dir != 0 && raiz->esq == 0) {
      aux = raiz->dir;
      free(raiz);
      return aux;
    }
    if(raiz->dir != 0 && raiz->esq != 0){
        aux = raiz->esq;
        while(aux->dir != 0){
            aux = aux->dir;
        }
        raiz->data = aux->data;
        aux->data = v;
        raiz->esq = remove(raiz->esq, v);
    }
  }
  return raiz;
}