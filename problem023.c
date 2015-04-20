/*
 
 Created on 04/2015
 
 Author: guidefloripa
 
 A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
 For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 
 A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 
 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
 By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
 However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 
 Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 
 */

#include <stdio.h>
#include <string.h>

#define LIMIT 28123

typedef unsigned long long uint64_t;

static int getDivisorsSum(int n)
{
	int i;
	int limit = (n/2)+1;
	int sum = 1;
	
	for (i=2; i<limit; i++) {
		if (n%i==0) sum += i;
	}
	
	return sum;
}

int main(int argc, char** argv)
{
	unsigned char abundant[LIMIT+1];
	unsigned char write_abund[LIMIT+1];
	int i, j, s;
	uint64_t sum = 0;
	
	memset(abundant, 0, sizeof(abundant));
	memset(write_abund, 0, sizeof(write_abund));
	
	for (i=1; i<=28123; i++) {
		if (getDivisorsSum(i)>i) {
			abundant[i] = 1;
		}
	}
	
	for (i=12; i<=LIMIT; i++) {
		if (abundant[i]==0) continue;
		for (j=i; j<=LIMIT; j++) {
			if (abundant[j]==0) continue;
			
			s = i + j;
			if (s > LIMIT) break;
			write_abund[s] = 1;
		}
	}
	
	for (i=1; i<=LIMIT; i++) {
		if (!write_abund[i]) {
			sum += i;
		}
	}
	
	fprintf(stderr, "[Problem 23] %llu\n", sum);
	
	return 0;
}