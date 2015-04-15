/*
 
 Created on 03/2014
 
 Author: guidefloripa
 
 n! means n × (n − 1) × ... × 3 × 2 × 1
 
 For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 
 Find the sum of the digits in the number 100!
 
 */

#include <stdio.h>
#include <string.h>

#define SUM_LEN 200

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
	int i, j, k;
	int sum[SUM_LEN];
	int temp[SUM_LEN];
	int carry;
	
	memset(&sum, 0, sizeof(sum));
	
	sum[SUM_LEN-1] = 1;
	for (i=2; i<=100; i++) {
		memcpy(&temp, &sum, sizeof(sum));
		for (j=1; j<i; j++) {
			carry = 0;
			for (k=(SUM_LEN-1); k>=0; k--) {
				sum[k] = sum[k]+temp[k]+carry;
				carry = sum[k]/10;
				sum[k] = sum[k]%10;
			}
		}
	}
	
	carry = printsum(sum, 0);
	fprintf(stderr, "[Problem 20] %d\n", carry);
	
	
	return 0;
}
