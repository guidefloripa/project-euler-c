/*

Created on 03/2014

Author: guidefloripa

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and
 the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and
 the square of the sum.

*/

#include <stdio.h>

typedef unsigned long long uint64_t;

int main()
{
    uint64_t sum_squares = 0;
    uint64_t square_sums = 0;
    uint64_t i;

    for (i=1; i<=100; i++) {
        sum_squares += (i*i);
        square_sums += i;
    }
    square_sums *= square_sums;

    fprintf(stdout, "[Problem 06] %lld (%lld-%lld)\n", square_sums-sum_squares, square_sums, sum_squares);

    return 0;
}
