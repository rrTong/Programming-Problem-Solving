#include "Maze.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Create a cell with fields i, j
// 
// typedef struct {
// 	unsigned int i, j;
// } Cell;
Cell Cell_Init(unsigned int i, unsigned int j) {
	Cell result;
	result.i = i;
	result.j = j;
	return result;
}

// Initialize a rows x cols maze with all walls up
// 
// typedef struct {
// 	unsigned int rows, cols;
// 	DisjointSet* cells;
// 	Walls** walls;
// } Maze;
Maze* Maze_Init(unsigned int rows, unsigned int cols) {
	Maze* result = malloc(sizeof(Maze));
	result->rows = rows;
	result->cols = cols;
	Maze_InitializeWalls(result);
	result->cells = DisjointSet_Init(rows * cols);
	return result;
}

// Allocates space for walls and initializes them so that
// each cell is completely surrounded by walls
void Maze_InitializeWalls(Maze* M) {
//	int mazeSize = (M->rows + 1) * (M-cols + 1);

//	for(int i = 0; i < mazeSize; ++i)
//		M->walls[i]->Wall_Init(); 

	// memory allocation
	M->walls = malloc((M->rows + 1) * sizeof(Wall*));
	if(M->walls == NULL)
	{
		printf("Low memory, exiting...\n\n");
		exit(0);
	}
	for(int i = 0; i < M->rows + 1; ++i)
	{
		M->walls[i] = malloc((M->cols + 1) * sizeof(Wall*));		
	}

	// initialize 
	for(int i = 0; i < M->rows + 1; ++i)
	{
		for(int j = 0; j < M->cols + 1; ++j)
		{
			M->walls[i][j] = Wall_Init();
		}
	}

	// cut off borders on edges
	for(int i = 0; i < M->rows + 1; ++i)
	{
		for(int j = 0; j < M->cols + 1; ++j)
		{
			if(i == 0)
			{
				Wall_RemoveUpperWall(&M->walls[i][j]);
			}		
			if(j == 0)
			{
				Wall_RemoveLeftWall(&M->walls[i][j]);
			}
			if(j == M->cols)
			{
				Wall_RemoveRightWall(&M->walls[i][j]);
			}
			if(i == M->rows)
			{
				Wall_RemoveLowerWall(&M->walls[i][j]);
			}
		}
	}
}

// Break wall between cells if they neighbor and there is no
// current path between each other. Returns true if it succeeds
// and false otherwise
void Maze_BreakWall(Maze* M, Cell C1, Cell C2) {
	printf("LUL : %d %d %d %d\n", C1.i, C1.j, C2.i, C2.j);

//	printf("%d\n", M->walls[0][0]);

//	M->cells->setRepresentative[] = (M->cols + 1) * M->rows + M->cols;

	if((abs(C2.i - C1.i) == 1 && C2.j == C1.j) || (C2.i == C1.i && abs(C2.j - C1.j) == 1)) 
	{
		printf("It works, you're adjacent\n"); // delete later

		int unionI = (C1.i * M->cols) + C1.j;
		int unionJ = (C2.i * M->cols) + C2.j;

		if(DisjointSet_Union(M->cells, unionI, unionJ))
		{
			printf("P1: It works, you're union\n"); // delete later

			int compareI = C2.i - C1.i;
			int compareJ = C2.j - C1.j;

			if(compareI == 1)
			{
				Wall_RemoveRightWall(&M->walls[C2.i][C2.j]);
				Wall_RemoveLeftWall(&M->walls[C2.i][C2.j+1]);
			}
			else if(compareI == -1)
			{
				Wall_RemoveRightWall(&M->walls[C1.i][C1.j]);
				Wall_RemoveLeftWall(&M->walls[C1.i][C1.j+1]);
			}
			else if(compareJ == 1)
			{
				Wall_RemoveUpperWall(&M->walls[C2.i+1][C2.j]);
				Wall_RemoveLowerWall(&M->walls[C2.i][C2.j]);
			}
			else if(compareJ == -1)
			{
				Wall_RemoveUpperWall(&M->walls[C1.i+1][C1.j]);
				Wall_RemoveLowerWall(&M->walls[C1.i][C1.j]);
			}
		}
		else
		{
			printf("P1: Cells already have a path between them. Try again\n");
		}
	}
	else
	{
		printf("Cells are not adjacent. Try again\n");
	}
}

// Returns true if not complete.
// Maze is complete if every pair of cells has a path between each other
bool Maze_IsIncomplete(const Maze* M) {
	if(DisjointSet_NumberOfSets(M->cells) != 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Print maze
void Maze_Print(const Maze* M) {
//	int mazeSize = (M->rows + 1) * (M-cols + 1);

	for(int i = 0; i < M->rows + 1; ++i)
	{
		for(int j = 0; j < M->cols + 1; ++j)
		{
			Wall_Print(M->walls[i][j]);
		}
		printf("\n");
	}
}

// Deallocate memory used for Maze
void Maze_Destroy(Maze* M) {
	for(int i = 0; i < M->rows + 1; ++i)
	{
		free(M->walls[i]);
	}
	free(M->walls);

	free(M->cells);

	free(M);
}