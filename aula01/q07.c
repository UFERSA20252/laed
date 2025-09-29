#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int vetor[10];
    int i, menor;

    for (i = 0; i < 10; i++) {
        vetor[i] = atoi(argv[i + 1]);
    }

    menor = vetor[0];
    for (i = 1; i < 10; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    printf("O menor elemento do vetor é: %d\n", menor);

    return 0;
}