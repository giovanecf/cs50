#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* citoa(long num, char* snum, int base);
void check_credit_card_number(long cc_number);
int first_step_verification(int digits_arr[], int size, int base);
long get_long(char* text);
int get_number_digits(long number);
void reverse(char str[], int length);
void reverse_int(int str[], int length);
int second_step_verification(int previous_sum, int digits_arr[], int size);
void split_long_number_as_array(long number, int* arr, int size, int base);

int main(void)
{
	long card_number = get_long("Insira o número do seu cartão: ");

	check_credit_card_number(card_number);

	printf("\n");

	return 0;
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

long get_long(char* text)
{
	long long_number;
	char input[20];  // Assuming the input won't exceed 100 characters
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
	while(long_number < 0 || (isspace(*endptr) || *endptr != '\0'));
	
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

int get_number_digits(long number)
{
	// Count how much digits the credit card number has
	int number_digits = 0;

	while(number != 0)
	{
		number = number / 10;
		number_digits++;
	}

	return number_digits;
}

void split_long_number_as_array(long number, int* arr, int size, int base)
{
	for(int i = size - 1; i > -1; i--)
	{
		arr[i] = number % base;
		number = number / base;
	}
}

int first_step_verification(int digits_arr[], int size, int base)
{
	int sum = 0;
	for(int i = 0; i < size; i++){
		if(i % 2 == 0)
		{
			int current_product = digits_arr[i] * 2;

			if(current_product > 9)
			{
				while(current_product != 0)
				{

					sum = sum + (current_product % base);
					current_product = current_product / base;
				}
			}
			else 
			{
				sum = sum + current_product;
			}
		}
	}

	return sum;
}

int second_step_verification(int previous_sum, int digits_arr[], int size)
{
	int sum = 0;
	for(int i = 0; i < size; i++){
		if(i % 2 != 0)
		{
			sum = sum + digits_arr[i];
		}
	}

	return sum + previous_sum;
}

void check_credit_card_number(long cc_number)
{
	int base = 10;

	int cc_number_digits = get_number_digits(cc_number);

	// Check for acceptable number of digits
	if(cc_number < 9)
	{
		printf("INVALID\n");
		return;
	}

	// Create the digits array
	int cc_numbers_arr[cc_number_digits];
	split_long_number_as_array(cc_number, cc_numbers_arr, cc_number_digits, base);

	int first_step_sum = first_step_verification(cc_numbers_arr, cc_number_digits, base);
	
	int second_step_sum = second_step_verification(first_step_sum, cc_numbers_arr, cc_number_digits);

	if(second_step_sum % 10 != 0)
	{
		printf("INVALID\n");
		return;
	}

	int first_two_digits = cc_numbers_arr[0] * 10 + cc_numbers_arr[1];
	if(first_two_digits == 34 || first_two_digits == 37)
	{
		printf("AMEX\n");
	}
	else if(first_two_digits >= 51 && first_two_digits <= 55)
	{
		printf("MASTERCARD\n");
	}
	else if(first_two_digits >= 40 && first_two_digits < 50)
	{
		printf("VISA\n");
	}

	//4003600000000014
	//4111111111111111
}
