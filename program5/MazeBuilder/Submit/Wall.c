// Ryan Tong

#include "Wall.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char WALL_CROSS[] = "\u254b";		// ╋

char WALL_NO_LOWER[] = "\u253b";	// ┻

char WALL_NO_LEFT[] = "\u2523";		// ┣

char WALL_NO_UPPER[] = "\u2533";	// ┳

char WALL_NO_RIGHT[] = "\u252b";	// ┫

char WALL_UPPER_LOWER[] = "\u2503";	// ┃

char WALL_UPPER_RIGHT[] = "\u2517";	// ┗

char WALL_UPPER_LEFT[] = "\u251b";	// ┛

char WALL_LOWER_RIGHT[] = "\u250f";	// ┏

char WALL_LOWER_LEFT[] = "\u2513";	// ┓

char WALL_LEFT_RIGHT[] = "\u2501";	// ━

char WALL_ONLY_LEFT[] = "\u2574"; 	// ╸

char WALL_ONLY_UPPER[] = "\u2575"; 	// ╹

char WALL_ONLY_RIGHT[] = "\u2576"; 	// ╺

char WALL_ONLY_LOWER[] = "\u2577"; 	// ╻

Wall Wall_Init() {
	Wall result;
	result.lower = result.upper = result.right = result.left = true;
	return result;
}

// Remove the lower wall
void Wall_RemoveLowerWall(Wall* wall) {
	wall->lower = false;
}

// Remove the upper wall of a cell
void Wall_RemoveUpperWall(Wall* wall) {
	wall->upper = false;
}

// Remove the left wall of a cell
void Wall_RemoveLeftWall(Wall* wall) {
	wall->left = false;
}

// Remove the right wall of a cell
void Wall_RemoveRightWall(Wall* wall) {
	wall->right = false;
}

// Prints the character defined by the wall
// Walls: ╋ ┻ ┣ ┳ ┫ ┃ ┗ ┛ ┏ ┓ ━
void Wall_Print(Wall wall) {
	if(wall.lower == false && wall.upper == true && wall.right == true && wall.left == true)
	{
		printf("%s", WALL_NO_LOWER);
	}

	else if(wall.lower == true && wall.upper == true && wall.right == true && wall.left == false)
	{
		printf("%s", WALL_NO_LEFT);
	}

	else if(wall.lower == true && wall.upper == false && wall.right == true && wall.left == true)
	{
		printf("%s", WALL_NO_UPPER);
	}

	else if(wall.lower == true && wall.upper == true && wall.right == false && wall.left == true)
	{
		printf("%s", WALL_NO_RIGHT);
	}

	else if(wall.lower == true && wall.upper == true && wall.right == false && wall.left == false)
	{
		printf("%s", WALL_UPPER_LOWER);	
	}

	else if(wall.lower == false && wall.upper == true && wall.right == true && wall.left == false)
	{
		printf("%s", WALL_UPPER_RIGHT);
	}

	else if(wall.lower == false && wall.upper == true && wall.right == false && wall.left == true)
	{
		printf("%s", WALL_UPPER_LEFT);
	}

	else if(wall.lower == true && wall.upper == false && wall.right == true && wall.left == false)
	{
		printf("%s", WALL_LOWER_RIGHT);	
	}

	else if(wall.lower == true && wall.upper == false && wall.right == false && wall.left == true)
	{
		printf("%s", WALL_LOWER_LEFT);	
	}

	else if(wall.lower == false && wall.upper == false && wall.right == true && wall.left == true)
	{
		printf("%s", WALL_LEFT_RIGHT);	
	}

	else if(wall.lower == true && wall.upper == false && wall.right == false && wall.left == false)
	{
		printf("%s", WALL_ONLY_LOWER);	
	}

	else if(wall.lower == false && wall.upper == false && wall.right == false && wall.left == true)
	{
		printf("%s", WALL_ONLY_LEFT);	
	}

	else if(wall.lower == false && wall.upper == true && wall.right == false && wall.left == false)
	{
		printf("%s", WALL_ONLY_UPPER);	
	}

	else if(wall.lower == false && wall.upper == false && wall.right == true && wall.left == false)
	{
		printf("%s", WALL_ONLY_RIGHT);	
	}

	else
	{
		printf("%s", WALL_CROSS);
	}
}

// Shows you how to use the Unicode wall characters
void Wall_ShowWallChars() {
	printf("WALL_CROSS:\t\t%s\n", WALL_CROSS);
	printf("WALL_NO_LOWER:\t\t%s\n", WALL_NO_LOWER);
	printf("WALL_NO_LEFT:\t\t%s\n", WALL_NO_LEFT);
	printf("WALL_NO_UPPER:\t\t%s\n", WALL_NO_UPPER);
	printf("WALL_NO_RIGHT:\t\t%s\n", WALL_NO_RIGHT);
	printf("WALL_UPPER_LOWER:\t\t%s\n", WALL_UPPER_LOWER);
	printf("WALL_UPPER_RIGHT:\t\t%s\n", WALL_UPPER_RIGHT);
	printf("WALL_UPPER_LEFT:\t\t%s\n", WALL_UPPER_LEFT);
	printf("WALL_LOWER_RIGHT:\t\t%s\n", WALL_LOWER_RIGHT);
	printf("WALL_LOWER_LEFT:\t\t%s\n", WALL_LOWER_LEFT);
	printf("WALL_LEFT_RIGHT:\t\t%s\n", WALL_LEFT_RIGHT);
	printf("WALL_ONLY_LOWER:\t\t%s\n", WALL_ONLY_LOWER);
	printf("WALL_ONLY_LEFT:\t\t%s\n", WALL_ONLY_LEFT);
	printf("WALL_ONLY_UPPER:\t\t%s\n", WALL_ONLY_UPPER);
	printf("WALL_ONLY_RIGHT:\t\t%s\n", WALL_ONLY_RIGHT);
}