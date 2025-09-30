#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    int n, i;
    if (argc > 1) {
        n = atoi(argv[1]);
    } else {
        printf("Digite o número de termos da sequência de Fibonacci: ");
        scanf("%d", &n);
    }
    fibonacci(n); // Chamada para gerar a pilha de chamadas

    return 0;
}