#include <stdio.h>

void draw(int n);
void draw_r(int n);

int main(void)
{
    int height = 0;

    printf("Height: ");
    scanf("%i", &height);

    draw_r(height);

    return 0;
}

void draw(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

void draw_r(int n)
{

    if(n <= 0)
        return;

    draw_r(n - 1);

    for(int i = 0; i < n; i++)
    {
        printf("##");
    }

    printf("\n");
}