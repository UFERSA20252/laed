# Algoritmos Recursivos

Pre-requisitos:
- Conceitos básicos de programação em C
- Estruturas de controle (if, else, loops)
- Funções em C
- Noções de pilha de chamadas
- Conceito de recursão
- Noções de complexidade de algoritmos

## Implementação de algoritmos recursivos em C

### Cronômetro

Considere que queremos calcular o tempo de execução de uma rotina em C. Para isso, podemos utilizar a biblioteca `<time.h>`, que fornece funções para manipulação de tempo. Funciona da seguinte maneira:

Dentro da biblioteca `<time.h>`, temos a função `clock()`, que retorna o número de "ticks" desde que o programa começou a ser executado. Podemos usar essa função para medir o tempo de execução de uma rotina específica.

Ou seja, quando temos um trecho de código que queremos medir o tempo de execução, podemos fazer o seguinte:
```c
//...
clock_t inicio, fim;
double tempo;
inicio = clock(); // Marca o início do tempo
// Trecho de código cuja execução queremos medir
fim = clock(); // Marca o fim do tempo
tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo em segundos
printf("Tempo de execução: %f segundos\n", tempo);
//...
```

Neste trecho de código, `inicio` e `fim` são variáveis do tipo `clock_t` que armazenam o número de ticks no início e no fim da execução do trecho de código. A diferença entre `fim` e `inicio` nos dá o número de ticks que o trecho de código levou para ser executado. Dividindo essa diferença por `CLOCKS_PER_SEC`, obtemos o tempo em segundos. Esse `CLOCKS_PER_SEC` é uma constante definida na biblioteca `<time.h>` que indica o número de ticks por segundo.

Agora iremos usar essa técnica para medir o tempo de execução de uma função recursiva simples, como a função que calcula o n-ésimo número da sequência de Fibonacci.

### Fibonacci
A sequência de Fibonacci é definida da seguinte maneira:
- $F(0) = 0$
- $F(1) = 1$
- $F(n) = F(n-1) + F(n-2)$ para $n > 1$
- Ou seja, cada número na sequência é a soma dos dois números anteriores.
- A sequência começa assim: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
- A implementação recursiva da função Fibonacci em C pode ser feita da seguinte maneira:

```c
#include <stdio.h>
#include <time.h>


int fibonacci(int n) {
    if (n < 2) return n; //Aqui consideramos F(0) = 0 e F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    int resultado = fibonacci(30);
    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Fibonacci(30) = %d\n", resultado);
    printf("Tempo de execução: %f segundos\n", tempo);

    return 0;
}
```

Para facilitar os testes, usaremos os parâmetros de argv para passar o valor de n a ser calculado. Assim, o código do main ficará assim:

```c
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

```
Dessa forma, podemos compilar o programa e executá-lo passando o valor de n como argumento na linha de comando. Por exemplo:
```gcc fibonacci.c -o fibonacci
./fibonacci 30
```
Isso calculará o 30º número da sequência de Fibonacci e imprimirá o tempo de execução.

Observe que a implementação recursiva da função Fibonacci é simples e direta, mas não é eficiente para valores grandes de n devido à sua complexidade exponencial. Cada chamada para `fibonacci(n)` resulta em duas chamadas adicionais para `fibonacci(n-1)` e `fibonacci(n-2)`, levando a um crescimento exponencial no número de chamadas conforme n aumenta. Isso pode ser observado claramente ao medir o tempo de execução para valores maiores de n. Por exemplo,
- Para n = 30, o tempo de execução pode ser aceitável.
- Para n = 40, o tempo de execução já pode ser significativamente maior.
- Para n = 50 ou mais, o tempo de execução pode se tornar impraticávelmente longo.

Exemplo na minha máquina:
```bash
$ gcc fibonacci.c -o fibonacci
$ ./fibonacci 30
Fibonacci(30) = 832040
Tempo de execução: 0.006260 segundos
$ ./fibonacci 40 
Fibonacci(40) = 102334155
Tempo de execução: 0.739129 segundos
$ ./fibonacci 50
Fibonacci(45) = 1134903170
Tempo de execução: 7.860224 segundos
```
Observe o salto de tempo significativo ao aumentar n. De 30 para 40, o tempo aumentou de milissegundos para quase um segundo. De 40 para 45, o tempo aumentou para quase 8 segundos. Isso ilustra a ineficiência da abordagem recursiva simples para calcular Fibonacci.
