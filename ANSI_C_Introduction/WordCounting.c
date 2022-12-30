/*
    Implementation of Exercise 1-12 in Chapter 1 of "The ANSI C Programming Language"

    Modifies program in book to print out each word on a new line in addition to
    tracking the number of characters, words, and lines
*/

#include <stdio.h>
#include <string.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

#define MAX_WORD_SIZE 1000

/* count lines, words, and characters in input */
int main()
{
    int c, nl, nw, nc, state, i;

    char currWord[MAX_WORD_SIZE];

    state = OUT;
    nl = nw = nc = i = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        currWord[i++] = c;

        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t') {
            printf("%s\n", currWord);
            memset(currWord, 0, sizeof(currWord)); // clear buffer
            i = 0;

            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("TOTAL: %d %d %d\n", nl, nw, nc);
}