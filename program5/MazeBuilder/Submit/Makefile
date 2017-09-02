CC=gcc
FLAGS=-Wall -Werror -g

all: MazeBuilder

Wall.o:	Wall.h Wall.c
	gcc -Wall -c Wall.c

Maze.o: Maze.h Maze.c
	gcc -Wall -c Maze.c

DisjointSetADT.o: DisjointSetADT.h DisjointSetADT.c
	gcc -Wall -c DisjointSetADT.c

MazeBuilder.o: MazeBuilder.c
	gcc -Wall -c MazeBuilder.c

MazeBuilder: MazeBuilder.c Wall.h Wall.o Maze.h Maze.o DisjointSetADT.h DisjointSetADT.o
	gcc -Wall MazeBuilder.c Wall.o Maze.o DisjointSetADT.o -o MazeBuilder

clean:
	rm *.o