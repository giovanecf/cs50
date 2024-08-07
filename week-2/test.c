#include <stdio.h>

int get_str_size(char str[])
{
    int count = 0;
    int current_char = str[count++];

    while(current_char != 0)
    {
        current_char = str[count++];
    }

    return count - 1;
}

void main(void)
{
    char s[] = "Geovani";

    long i = 0;
    while(1 == 1){
        printf("%i -> %i %c \n", i, s[i], s[i]);
        i++;
    }
}