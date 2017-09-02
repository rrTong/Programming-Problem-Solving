// Ryan Tong

#include <stdio.h>
#include <math.h>

int main()
{
	double jackAndBob = 0.0;
	double bobAndDanny = 0.0;
	double jackAndDanny = 0.0;

	double jbSec = 0.0;
	double bdSec = 0.0;
	double jdSec = 0.0;

	double allTogether = 0.0;

	double frontExtract = 0.0;
	double backExtract = 0.0;

	double finalHour = 0.0;
	double finalMin = 0.0;
	double finalSec = 0.0;

	printf("How long will it take Jack and Bob to do the job?  ");
	scanf("%lf", &jackAndBob);
	printf("How long will it take Bob and Danny to do the job?  ");
	scanf("%lf", &bobAndDanny);
	printf("How long will it take Jack and Danny to do the job?  ");
	scanf("%lf", &jackAndDanny);

	jbSec = jackAndBob * 3600;
	bdSec = bobAndDanny * 3600;
	jdSec = jackAndDanny * 3600;

	allTogether = (1 / ((1 / jbSec) + (1 / bdSec) + (1 / jdSec) )) * 2;

	backExtract = modf(allTogether, &frontExtract);

	if (1 - backExtract >= 0.5)
	{
		allTogether = floor(allTogether);
	}
	else
	{
		allTogether = ceil(allTogether);
	}

	finalSec = (int) allTogether;

	while (finalSec > 59)
	{
		if (finalSec > 59)
		{
			finalSec = finalSec - 60;
			finalMin++;
		}
		if (finalMin > 59)
		{
			finalMin = finalMin - 60;
			finalHour++;
		}
	}

	printf("It will take Jack, Bob and Danny %.0f hours, %.0f minutes, and %.0f seconds to do the job if they worked together\n\n", finalHour, finalMin, finalSec);

	return 0;
}
