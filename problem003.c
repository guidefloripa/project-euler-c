/*

Created on 03/2014

Author: guidefloripa

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?

*/

#include <stdio.h>

typedef unsigned long long uint64_t;

static uint64_t sqrt_uint64_t(uint64_t value)
{
	uint64_t min = 0;
	uint64_t max = ((uint64_t)1) << 32;
	uint64_t sqt;
	uint64_t sq;

	while (1) {
		if (max <= 1 + min)
			return min;

		sqt = min + (max - min)/2;
		sq = sqt*sqt;

		if (sq == value) 
			return sqt;

		if (sq > value)
			max = sqt;
		else
			min = sqt;
	}
}

static int isPrime(uint64_t value)
{
	uint64_t max = sqrt_uint64_t(value)+1;
	for (int i=3; i<max; i+=2) {
		if (value%i==0) return 0;
	}

	return 1;
}

int main(int argc, char** argv)
{
	uint64_t value = 600851475143;

	uint64_t limit = 1+value/2;
	uint64_t max = (value%2==0) ? 2 : 1;
	uint64_t i = 3;

	while (i<limit) {
		if (value%i == 0 && isPrime((uint64_t)i)) {
			max = i;
			value /= i;
			if (value <= 1) break;
		}
		i+=2;
	}

	fprintf(stdout, "[Problem 03] %lld\n", max);
	return 0;
}
