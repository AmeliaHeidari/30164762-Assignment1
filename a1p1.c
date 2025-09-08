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

	pid_t pids[ROWS]; // storing all the kids PID's here 
	int status;
	int treasure_row = -1, treasure_col = -1; // this is where the treasure is found

	for (int i = 0; i < ROWS; ++i) { // creating child processes (100) for the matrix
		pid_t pid = fork();
		if (pid == 0) {
			printf("Child %d (PID %d): Searching row %d\n", i, getpid(), i);
			for (int j = 0; j < COLS; ++j) { 
				if (matrix[i][j] == 1) {
					// if the treasure is found then it exits 
					exit(j); // column number 
				}
			}
			exit(255); // if nothing was found
			} else if (pid > 0) {
				pids[i] = pid; // storing PID for later
			} else {
				perror("fork failed"); // if it fails
				exit(1);
			}
	}
