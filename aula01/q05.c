#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 11) {
        printf("Erro: Forneça exatamente 10 números inteiros como argumentos.\n");
        return 1;
    }

    int vetor[10];
    for (int i = 0; i < 10; i++) {
        vetor[i] = atoi(argv[i + 1]);
    }

    // Inverte o vetor
    for (int i = 0; i < 5; i++) {
        int temp = vetor[i];
        vetor[i] = vetor[9 - i];
        vetor[9 - i] = temp;
    }

    printf("Vetor invertido:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}