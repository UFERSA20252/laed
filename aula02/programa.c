#include <stdio.h>
int main() {
    int a = 5;
    int b = 0;
    int c = a / b; // Erro: divisão por zero
    printf("Resultado: %d\n", c);
    return 0;
}