/*
 
 Created on 04/2015
 
 Author: guidefloripa
 
 Euler discovered the remarkable quadratic formula: n² + n + 41
 
 It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39.
 However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.
 
 The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79.
 The product of the coefficients, −79 and 1601, is −126479.
 
 Considering quadratics of the form:
 
 n² + an + b, where |a| < 1000 and |b| < 1000
 
 where |n| is the modulus/absolute value of n
 e.g. |11| = 11 and |−4| = 4
 Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
 
 */

#include <stdio.h>
#include <math.h>

static int isPrime(int value)
{
    int max = sqrt(value)+1;
    if (value%2==0) return 0;
    for (int i=3; i<max; i+=2) {
        if (value%i==0) return 0;
    }
    
    return 1;
}

int main(int argc, char** argv)
{
    int a, b, n, s;
    int max_n, max_a, max_b;
    
    max_a = -99999;
    max_b = -99999;
    max_n = 0;
    
    for (a=-999; a<1000; a++) {
        for (b=-999; b<1000; b++) {
            n = 0;
            while (1) {
                s = n*n + a*n + b;
                if (s > 0 && isPrime(s)) n++;
                else break;
            }
            
            if (n > max_n) {
                max_n = n;
                max_a = a;
                max_b = b;
            }
        }
    }
    
    fprintf(stdout, "[Problem 27] %d\n", max_a*max_b);
    return 0;
}
