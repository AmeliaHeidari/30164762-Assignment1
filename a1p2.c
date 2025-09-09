// Amelia Heidari - 30164762
// Tutorial 11
// Assignment 1

// finds primes between lower and upper using n processes, each child gets its own range and memory block

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <math.h>

#define MAX_PRIMES_PER_CHILD 1000 // this can be adjusted, just put it at 1000 for now

int is_primeIint num) { // checking if number is prime or not 
	if (num < 2) return 0;
	for (int i = 2; i <= sqrt(num); ++i)
		if (num % i == 0)
			return 0;
	return 1;
}

// sanity check, 3 arguments or it will bail out 

