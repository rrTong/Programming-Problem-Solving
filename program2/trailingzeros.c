// Ryan Tong

#include <stdio.h>
#include <math.h>

int main()
{
	int userInput = 0;
	int trailingZeros = 0;

	printf("Please enter the number: ");
	scanf("%d", &userInput);

	trailingZeros = (userInput / 5) + (userInput / 25) + (userInput / 125) + (userInput / 625);

	printf("Factorial of %d has %d trailing zeros\n\n", userInput, trailingZeros);

	return 0;
}