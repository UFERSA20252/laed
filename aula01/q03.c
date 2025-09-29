#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
    int vetor[10];
    int i, soma = 0;
    float media;
    for(i = 0; i < 10; i++) {
        vetor[i] = atoi(argv[i + 1]);
        soma += vetor[i];
    }
    media = soma / 10.0;
    printf("%.2f", media);
    return 0;
}