/*

Created on 03/2014

Author: guidefloripa

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

#include <stdio.h>

int main()
{
	int i = 1;
	int j;
	int max_div;
	bool fail_div;

	while (1) {
		fail_div = false;
		for (j=2; j<=20; j++) {
			if (i%j != 0) {
				fail_div = true;
				break;
			}
		}
		if (!fail_div) {
			max_div = i;
			break;
		}
		i++;
	}

	fprintf(stdout, "[Problem 05] %d\n", max_div);

	return 0;
}
