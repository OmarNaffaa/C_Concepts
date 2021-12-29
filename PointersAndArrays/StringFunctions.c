/*
    C implementations of string functions

    Chapter 5 - Pointers and Arrrays in "The ANSI C Programming Language"
*/
#include <stdio.h>

#define STRING_BUFFER_SIZE 100

// strcopy: copy t to s
void strcopy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

// strcomp: return <0 if s<t, 0 if s==t, >0 if s>t
int strcomp(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

// test function
int main()
{
    // Testing "strcopy"
    printf("\n--------------------------------------\n");
    printf("Testing strcopy function");
    printf("\n--------------------------------------\n");
    char testStr[STRING_BUFFER_SIZE] = "Testing string copy function";
    char copiedStr[STRING_BUFFER_SIZE];
    strcopy(copiedStr, testStr);
    printf("Copied String:\n  %s\n", copiedStr);

    // Testing "strcomp"
    printf("\n--------------------------------------\n");
    printf("Testing strcomp function");
    printf("\n--------------------------------------\n");
    char strOne[] = "String 1";
    char strTwo[] = "String 2";
    char strThree[] = "String 1";
    printf("Expecting 0 - Value: %d\n", strcomp(strOne, strThree));
    printf("Expecting value less than 0 - Value: %d\n", strcomp(strOne, strTwo));

    // TODO

    // Exiting test function
    printf("\n");
}