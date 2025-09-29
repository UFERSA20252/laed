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