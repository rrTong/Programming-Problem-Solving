// Ryan Tong

#include <stdio.h>
#include <math.h>

int main()
{
	double currentGrade = 0.0;
	double totalCurrentGrade = 0.0;
	double finalWorth = 0.0;
	double finalScore = 0.0;
	int result = 0;

	printf("What is your current grade?  ");
	scanf("%lf", &currentGrade);
	printf("How much is the final worth?  ");
	scanf("%lf", &finalWorth);

	totalCurrentGrade = ( ((100 - finalWorth)/100) * currentGrade);

	finalScore = ceil((90 - totalCurrentGrade) / (finalWorth/100)); 

	if (finalScore > 100)
	{
		finalScore = 100;
	}
	else if (finalScore < 0)
	{
		finalScore = 0;
	}

	result = (int) finalScore;

	printf("Your final exam score must be %.0lf%%\n\n", finalScore);

	return 0;
}