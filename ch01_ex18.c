#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);

int main() {
    int len;              
    char c, line[MAXLINE];   

    while ((len = getline(line, MAXLINE)) > 0) {
        len--;
        for (; len >= 0; len--) {
            c = line[len];
            if (c == ' ' || c == '\t')
                line[len] = '\0';
            else
                break;
        }
        if (len > 0)
            printf("%s\n", line);
    }
    return 0;
}

int getline(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

