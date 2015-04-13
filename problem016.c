/*
 
 Created on 04/2015
 
 Author: guidefloripa
 
 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 
 What is the sum of the digits of the number 2^1000?
 
 */

#include <stdio.h>
#include <string.h>

#define SUM_LEN 400

static int printsum(int *sum, int print)
{
	int i;
	int s = 0;
	int found = 0;
	for (i=0; i<SUM_LEN; i++) {
		if (sum[i] || found) {
			s += sum[i];
			if (print) fprintf(stderr, "%d", sum[i]);
			found = 1;
		}
	}
	if (print) fprintf(stderr, "\n");
	return s;
}

int main(int argc, char** argv)
{
	int i, j;
	int sum[SUM_LEN];
	int carry;
	
	memset(&sum, 0, sizeof(sum));
	
	sum[SUM_LEN-1] = 2;
	for (i=2; i<=1000; i++) {
		carry = 0;
		for (j=(SUM_LEN-1); j>=0; j--) {
			sum[j] = sum[j]*2+carry;
			carry = sum[j]/10;
			sum[j] %= 10;
		}
	}
	
	carry = printsum(sum, 1);
	fprintf(stderr, "[Problem 16] %d\n", carry);
	
	return 0;
}
