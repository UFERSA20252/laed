//Crie um programa que encontre o maior elemento de um vetor de 10 números inteiros
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc != 11) {
        printf("Erro: Informe 10 números inteiros como argumentos.\n");
        return 1;
    }
    int numeros[10];
    for (int i = 0; i < 10; i++) {
        numeros[i] = atoi(argv[i + 1]);
    }
    int maior = numeros[0];
    for (int i = 1; i < 10; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }
    printf("%d", maior);
    return 0;
}