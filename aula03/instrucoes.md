# Algoritmos Recursivos

Pre-requisitos:
- Conceitos básicos de programação em C
- Estruturas de controle (if, else, loops)
- Funções em C
- Noções de pilha de chamadas
- Conceito de recursão
- Noções de complexidade de algoritmos

## Estudo de caso: Melhoria de performance para Fibonacci

### Cronômetro

Considere que queremos calcular o tempo de execução de uma rotina em C. Para isso, podemos utilizar a biblioteca `<time.h>`, que fornece funções para manipulação de tempo. Funciona da seguinte maneira:

```c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    // Trecho de código cuja execução queremos medir
    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", tempo);

    return 0;
}
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

### Limite da representação inteira
Outro ponto importante a ser considerado é o limite da representação inteira em C. A função `fibonacci` retorna um `int`, que geralmente é um inteiro de 32 bits. Isso significa que o valor máximo que pode ser representado é 2.147.483.647 (2^31 - 1). A sequência de Fibonacci cresce rapidamente, e o 47º número da sequência já excede esse valor, resultando em overflow e retornando um valor incorreto. Portanto, ao testar a função com valores maiores de n, é importante estar ciente desse limite.

Uma estimação da quantidade de dígitos do n-ésimo número de Fibonacci pode ser feita usando a fórmula de Binet, que envolve a razão áurea (phi). A fórmula é a seguinte:

$\displaystyle d(n) \approx \left\lfloor n \cdot \log_{10}\!\left(\varphi\right) \;-\; \tfrac{1}{2}\log_{10}(5) \right\rfloor + 1$

$\displaystyle \text{onde } \varphi = \frac{1 + \sqrt{5}}{2}$


Exemplo:
- F(10) = 55 (2 dígitos)
- F(20) = 6765 (4 dígitos)
- F(30) = 832040 (6 dígitos)
- F(40) = 102334155 (9 dígitos)
- F(50) = 12586269025 (11 dígitos)
- F(60) = 1548008755920 (13 dígitos)

Como a representação inteira em C é limitada, para valores maiores de n, podemos usar tipos de dados maiores, como `long long int`, que geralmente é um inteiro de 64 bits, permitindo representar valores até 9.223.372.036.854.775.807 (2^63 - 1). No entanto, mesmo com `long long int`, o 93º número da sequência de Fibonacci já excede esse valor. Portanto, para valores muito grandes de n, seria necessário usar bibliotecas de precisão arbitrária, como GMP (GNU Multiple Precision Arithmetic Library) ou implementar uma estrutura de dados personalizada para lidar com números grandes.

A título de curiosidade, a representação de números em C é a seguinte:
- `char`: geralmente 8 bits, intervalo de -128 a 127 (ou 0 a 255 se for `unsigned char`)
- `short int`: geralmente 16 bits, intervalo de -32.768 a 32.767
- `int`: geralmente 32 bits, intervalo de -2.147.483.648 a 2.147.483.647
- `long int`: geralmente 32 ou 64 bits, dependendo da arquitetura (em sistemas de 64 bits, geralmente é 64 bits)
- `long long int`: geralmente 64 bits, intervalo de -9.223.372.036.854.775.808 a 9.223.372.036.854.775.807
- `float`: geralmente 32 bits, precisão de cerca de 7 dígitos decimais
- `double`: geralmente 64 bits, precisão de cerca de 15-16 dígitos decimais
- `long double`: geralmente 80, 96 ou 128 bits dependendo da implementação, com precisão maior que `double`
- `unsigned int`, `unsigned long int`, `unsigned long long int`: versões sem sinal dos tipos inteiros, com intervalos que começam em 0 e vão até o dobro do valor máximo do tipo com sinal correspondente.

### Utilizando a memória de forma eficiente
A implementação recursiva simples da função Fibonacci é ineficiente em termos de tempo de execução devido à grande quantidade de chamadas recursivas redundantes. Para melhorar a eficiência, podemos utilizar técnicas como memoização ou programação dinâmica.

#### Memoização
A memoização é uma técnica que armazena os resultados de chamadas de função para evitar cálculos redundantes. Podemos implementar a memoização usando um array para armazenar os valores já calculados. Aqui está um exemplo de como fazer isso:
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

long long int memo[MAX];

long long int fibonacci(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }

    clock_t start = clock();
    printf("Fibonacci(40) = %lld\n", fibonacci(40));
    clock_t end = clock();
    printf("Tempo de execução: %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Fibonacci(50) = %lld\n", fibonacci(50));
    end = clock();
    printf("Tempo de execução: %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
```

Nesta implementação, usamos um array `memo` para armazenar os valores já calculados da sequência de Fibonacci. Antes de calcular `fibonacci(n)`, verificamos se o valor já está armazenado em `memo[n]`. Se estiver, retornamos esse valor diretamente, evitando chamadas recursivas desnecessárias. Caso contrário, calculamos o valor, armazenamos em `memo[n]` e retornamos.

Apesar dos resultado do fibonacci para números grandes não poderem ser representados em tipos inteiros padrão, a técnica de memoização é muito útil para melhorar a eficiência de algoritmos recursivos que possuem subproblemas sobrepostos.

### Análise de complexidade

A complexidade de tempo da implementação recursiva simples da função Fibonacci é O(2^n), devido ao fato de que cada chamada para `fibonacci(n)` resulta em duas chamadas adicionais para `fibonacci(n-1)` e `fibonacci(n-2)`. Isso leva a um crescimento exponencial no número de chamadas conforme n aumenta.

Quando utilizamos memoização, a complexidade de tempo é reduzida para O(n), pois cada valor de Fibonacci é calculado apenas uma vez e armazenado para reutilização em chamadas subsequentes. A complexidade de espaço também é O(n) devido ao array de memoização que armazena os valores calculados.

Para melhorar mais ainda a eficiência, podemos usar uma abordagem iterativa que calcula os valores de Fibonacci em uma única passagem, utilizando apenas duas variáveis para armazenar os dois últimos valores da sequência. A complexidade de tempo permanece O(n), mas a complexidade de espaço é reduzida para O(1). Aqui está um exemplo de implementação iterativa:

```c
#include <stdio.h>
long long int fibonacci(int n) {
    if (n <= 1) return n;
    long long int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
```

> A complexidade de espaço dessa abordagem é $O(1)$ porque usamos apenas um número fixo de variáveis, independentemente do tamanho de $n$. Já a complexidade de tempo continua sendo $O(n)$ porque ainda precisamos iterar de 2 até n para calcular o n-ésimo número de Fibonacci.

### Melhoria definitiva de performance de Tempo e Espaço
A melhoria definitiva de performance tanto em tempo quanto em espaço pode ser alcançada utilizando a fórmula de Binet, que permite calcular o n-ésimo número de Fibonacci diretamente, sem a necessidade de cálculos recursivos ou iterativos. A fórmula de Binet é a seguinte:
$F(n) = \frac{\varphi^n - (1 - \varphi)^n}{\sqrt{5}}$
onde $\varphi = \frac{1 + \sqrt{5}}{2}$ é a razão áurea.

Aqui está uma implementação em C que utiliza a fórmula de Binet para calcular o n-ésimo número de Fibonacci:

```c
#include <stdio.h>
#include <math.h>

long long int fibonacci(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}
int main() {
    int n = 50; // Exemplo de valor para n
    printf("Fibonacci(%d) = %lld\n", n, fibonacci(n));
    return 0;
}
```
Nesta implementação, usamos a função `pow` da biblioteca `<math.h>` para calcular $\varphi^n$ e a função `sqrt` para calcular $\sqrt{5}$. A função `round` é usada para arredondar o resultado para o inteiro mais próximo, já que a fórmula de Binet pode resultar em um valor decimal devido à precisão limitada dos cálculos de ponto flutuante.


