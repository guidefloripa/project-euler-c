/*

Created on 03/2014

Author: guidefloripa

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
 there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

*/

#include <stdio.h>

typedef unsigned long long uint64_t;

static void printL(uint64_t *L, int grid_size)
{
	int i;
	for (i=0; i<=grid_size; i++) {
		fprintf(stderr, "%llu ", L[i]);
	}
	fprintf(stderr, "\n");
}

static uint64_t getRoutes(int grid_size)
{
	uint64_t L[grid_size+1];
	uint64_t count = 0;
	int i,j;

	for (i=0; i<=grid_size; i++) {
		L[i] = 1;
	}

	for (i=1; i<=grid_size; i++) {
		for (j=1; j<=i; j++) {
			L[j] += L[j-1];
		}
		L[i] = 2 * L[i - 1];
		printL(L, i);
	}

	return L[grid_size];
}

int main(int argc, char** argv)
{
	fprintf(stderr, "[Problem 15] %llu\n", getRoutes(20));
	return 0;
}
