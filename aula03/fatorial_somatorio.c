#include <stdio.h>
int somatorio_aux(int n, int acc) {
  if (n == 0)
    return acc;
  return somatorio_aux(n - 1, acc + n);
}
int somatorio(int n) { return somatorio_aux(n, 0); }
int fatorial_aux(int n, int acc) {
  if (n == 0)
    return acc;
  return fatorial_aux(n - 1, acc * n);
}
int fatorial(int n) { return fatorial_aux(n, 1); }
int main() {
  int n = 10; // Exemplo de valor para n
  printf("S(%d) = %d\n", n, somatorio(n));
  printf("F(%d) = %d\n", n, fatorial(n));
  return 0;
}
