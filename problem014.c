/*

Created on 03/2014

Author: guidefloripa

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/

#include <stdio.h>

typedef unsigned long long uint64_t;

static inline uint64_t nextCollatz(uint64_t value)
{
	return (value%2==0) ? value/2 : (3*value + 1);
}

static uint64_t getCollatzN(uint64_t value)
{
	uint64_t n = 1;
	while (value > 1) {
		value = nextCollatz(value);
		n++;
	}

	return n;
}


int main(int argc, char** argv)
{
	uint64_t value = 1;
	uint64_t maxCLen = 1;
	uint64_t maxCStart = 1;
	uint64_t n;

	while (value < 1000000) {
		n = getCollatzN(value);
		if (n > maxCLen) {
			maxCLen = n;
			maxCStart = value;
		}
		value++;
	}

	fprintf(stderr, "[Problem 14] %lld [length %lld]\n", maxCStart, maxCLen);
	return 0;
}

