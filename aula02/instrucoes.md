# Depuração de Código com gdb

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

