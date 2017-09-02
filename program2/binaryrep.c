// Ryan Tong

#include <stdio.h>
#include <ctype.h>

int main()
{
	char charInput;
	int result = 0000000;

	printf("Please enter a character: ");
	scanf("%c", &charInput);

	if (isalnum(charInput))
	{
		result = result + 1000000;
	}
	if (isupper(charInput))
	{
		result = result + 100000;
	}
	if (islower(charInput))
	{
		result = result + 10000;
	}
	if (charInput == 65 || charInput == 69 || charInput == 73 || charInput == 79 || charInput == 85 || charInput == 97 || charInput == 101 || charInput == 105 || charInput == 111 || charInput == 117)
	{
		result = result + 1000;
	}
	if (isdigit(charInput))
	{
		result = result + 100;
	}
	if (isxdigit(charInput))
	{
		result = result + 10;
	}
	if (ispunct(charInput))
	{
		result = result + 1;
	}

	if (result == 1)
	{
		printf("The properties of the character can be represented by 000000%d\n", result);
	}
	else
	{
	printf("The properties of the character can be represented by %d\n", result);
	}

	return 0;
}