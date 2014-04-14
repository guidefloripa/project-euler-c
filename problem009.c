/*

Created on 03/2014

Author: guidefloripa

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <stdio.h>
#include <math.h>

static int isPythagoreanTriplet(int a, int b, int c)
{
	return (a*a + b*b) == c*c ? 1 : 0;
}

int main(int argc, char** argv)
{
	int a;
	int b;
	int c;
	int sum = 1000;

	for (a=10; a<500; a++) {
		for (b=10; b<500; b++) {
			c = sqrt(a*a + b*b);
			if ((a+b+c)==sum && isPythagoreanTriplet(a,b,c)) {
				fprintf(stdout, "[Problem 09] %d [a=%d; b=%d; c=%d]\n", a*b*c, a, b, c);
				return 0;
			}
		}
	}

	fprintf(stdout, "[Problem 09] solution not found!\n");
	return 0;
}
