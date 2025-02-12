#include <stdio.h>

#define LETTERS 26
#define VSTEP 1

int main() {
    int c, s, i, j;
    int nletters[LETTERS];
    double max_freq;
    double freq[LETTERS];

    for (i = 0; i < LETTERS; ++i)
        nletters[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z')
            nletters[c - 'A']++;
        if (c >= 'a' && c <= 'z')
            nletters[c - 'a']++;
    }

    s = 0;
    for (i = 0; i < LETTERS; ++i)
        s += nletters[i];

    if (s == 0) {
        printf("Info: No letters in input; returning without plotting histogram\n");
        return 0;
    }

    for (i = 0; i < LETTERS; ++i)
        freq[i] = (double)nletters[i] / (double)s * 100;

    max_freq = 0;
    for (i = 0; i < LETTERS; ++i)
        if (max_freq < freq[i])
            max_freq = freq[i];

    printf("\nHistogram of Letter Frequency:\n");
    for (i = (int)max_freq + (int)max_freq % VSTEP - 1; i > 0; i -= VSTEP) {
        printf("%3d|", i);
        for (j = 0; j < LETTERS; ++j) {
            if (freq[j] >= (double)i)
                putchar('x');
            else
                putchar(' ');
        }
        printf(" \n");
    }
    printf("   +--------------------------\n"
           "    A                        Z\n");

    return 0;
}

