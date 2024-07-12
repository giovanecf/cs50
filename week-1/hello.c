#include <stdio.h>
#include <string.h>


int main(void){

    char name[30];

    printf("What's your name, cuz? ");
    int scan_result = scanf("%s", name);

    if(scan_result == 0)
    {
        printf("No value was assigned");
        return -1;
    } 
    else if(scan_result < 0)
    {
        printf("Read error encountered or end-of-file(EOF) reached before any assignment was made");
        return -1;
    }

    printf("It's a pleasure, %s \n", name);

    return 0;
}