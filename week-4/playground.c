#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change_str(char *p);

int main(void)
{
    char s1 = 'B';
    char s2 = 'A';
    char *p1 = &s1;
    char *p2 = &s2;

    if(strcmp(p2, p1) > 0)
    {
        printf("G\n");
    }
    else
    {
        printf("L\n");
    }
}

void change_str(char *p){
    *p = 'B';
}

void copy_str(void){
    char *s1 = "Hi!";
    char *s2 = malloc(strlen(s1) + 1);

    for(int i = 0, n = strlen(s1); i <= n; i++)
    {
        // syntatic sugar for *(s1 + i) = *(s2 + 1)
        s1[i] = s2[i];
    }
}