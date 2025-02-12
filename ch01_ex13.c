#include <stdio.h>

#define MAX_LEN 10

int main() {
    int c, i, j, nletter, max_words, big_word;
    int nwords[MAX_LEN];

    for (i = 0; i < MAX_LEN; ++i)
        nwords[i] = 0;

    nletter = 0;
    while ((c = getchar()) != EOF)
        if (c >= 'A' && c <= 'z')
            nletter += 1;
        else {
            if (nletter >= MAX_LEN) {
                fprintf(stderr, "Warning: The word was too big!\n");
                return 1;
            }
            nwords[nletter] += 1;
            nletter = 0;
        }

    max_words = 0;
    for (i = 1; i < MAX_LEN; ++i)
        if (max_words < nwords[i])
            max_words = nwords[i];

    if (max_words == 0) {
        printf("Info: No words in the input! Not printing histogram\n");
        return 0;
    }

    big_word = 1;
    for (i = 1; i < MAX_LEN; ++i) 
        if (nwords[i] > 0)
            big_word = i;

    printf("\nHistogram of Word Counts:\n%2d|\n\n", max_words+1);
    for (i = max_words; i > 0; --i) {
        printf("%2d|", i);
        for (j = 1; j <= big_word; ++j) {
            putchar(' ');
            if (nwords[j] >= i)
                putchar('x');
            else
                putchar(' ');
        }
        printf(" \n");
    }
    printf("  +");
    for (j = 1; j <= big_word; ++j)
        printf("--");
    printf("-\n   ");
    for (j = 1; j <= big_word; ++j)
        printf(" %d", j);
    putchar('\n');

    return 0;
}
