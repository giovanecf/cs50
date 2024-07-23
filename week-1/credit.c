#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void citoa(long num, char snum[], int base);
void reverse(char str[], int length);
long get_long(char* text);

int main(void)
{
	//long card_number = get_long("Insira o número do seu cartão: ");
	//printf("Número do cartão de crédito: %ld\n", card_number);

	char number_as_str[16];

	int number;

	printf("Num: ");
	scanf("%d", &number);

	citoa(number, number_as_str, 10);

	printf("Str: %s", number_as_str);

	printf("\n");

	return 0;
}

long get_long(char* text)
{
	long long_number;
	char input[16];  // Assuming the input won't exceed 100 characters
    char *endptr;

	do
	{
		printf("%s", text);

		fgets(input, sizeof(input), stdin);  // Read user input

		// Remove trailing newline character, if any
		input[strcspn(input, "\n")] = '\0';

		// Check if the input is a valid number
		// strtol converts the initial part of the string to a long integer
		// The base (10 in this case) is assumed to be decimal
		long_number = strtol(input, &endptr, 10);

	}
	while(long_number <= 0 || long_number > 9999999999999999 || (isspace(*endptr) || *endptr != '\0'));
	
	return long_number;
}

// A utility function to reverse a string
void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

void citoa(long num, char snum[], int base)
{	
	if(num == 0)
	{
		snum[0] = '0';
		snum[1] = '\0';
		return;
	}

	int isNegative = 1;
	if(num > 0)
	{
		isNegative = 0;
		num = -num;
	}

	int i = 0;
	while(num != 0)
	{
		int rem = num % 10;
		snum[i] = (base > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	if(isNegative == 1)
	{
		snum[i++] = '-';
	}

	snum[i++] = '\0';

	reverse(snum, i);
}