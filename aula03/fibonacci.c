#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonacci(int);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    clock_t inicio, fim;
    double tempo;
    inicio = clock();
    int resultado = fibonacci(n);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Fibonacci(%d) = %d\n", n, resultado);
    printf("Tempo de execução: %f segundos\n", tempo);
    return 0;
}
int fibonacci(int n) {
    if (n < 2) return n; //Aqui consideramos F(0) = 0 e F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2);
}