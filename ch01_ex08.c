#include <stdio.h>

int main() {
    int c, b;

    b = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n' || c == '\t' || c == ' ')
            ++b;
    printf("%d\n", b);
}

