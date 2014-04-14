/*

Created on 03/2014

Author: guidefloripa

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?

*/

#include <stdio.h>
#include <math.h>

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
	int next_prime = 1;

	for(i=2; i<=10001; i++) {
		next_prime += 2;
		while (!isPrime(next_prime)) {
			next_prime += 2;
		}
	}

	fprintf(stdout, "[Problem 07] %d\n", next_prime);
	return 0;
}
