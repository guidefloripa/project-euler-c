/*

Created on 03/2014

Author: guidefloripa

A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include <stdio.h>

static int isPalindrome(int value)
{
	char buffer[64];
	const char *c1, *c2;
	int n;
	n = snprintf(buffer, sizeof(buffer), "%d", value);
	c1 = &buffer[0];
	c2 = &buffer[n-1];
	while (c1<=c2) {
		if (c1[0] != c2[0]) return 0;
		c1++;
		c2--;
	}
	return 1;
}

int main()
{
	int i,j;
	int max_palindrome = 0;
	int max_i = 0;
	int max_j = 0;

	for (i=999; i>99; i--) {
		for (j=999; j>99; j--) {
			if ((i*j) <= max_palindrome) break;
			if (isPalindrome(i*j)) {
				max_palindrome = i*j;
				max_i = i;
				max_j = j;
				break;
			}
		}
	}

	fprintf(stdout, "[Problem 04] %d (%d * %d)\n", max_palindrome, max_i, max_j);

	return 0;
}
