#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* citoa(long num, char* snum, int base);
void reverse(char str[], int length);
long get_long(char* text);

void check_credit_card_number(long cc_number)
{
	int base = 10;

	int cc_number_digits = 1;
	long cc_number_aux = cc_number;
	while(cc_number_aux != 0)
	{
		cc_number_aux = cc_number_aux / 10;
		cc_number_digits++;
	}

	printf("Digits: %d\n", cc_number_digits);

	if(cc_number < 11)
	{
		printf("INVALID\n");
	}

	int cc_numbers_arr[cc_number_digits];
	for(int i = cc_number_digits - 1; i >= 0; i--)
	{
		cc_numbers_arr[i] = cc_number % base;
		cc_number = cc_number / base;
	}

	int first_step_sum = 0;
	for(int i = 0; i < cc_number_digits; i++){
		if(i % 2 == 0)
		{
			int current_product = cc_numbers_arr[i] * 2;
			if(current_product > 9)
			{
				while(current_product != 0)
				{
					first_step_sum = first_step_sum + (current_product % base);
					current_product = current_product / base;
				}
			}
			else 
			{
				first_step_sum = first_step_sum + current_product;
			}
		}
	}

	printf("First Step Sum: %d\n", first_step_sum);

	int second_step_sum = first_step_sum;
	for(int i = 0; i < cc_number_digits; i++){
		if(i % 2 != 0)
		{
			second_step_sum = second_step_sum + cc_numbers_arr[i];
		}
	}

	printf("Second Step Sum: %d\n", first_step_sum);


	//4003600000000014
}

int main(void)
{
	long card_number = get_long("Insira o número do seu cartão: ");

	// char card_number_as_str[16];
	// citoa(card_number, card_number_as_str, 10);

	// printf("Cartão informado: %s\n", card_number_as_str);

	// long total = 0;
	// for(int i = 0; i < strlen(card_number_as_str); i++){
	// 	if(i % 2 == 0)
	// 	{
	// 		total = total + card_number_as_str[i] * 2;
	// 	}
	// }

	check_credit_card_number(card_number);

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
	while(long_number < 0 || long_number > 9999999999999999 || (isspace(*endptr) || *endptr != '\0'));
	
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

// A utility function to reverse a string
void reverse_int(int str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end) {
        int temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

char* citoa(long num, char* str, int base)
{	
	if(num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return str;
	}

	int isNegative = 0;
	if(num < 0 && base == 10)
	{
		isNegative = 1;
		num = -num;
	}

	int i = 0;
	while(num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	if(isNegative == 1)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	reverse(str, i);

	return str;
}