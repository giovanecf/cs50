#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int TEXT_MAX_LEN = 1000;

    char text[TEXT_MAX_LEN];

    printf("Text: ");
    fgets(text, TEXT_MAX_LEN, stdin);

    printf("Entered:\n%s\n", text);

    int letters_counter = 0;
    int spaces_counter = 1;// At least one word
    int dots_counter = 0;
    int i = 0;
    while(1 == 1)
    {
        if(text[i] == '\0') break;
        
        if(text[i] == ' ') spaces_counter++;
        if(text[i] == '.' || text[i] == '!' || text[i] == '?') dots_counter++;
        
        int current_char_as_num = (int) toupper(text[i]);
        if(current_char_as_num >= 65 && current_char_as_num <= 90)
            letters_counter++;

        i++;
    }

    if(dots_counter == 0) dots_counter++; // At least one sentence

    printf("Letters: %d\n", letters_counter);
    printf("Words: %d\n", spaces_counter);
    printf("Sentences: %d\n", dots_counter);

    float L = letters_counter * 100 / spaces_counter;
    float S = dots_counter * 100 / spaces_counter;

    float grade_index = 0.0588 * L - 0.296 * S - 15.8;

    printf("Grade Index: %.2f \n", grade_index);

    if(grade_index < 1) printf("Before Grade 1\n");
    else if(grade_index > 16) printf("Grade 16+\n");
    else printf("Grade %.0f\n", grade_index);

    return 0;
}