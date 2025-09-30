# Depuração de Código com gdb (aula02)

Obs.: Para executar os exemplos, é necessário estar na pasta `aula02`.

```bash
cd aula02
```

## Análise da Estrutura de Dados Implícita: Depuração de Código.

Nesta aula são apresentadas os principais comandos do depurador gdb, que é uma ferramenta essencial para a análise e depuração de programas em C. O gdb permite que os desenvolvedores inspecionem o estado do programa em execução, identifiquem erros e compreendam o fluxo de execução.

### Comandos Básicos do gdb
- `gdb <programa>`: Inicia o gdb com o programa especificado.
- `run` ou `r`: Inicia a execução do programa. (Semelhante a executar `./programa` no terminal).
- `break <linha>` ou `b <linha>`: Define um ponto de interrupção na linha especificada.
- `next` ou `n`: Executa a próxima linha de código, pulando chamadas de função.
- `step` ou `s`: Executa a próxima linha de código, entrando em chamadas de função.
- `continue` ou `c`: Continua a execução do programa até o próximo ponto de interrupção.


Os comandos acima são essenciais para navegar e controlar a execução do programa durante a depuração. Eles permitem que você inspecione o estado do programa em pontos específicos, facilitando a identificação de erros e a compreensão do fluxo de execução.

### Inspeção de Variáveis
- `print <variável>` ou `p <variável>`: Exibe o valor da variável especificada.
- `info locals`: Exibe todas as variáveis locais no escopo atual.
- `info args`: Exibe os argumentos da função atual.

## Exemplo Prático
Considere o seguinte código em C (programa.c) que contém um erro de divisão por zero:
```c
#include <stdio.h>
int main() {
    int a = 5;
    int b = 0;
    int c = a / b; // Erro: divisão por zero
    printf("Resultado: %d\n", c);
    return 0;
}
```
Para depurar este código com **gdb**, siga os passos abaixo:
1. Compile o código com a opção `-g` para incluir informações de depuração:
 ```bash
   gcc programa.c -o programa -g
   ```
2. Inicie o gdb com o programa compilado:
```bash
gdb programa
```

Após essa etapa, você estará no prompt do gdb, onde poderá usar os comandos mencionados anteriormente para depurar o programa.

3. Defina um ponto de interrupção na linha onde ocorre a divisão:

```bash
(gdb) break 6
```
4. Inicie a execução do programa:
```bash
(gdb) run
```

5. Quando o programa atingir o ponto de interrupção, inspecione o valor das variáveis:
```bash
(gdb) print a
(gdb) print b
```
6. Continue a execução para observar o erro:
```bash
(gdb) continue
``` 

Ao seguir esses passos, você poderá identificar o erro de divisão por zero e entender o fluxo de execução do programa. O gdb é uma ferramenta poderosa que, quando utilizada corretamente, pode facilitar significativamente o processo de depuração e análise de código em C.

Exemplo de saída ao tentar continuar a execução:

> Program received signal SIGFPE, Arithmetic exception.0x0000555555555167 in main () at programa.c:5

> 5           int c = a / b; // Erro: divisão por zero

## Exemplo com passagem de parâmetros
Considere o seguinte código em C (programa2.c) que contém um erro de acesso a memória inválida:
```c
#include <stdio.h>
#include <stdlib.h>
void func(int a, int b) {
    int c = a / b; // Erro: divisão por zero
    printf("Resultado: %d\n", c);
}
int main(int argc, char *argv[]) {
    func(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
```
Para depurar este código com **gdb**, siga os passos abaixo:
1. Compile o código com a opção `-g` para incluir informações de depuração:
```bash
gcc programa2.c -o programa2 -g
```
2. Inicie o gdb com o programa compilado:
```bash
gdb programa2
```
Após essa etapa, você estará no prompt do gdb, onde poderá usar os comandos mencionados anteriormente para depurar o programa.
3. Defina um ponto de interrupção na linha onde ocorre a divisão:
```bash
(gdb) break 5
```
4. Inicie a execução do programa:
```bash
(gdb) run 5 0
```
5. Quando o programa atingir o ponto de interrupção, inspecione o valor das variáveis:
```bash
(gdb) print a
(gdb) print b
```
6. Continue a execução para observar o erro:
```bash
(gdb) continue
```
### Inspeção da pilha de execução

#### Comandos para Inspeção da Pilha de Execução
- `backtrace` ou `bt`: Exibe a pilha de chamadas (call stack) atual.
- `frame <n>`: Seleciona o quadro de pilha (stack frame) número n.
- `info frame`: Exibe informações sobre o quadro de pilha atual.

### Exemplo: Fibonacci com gdb

Considere o seguinte código em C (fibonacci.c) que calcula o n-ésimo número de Fibonacci de forma recursiva:
```c
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
```
Para depurar este código com **gdb**, siga os passos abaixo:
1. Compile o código com a opção `-g` para incluir informações de depuração:
```bash
gcc fibonacci.c -o fibonacci -g
```
2. Inicie o gdb com o programa compilado:
```bash
gdb fibonacci
```
Após essa etapa, você estará no prompt do gdb, onde poderá usar os comandos mencionados anteriormente para depurar o programa.
3. Defina o ponto de interrupção na função `fibonacci`:
```bash
(gdb) break fibonacci
```
4. Inicie a execução do programa com um argumento para `n`:
```bash
(gdb) run 5
```
5. Quando o programa atingir o ponto de interrupção, inspecione a pilha de chamadas:
```bash
(gdb) backtrace
```

Observe que a pilha de chamadas mostra todas as chamadas recursivas para a função `fibonacci`. Você pode navegar pelos quadros da pilha usando o comando `frame <n>` e inspecionar os valores dos parâmetros `n` em cada chamada.

No exemplo acima algo como isso logo abaixo deve ser exibido:

```gdb
(gdb) backtrace
#0  fibonacci (n=5) at fibonacci.c:5
#1  0x0000555555555261 in main (argc=2,argv=0x7fffffffd4c8) at fibonacci.c:19
```

Isso nos mostra que a função `fibonacci` foi chamada com o valor `n=5` e que essa chamada foi feita a partir da função `main`.

Agora você pode continuar a execução do programa ou inspecionar mais detalhes conforme necessário.
```bash
(gdb) continue
(gdb) backtrace
```

O resultado será algo como:
```gdb
#0  fibonacci (n=4) at fibonacci.c:5
#1  0x00005555555551d1 in fibonacci (n=5) at fibonacci.c:8
#2  0x0000555555555261 in main (argc=2, argv=0x7fffffffd4c8) at fibonacci.c:19
```

O que indica que o gdb está mostrando a pilha de chamadas, permitindo que você veja como o programa chegou ao ponto atual de execução. Dessa forma, você pode analisar o fluxo de execução e os valores das variáveis em cada nível da pilha. No nível mais alto, você vê a chamada original para `fibonacci(5)` feita a partir de `main`, e abaixo dela, as chamadas recursivas subsequentes.

Ou seja, o **#0** é a chamada mais recente (fibonacci(4)), o **#1** é a chamada anterior (fibonacci(5)), e o **#2** é a chamada original feita a partir de `main`.

