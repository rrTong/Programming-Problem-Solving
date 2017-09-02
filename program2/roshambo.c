// Ryan Tong

#include <stdio.h>
#include <stdlib.h> // for rand()
#include <time.h> // for time_t

int main()
{
	char userInput;
	int compInput = 0;

	printf("Rock, paper, or scissors? ");
	scanf("%c", &userInput);

	srand((int) time(0));

	if(userInput == 'r')
	{
		compInput = rand() % 3;
		if(compInput == 0)
		{
			printf("I rolled rock. We tie!\n\n");
		}
		else if(compInput == 1)
		{
			printf("I rolled paper. You lose!\n\n");
		}
		else if(compInput == 2)
		{
			printf("I rolled scissors. You win!\n\n");
		}
		else
		{
			printf("I rolled an error. You what?\n\n");
		}
	}
	else if(userInput == 'p')
	{
		compInput = rand() % 3;
		if(compInput == 0)
		{
			printf("I rolled rock. You win!\n\n");
		}
		else if(compInput == 1)
		{
			printf("I rolled paper. We tie!\n\n");
		}
		else if(compInput == 2)
		{
			printf("I rolled scissors. You lose!\n\n");
		}
		else
		{
			printf("I rolled an error. You what?\n\n");
		}	
	}
	else if(userInput == 's')
	{
		compInput == rand() % 3;
		if(compInput == 0)
		{
			printf("I rolled rock. You lose!\n\n");
		}
		else if(compInput == 1)
		{
			printf("I rolled paper. You win!\n\n");
		}
		else if(compInput == 2)
		{
			printf("I rolled scissors. We tie!\n\n");
		}
		else
		{
			printf("I rolled an error. You what?\n\n");
		}
	}
	else
	{
		printf("Error: you did not enter \'r\', \'p\', or \'s\'!\n\n");
	}

	return 0;
}