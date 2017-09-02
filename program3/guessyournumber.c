// Ryan Tong

#include <stdio.h>
#include <ctype.h>

int main()
{
	int userInt = 0;
	char userInput = 'a';

	int lowerBound = 1;
	int upperBound = 2;
	int halfBound = 1;
	int guessCount = 0;
	int findingAnswer = 1;

	printf("Enter n: ");
	if (scanf("%d", &userInt) != 1)
	{
		printf("Error: invalid input.\n\n");
		exit(0);
	}

	if(userInt < 1)
	{
		printf("Error: n must be positive.\n\n");
		return 0;
	}
	else if(userInt == 1)
	{
		printf("Is your number 1? \n");
		printf("Error: invalid input.\n\n");
		return 0;
	}

/*	
	else if(userInt == '!')
	{
		printf("Error: invalid input.\n\n");
		return 0;
	}
*/
/*
	else if(isalpha(userInt))
	{
		printf("Error: invalid input.\n\n");
		return 0;
	}
*/

	upperBound = userInt; //setting upperBound to n
	halfBound = (upperBound + lowerBound) / 2;

	while(findingAnswer != 0)
	{
		if(lowerBound == upperBound)	// check if equal
		{
			if(guessCount == 1)
			{
				printf("Your number must be %d. I used %d guess.\n\n", upperBound, guessCount);		
			}
			else
			{
				printf("Your number must be %d. I used %d guesses.\n\n", upperBound, guessCount);
			}
			return 0;
		}

		printf("Is your number %d? ", halfBound);
		scanf(" %c", &userInput);

		if(userInput == 'l' || userInput == 'L')
		{
			lowerBound = halfBound + 1;

			halfBound = (upperBound + lowerBound) / 2;

			if(lowerBound < 1 || lowerBound > userInt || upperBound < lowerBound)
			{
				printf("Error: that's not possible.\n\n");
				return 0;
			}
		}
		else if(userInput == 's' || userInput == 'S')
		{
			upperBound = halfBound - 1;

			halfBound = (upperBound + lowerBound) / 2;

			if(upperBound < 1 || upperBound > userInt || upperBound < lowerBound)
			{
				printf("Error: that's not possible.\n\n");
				return 0;				
			}
		}
		else if(userInput == 'e' || userInput == 'E')
		{
			findingAnswer = 0;
		}
		else
		{
			printf("Error: invalid input.\n\n");
			return 0;
		}
		++guessCount;
	}
	if(guessCount == 1)
	{
		printf("Your number must be %d. I used %d guess.\n\n", halfBound, guessCount);		
	}
	else
	{
		printf("Your number must be %d. I used %d guesses.\n\n", halfBound, guessCount);
	}
	return 0;
}