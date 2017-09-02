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
// 	char** walls;
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
	// TODO: complete this function
}

// Break wall between cells if they neighbor and there is no
// current path between each other. Returns true if it succeeds
// and false otherwise
void Maze_BreakWall(Maze* M, Cell C1, Cell C2) {
	// TODO: complete this function
}

// Returns true if not complete.
// Maze is complete if every pair of cells has a path between each other
bool Maze_IsIncomplete(const Maze* M) {
	// TODO: complete this function
}

// Print maze
void Maze_Print(const Maze* M) {
	// TODO: complete this function
}

// Deallocate memory used for Maze
void Maze_Destroy(Maze* M) {
	// TODO: complete this function
}