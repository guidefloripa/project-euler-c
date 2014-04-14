/*

Created on 03/2014

Author: guidefloripa

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.

*/

#include <stdio.h>
#include <math.h>

typedef unsigned long long uint64_t;

static int isPrime(int value)
{
	int max = sqrt(value)+1;
	if (value%2==0) return 0;
	for (int i=3; i<max; i+=2) {
		if (value%i==0) return 0;
	}

	return 1;
}

int main(int argc, char** argv)
{
	int i;
	uint64_t sum = 2;
	int limit = 2000000;

	for(i=3; i<=limit; i+=2) {
		if (isPrime(i)) {
			sum += i;
		}
	}

	fprintf(stdout, "[Problem 10] %lld\n", sum);
	return 0;
}
