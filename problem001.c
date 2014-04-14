/*

Created on 03/2014

Author: guidefloripa

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

*/

#include <stdio.h>

int main(int argc, char** argv)
{
	int sum = 0;
	int limit = 1000;

	for (int i=1; i<limit; i++) {
		if (i%3==0 || i%5==0) {
			sum += i;
		}
	}

	fprintf(stdout, "[Problem 01] %d\n", sum);

	return 0;
}