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


