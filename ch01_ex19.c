#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[], int len);
int getline(char line[], int maxline);

int main() {
    int len;              
    char c, line[MAXLINE];   

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
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

void reverse(char s[], int len) {
    int i;
    char t;

    for (i = 0; i < len / 2; ++i) {
        t = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = t;
    } 
}
