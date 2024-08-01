#include <stdio.h>
#include <ctype.h>

int POINTS[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int get_points_by_word(char word[])
{

    int i = 0;
    int sum = 0;
    while(1 == 1)
    {
        if(word[i] == '\0') break;

        int current_letter_as_num = (int) toupper(word[i]);

        if(current_letter_as_num >= 65 && current_letter_as_num <= 90)
            sum += POINTS[current_letter_as_num - 65];
       
        i++;
    }

    return sum;
}

int main(void)
{
    char player_1_word[100];
    char player_2_word[100];

    printf("Player 1: ");
    scanf("%s", player_1_word);

    printf("Player 2: ");
    scanf("%s", player_2_word);

    int player_1_sum = get_points_by_word(player_1_word);
    int player_2_sum = get_points_by_word(player_2_word);

    if(player_1_sum > player_2_sum) printf("Player 1 Wins!! :-)\n");

    else if(player_1_sum < player_2_sum) printf("Player 2 Wins!! :->\n");
    
    else printf("We Got a Tie!! :-O \n");

    return 0;
}
