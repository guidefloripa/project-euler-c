/*
 
 Created on 03/2014
 
 Author: guidefloripa
 
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
 
 */

#include <stdio.h>
#include <string.h>

#define SUM_LEN 10000

static int getDivisorsSum(int n)
{
	int i;
	int limit = (n/2)+1;
	int sum = 1;

	for(i=2; i<limit; i++) {
		if (n%i==0) sum += i;
	}

	return sum;
}

int main(int argc, char** argv)
{
	int sums[SUM_LEN];
	int sum = 0;
	int i, j;

	memset(sums, 0, sizeof(sums));

	for (i=1; i<SUM_LEN; i++) {
		sums[i] = getDivisorsSum(i);
	}

	for (i=1; i<SUM_LEN; i++) {
		if (sums[i] <= 1) continue;
		for (j=i+1; j<SUM_LEN; j++) {
			if (sums[i] == j && i == sums[j]) {
				sum += i + j;
			}
		}
	}

	fprintf(stderr, "[Problem 21] %d", sum);
	
	return 0;
}
