# Instruções para a Aula 01

Nesta aula, vamos abordar os conceitos básicos de programação. Certifique-se de ter o ambiente de desenvolvimento configurado corretamente antes de começar.

## Pré-requisitos

- Conhecimento básico de lógica de programação
- Ambiente de desenvolvimento instalado (ex: Visual Studio Code)

## Atividades

1. **Estudo Teórico**: Leia os materiais disponibilizados na branch `aula01`.
2. **Prática**: Realize os exercícios propostos.
3. **Revisão**: Revise os conceitos aprendidos e tire suas dúvidas.

## Dicas

- Não hesite em consultar a documentação oficial das linguagens que está utilizando.
- Utilize o Git para versionar seu código e facilitar o acompanhamento das alterações.

### Criação do arquivo de instruções
###  Criação do Hello World em C.

Compilação:
```bash
cd aula01
gcc aula01.c -o main
```

Execução:
```bash
./main
```

### Questão 02

*Implemente um programa que leia dois números inteiros e imprima a soma deles.*

Implementação no arquivo `q02.c`:

```c
#include<stdio.h>

int main() {
    int num1, num2, soma;
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    soma = num1 + num2;
    printf("A soma e: %d\n", soma);
    return 0;
}
```

Compilação:
```bash
gcc q02.c -o soma
```
Execução:
```bash
./soma
```

Removendo mensagens de aviso para o programa. Esta maneira será a preferível para as próximas questões uma vez que torna mais facil a automação das avaliações e testes.

```c
#include<stdio.h>

int main() {
    int num1, num2, soma;
    // printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    // printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    soma = num1 + num2;
    // printf("A soma e: %d\n", soma);
    printf("%d\n", soma);
    return 0;
}
```

Além disso, será utilizado como padrão o uso do int main(int argc, char *argv[]) nas próximas questões, mesmo que os argumentos não sejam utilizados.

Exemplo prático para a q02.c:
```c
#include<stdio.h>//printf
#include<stdlib.h>//atoi
int main(int argc, char *argv[]) {
    int num1, num2, soma;
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    soma = num1 + num2;
    printf("%d", soma);
    return 0;
}
```

Observe que os resultados são os mesmos, mas agora o programa lê os números passados como argumentos na linha de comando. Exemplo:
```bash
./soma 3 5
8
```
Os valores de **argv[0]** é o nome do programa, argv[1] é o primeiro argumento (3) e **argv[2]** é o segundo argumento (5). Já o valor de argc é 3, pois inclui o nome do programa e os dois argumentos.

### Questão 03
*Desenvolva um programa que calcule a média de um vetor de 10 números inteiros*

Implementação no arquivo `q03.c`:

```c
#include<stdio.h>//printf
#include<stdlib.h>//atoi
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
```

O printf com o valor de **%.2f** formata a média para exibir duas casas decimais. Do mesmo modo que na questão anterior, o programa lê os números passados como argumentos na linha de comando. Exemplo:
```bash
./media 5 10 15 20 25 30 35 40
27.50
```

Observe que o valor de argc é 11, pois inclui o nome do programa e os 10 números inteiros. Dessa forma, o programa consegue identificar e processar os números corretamente, pois sabe que os argumentos começam a partir de argv[1] até argv[10].

Uma modificação interessante seria permitir que o usuário informe a quantidade de números que deseja calcular a média. Isso pode ser feito ajustando o código para ler o primeiro argumento como a quantidade de números e os seguintes como os valores a serem somados. Como esse exemplo modificado da questão 03:

```c
#include<stdio.h>//printf
#include<stdlib.h>//atoi
int main(int argc, char *argv[]) {
    int n, i, soma = 0;
    float media;
    n = atoi(argv[1]); // Lê a quantidade de números
    for(i = 0; i < n; i++) {
        soma += atoi(argv[i + 2]); // Lê os números a partir do segundo argumento
    }
    media = soma / (float)n; // Calcula a média
    printf("%.2f", media); // Imprime a média com duas casas decimais
    return 0;
}
```

Desta forma, o usuário pode especificar quantos números deseja calcular a média, tornando o programa mais flexível. Exemplo de execução:
```bash
./media 5 10 15 20 25
15.00
```

### Questão 04

*Crie um programa que encontre o maior elemento de um vetor de 10 números inteiros*

Implementação no arquivo `q04.c`:

```c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc != 11) {
        printf("Erro: Informe 10 números inteiros como argumentos.\n");
        return 1;
    }
    int numeros[10];
    for (int i = 0; i < 10; i++) {
        numeros[i] = atoi(argv[i + 1]);
    }
    int maior = numeros[0];
    for (int i = 1; i < 10; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }
    printf("%d", maior);
    return 0;
}
```

Observe que uma comparação é feita para garantir que exatamente 10 números sejam fornecidos como argumentos. O programa então encontra e imprime o maior número entre os fornecidos.