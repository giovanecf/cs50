#include <stdio.h>

int main(void)
{
    long n = 0;
    
    while(n < 1000000000)
        n++;

    printf("%ld\n", n);

    return 0;
}