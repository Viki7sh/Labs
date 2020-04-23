// Лаба 4 (4.2).c
#define _CRT_SECURE_NO_WARNINGS
#define MAXLINE  1000    /* максимальная длина строки */
#define MAXWORD  100     /* максимальная длина слова  */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>


/* reverse: обращает строку s */
char* reverse(char s[])
{
    char* p, * q;
    int c;

    p = q = s;
    while (*q)
        q++;
    for (q--; p < q; p++, q--)
        c = *p, * p = *q, * q = c;
    return s;
}

/* ищет в тексте слова палиндромы и числа палиндромы без переносов */
int main()
{
    FILE* ifp;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* reverse(char[]);
    char line[MAXLINE], word[MAXWORD], tmp[MAXWORD], * p;
    int nc;
    const char* ifname = "слова.txt";

    if ((ifp = fopen(ifname, "r")) == NULL)
        return 1;

    while ((p = fgets(line, MAXLINE, ifp)) != NULL) {
        if (p[0] == '\n' || (p[0] == '\r' && p[1] == '\n'))
            break;
        while (sscanf(p, "%s%n", word, &nc) == 1) {
            p += nc;
            strcpy(tmp, word);
            if (strcmp(word, reverse(tmp)) == 0 && strlen(word) > 1)
                printf ("%s ", word);
        }
    }
    fclose(ifp);
    return 0;
}