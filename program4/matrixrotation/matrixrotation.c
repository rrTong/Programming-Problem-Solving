// Ryan Tong

#include <stdio.h> 
#include <stdlib.h>

#define MAX 10

void display(int matrix[][MAX], int size);

int main() {
	int n, degree;
	int matrix[MAX][MAX];
	int result[MAX][MAX];
	int nextResult[MAX][MAX];
	int lastResult[MAX][MAX];

	printf("Enter the size of the matrix: ");			// ENTER SIZE OF MATRIX
	if(scanf("%d", &n) != 1 || n < 0)
	{
		printf("Invalid input.\n\n");
		exit(0);
	}

	for(int i = 0; i < n; i++) //row					//ENTER ROWS OF MATRIX
	{
		printf("Enter the row %d of the matrix: ", i);
		for(int j = 0; j < n; j++) // col
		{
			if(scanf("%d", &matrix[i][j]) != 1)
			{
				printf("Invalid input.\n\n");
				exit(0);
			}
		}
	}

	printf("Enter the degree: ");						// ENTER DEGREE
	scanf("%d", &degree);
	if( degree != 90 && degree != 180 && degree != 270)
	{
		printf("Invalid input.\n\n");
		exit(0);
	}
	
    printf("Display the matrix: \n");
    display(matrix, n);

    if(degree == 90)
    {
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < n; j++)
    		{
    			result[i][j] = matrix[n-j-1][i];
    		}
    	}
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < n; j++)
    		{
    			nextResult[i][j] = result[n-j-1][i];
    		}
    	}
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < n; j++)
    		{
    			lastResult[i][j] = nextResult[n-j-1][i];
    		}
    	}
    	for(int a = 0; a < n; a++)
    	{
    		for(int b = 0; b < n; b++)
    		{
    			result[a][b] = lastResult[a][b];
    		}
    	}
    }
    else if(degree == 180)
    {
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < n; j++)
    		{
    			result[i][j] = matrix[n-j-1][i];
    		}
    	}
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < n; j++)
    		{
    			nextResult[i][j] = result[n-j-1][i];
    		}
    	}
    	for(int a = 0; a < n; a++)
    	{
    		for(int b = 0; b < n; b++)
    		{
    			result[a][b] = nextResult[a][b];
    		}
    	}
    }
    else if(degree == 270)
    {
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < n; j++)
    		{
    			result[i][j] = matrix[n-j-1][i];
    		}
    	}
    }

    printf("Rotate counterclockwise the matrix by %d degree: \n", degree);
    display(result, n);

	return 0;
}

void display(int matrix[][MAX], int size){
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) 
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}
}