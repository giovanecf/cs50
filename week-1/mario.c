#include <stdio.h>
#include <string.h>

void write_bricks(int num)
{
	int bricks;

	for(bricks = 0; bricks < num; bricks++)
	{
		printf("#");
	}
}

void write_spaces(int num)
{
	int spaces;

	for(spaces = 0; spaces < num; spaces++)
	{
		printf(" ");
	}

}

int main(void)
{

	int lines, i, spaces, bricks;

	printf("How many brick lines (1 to 8)? ");
	int scan_result = scanf("%d", &lines);

	if(scan_result > 0){
		if(lines <= 0 || lines > 8)
		{
			printf("Not what I'm looking for. Try again....\n");
			return -1;
		}
	} else {
		printf("Error on reading... Try again....\n");
		return -1;
	}

	


	printf("\n");

	for(i = 1; i <= lines; i++)
	{

		int spaces = lines - i;

		write_spaces(spaces);

		write_bricks(i);

		printf("  ");

		write_bricks(i);

		printf("\n");
	}

	return 0;

}