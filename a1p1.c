// Amelia Heidari - 30164762
// Tutorial 11
// Assignment 1

// program creates 100 child processes using fork(). each child is assigned one row of a 100x1000 matrix to search for a hidden treasure. if a child finds the treasure, it exits with the column number as the exit code. the parent waits for all children and reports the row+column where the treasure was found :)


#include <studio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ROWS 100 
#define COLS 1000

int matrix[ROWS][COLS]; // matrix is going to be filled with 0s and one 1 which is the trasure

int main() {
	// read the matrix from standard input or file and the matrix should have exactly 100 rows and 1000 columns
	for (int i = 0; i < ROWS; ++i) 
		for (int j = 0; j < COLS; ++j)
			scanf("%d", &matrix[i][j]);
