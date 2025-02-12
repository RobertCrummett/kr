#include <stdio.h>

int main() {
    int c, state;

    state = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ') {
            if (state == 0)
                putchar(' ');
            state = 1;
        } else {
            putchar(c);
            state = 0;
        }
}
