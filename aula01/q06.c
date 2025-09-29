#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int vetor[10];
    int i, pares = 0;

    for (i = 0; i < 10; i++) {
        vetor[i] = atoi(argv[i + 1]);
        if (vetor[i] % 2 == 0) {
            pares++;
        }
    }

    printf("%d", pares);

    return 0;
}