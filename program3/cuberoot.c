// Ryan Tong

#include <stdio.h>
#include <math.h>

int main()
{
	int x0 = 0;
	int userGuess = 0;
	int userSteps = 0;

	double xN = 0.0;
	double xK = 0.0;
	double xM = 0.0;

	printf("Enter the integer you wish to find the cube root of: ");
	scanf("%d", &x0);
	printf("Enter your first guess and number of steps: ");
	scanf("%d %d", &userGuess, &userSteps);

	xN = (double) x0;
	xK = userGuess;

	for(int i = 0; i < userSteps; i++)
	{
		if(i != 0)
		{
			xK = xM;
		}
		xM = ( (2.0 * xK) + ( xN / pow(xK, 2.0)) ) * (1.0 / 3.0);
	}

	printf("The cube root of %d is approximately %.5lf\n\n", x0, xM);

	return 0;
}