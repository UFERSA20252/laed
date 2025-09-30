#include <stdio.h>

void level0(){
    printf("Nível 0 Alcançado\n");
}

void test(int level) {
    if (level > 0)    {
        int prevLevel = level - 1;
        printf("Nível %d\n", level);
        test(prevLevel);
    } else {
        level0();
    }
}

int main() {
    test(5);
    return 0;
}