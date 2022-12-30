/*
    C implementations of string functions

    Chapter 5 - Pointers and Arrrays in "The ANSI C Programming Language"
*/
#include <stdio.h>

#define STRING_BUFFER_SIZE 100

/*
    Utility Functions
*/
// strcopy: copy t to s
void strcopy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

int strlen(char *s) /* added by RJH; source: K&R p99 */
{
  int n;

  for(n = 0; *s != '\0'; s++)
  {
    n++;
  }
  return n;
}

int strcmp(char *s, char *t) /* added by RJH; source: K&R p106 */
{
  for(;*s == *t; s++, t++)
    if(*s == '\0')
      return 0;
  return *s - *t;
}

/*
    End Utility Functions
*/

// Pointer implementation of "strcat" function
//   concatenate t to the end of s; s must be bug enough
void strconcat(char *s, char *t)
{
    while (*s) /* find the end of s */
        ++s;
    while (*s++ = *t++) /* copy t */
        ;
}

// Pointer implementation of "strend" function
//   returns 1 if the string t occurs at the end of the string s
//   returns 0 otherwise
int mystrend(char *s, char *t)
{
    int result, s_len, t_len;
    result = s_len = t_len = 0;

    /* get the lengths of the strings */
    s_len = strlen(s);
    t_len = strlen(t);

    /* check if the lengths mean that the string t could fit at the string s */
    if(t_len <= s_len) {
        /* advance the s pointer to where the string t would have to start in string s */
        s += s_len - t_len;

        /* and make the comparison using strcmp */
        if(!strcmp(s, t))
            result = 1;
    }

    return result;
}

// String reversal using pointers
void mystrrev(char *s)
{
    char *begin_ptr, *end_ptr;
    int len = strlen(s);

    begin_ptr = s;
    end_ptr = s;

    while (*end_ptr)
        ++end_ptr;
    --end_ptr; /* return one place prior to the null terminator */

    char tmp;
    while (end_ptr > begin_ptr) {
        tmp = *begin_ptr;
        *begin_ptr = *end_ptr;
        *end_ptr = tmp;

        ++begin_ptr;
        --end_ptr;
    }
}

// Test function
int main()
{
    // strcat test function
    char strOne[STRING_BUFFER_SIZE] = "This is my ";
    char strTwo[] = "test string";
    strconcat(strOne, strTwo);
    printf("Result:\n   %s", strOne);
    printf("\n");

    // strend test function
    char strendOne[] = "Main string";
    char strendTwo[] = "string";
    char strendThree[] = "str";
    char strendFour[] = "even bigger string";
    printf("Expected result: %d - Actual result: %d\n", 1, mystrend(strendOne, strendTwo));
    printf("Expected result: %d - Actual result: %d\n", 0, mystrend(strendOne, strendThree));
    printf("Expected result: %d - Actual result: %d\n", 0, mystrend(strendOne, strendFour));
    printf("\n");

    // strrev test function
    mystrrev(strOne);
    printf("Reversed String:\n   %s", strOne);
}
