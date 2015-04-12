/*

Created on 03/2014

Author: guidefloripa

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters
 used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115
 (one hundred and fifteen) contains 20 letters.
The use of "and" when writing out numbers is in compliance with British usage.

*/

#include <stdio.h>

static int CountLetters(int number)
{
	int count = 0;
	int n = number;

	if (n > 1000) {
		fprintf(stderr, "Only number until 1000!\n");
		return -32767;
	}

	if (n == 1000) {
		return 11; /* one thousand */
	}
	
	switch (n/100) {
		case 1: count+=10; break; /* one hundred */
		case 2: count+=10; break; /* two hundred */
		case 3: count+=12; break; /* three hundred */
		case 4: count+=11; break; /* four hundred */
		case 5: count+=11; break; /* five hundred */
		case 6: count+=10; break; /* six hundred */
		case 7: count+=12; break; /* seven hundred */
		case 8: count+=12; break; /* eight hundred */
		case 9: count+=11; break; /* nine hundred */
	}

	if (n>100 && n%100!=0) count += 3; /* and */

	n = n % 100;

	switch (n/10) {
		case 1: {
			if (n==10) count += 3; /* ten */
			else if (n==11) count += 6; /* eleven */
			else if (n==12) count += 6; /* twelve */
			else if (n==13) count += 8; /* fourteen */
			else if (n==14) count += 8; /* fourteen */
			else if (n==15) count += 7; /* fifteen */
			else if (n==16) count += 7; /* sixteen */
			else if (n==17) count += 9; /* seventeen */
			else if (n==18) count += 8; /* eighteen */
			else if (n==19) count += 8; /* nineteen */

			n = 0;
			break;
		}

		case 2: count+= 6 ; break; /* twenty */
		case 3: count+= 6 ; break; /* thirty */
		case 4: count+= 5 ; break; /* forty */
		case 5: count+= 5 ; break; /* fifty */
		case 6: count+= 5 ; break; /* sixty */
		case 7: count+= 7 ; break; /* seventy */
		case 8: count+= 6 ; break; /* eighty */
		case 9: count+= 6 ; break; /* ninety */
	}

	n = n % 10;

	switch (n) {
		case 1: count += 3; break; /* one */
		case 2: count += 3; break; /* two */
		case 3: count += 5; break; /* three */
		case 4: count += 4; break; /* four */
		case 5: count += 4; break; /* five */
		case 6: count += 3; break; /* six */
		case 7: count += 5; break; /* seven */
		case 8: count += 5; break; /* eight */
		case 9: count += 4; break; /* nine */
	}

	return count;
}


int main(int argc, char** argv)
{
	int i;
	int sum;

	for (i=1; i<=1000; i++) {
		sum += CountLetters(i);
	}
	fprintf(stderr, "[Problem 17] %d\n", sum);
	return 0;
}

