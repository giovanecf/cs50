#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    
    if(argc == 1)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    if(argc > 2)
    {
        printf("Too many arguments. Usage: ./substitution KEY\n");
        return 2;
    }

    if(strlen(argv[1]) != 26)
    {
        printf("KEY must contain 26 characters\n");
        return 3;
    }

    int TEXT_MAX_LEN = 1000;
    char text[TEXT_MAX_LEN];

    printf("Plaintext: ");
    fgets(text, TEXT_MAX_LEN, stdin);

    for(int i = 0, n = strlen(text); i < n; i++){
        
        int decimal_upper_letter = toupper(text[i]);
        
        if(decimal_upper_letter < 65 || decimal_upper_letter > 90) continue;

        int alphabetic_anchor = 'A';

        int letter_index_on_alphabetic = decimal_upper_letter - alphabetic_anchor;

        if(text[i] >= 97)
            text[i] = tolower(argv[1][letter_index_on_alphabetic]);
        else
            text[i] = toupper(argv[1][letter_index_on_alphabetic]);
    }

    printf("Cyphertext: %s\n", text);

    return 0;
}