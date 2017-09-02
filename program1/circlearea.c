// Ryan Tong

#include <stdio.h>

int main()
{
	const double pi = 3.14;
	double circleRadius = 0.0;
	double circleArea = 0.0;

	printf("What is the radius of the circle in feet?  ");
	scanf("%lf", &circleRadius);

	circleArea = pi * circleRadius * circleRadius;

	printf("The area of the circle is %.2f square feet\n\n", circleArea);

	return 0;
}