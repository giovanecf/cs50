#include <stdio.h>

long get_long(char* text)
{
	long long_number;

	do
	{
		printf("%s", text);
		scanf("%ld", &long_number);
	}
	while(long_number <= 0 || long_number > 9999999999999999);
	
	return long_number;
}

int main(void)
{
	long card_number = get_long("Insira o número do seu cartão: ");

	printf("%ld", card_number);

	printf("\n");

	return 0;
}