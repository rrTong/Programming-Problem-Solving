#include "Wall.h"

#include <stdio.h>

int main()
{
	Wall* wall;
	Wall llaw;

	wall->upper = true; 
	wall->lower = true;
	wall->left = true;
	wall->right = true;

	llaw.upper = true;
	llaw.lower = true;
	llaw.left = true;
	llaw.right = true;

	Wall_RemoveLowerWall(wall);

	//Wall_Print(llaw);

	return 0;
}
