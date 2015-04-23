/*
 
 Created on 04/2015
 
 Author: guidefloripa
 
 The Fibonacci sequence is defined by the recurrence relation:
 
 Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 Hence the first 12 terms will be:
 
 F1 = 1
 F2 = 1
 F3 = 2
 F4 = 3
 F5 = 5
 F6 = 8
 F7 = 13
 F8 = 21
 F9 = 34
 F10 = 55
 F11 = 89
 F12 = 144
 The 12th term, F12, is the first term to contain three digits.
 
 What is the first term in the Fibonacci sequence to contain 1000 digits?
 
 */

#include <stdio.h>
#include <string.h>

#define SUM_LEN 1010

static void sum(int *a, int *b, int *r, int len)
{
    int i;
    int carry = 0;
    
    memset(r, 0, len*sizeof(int));
    for (i=(len-1); i>=0; i--) {
        r[i] = a[i]+b[i]+carry;
        carry = r[i]/10;
        r[i] %= 10;
    }
}

static int count_digits(int *a, int len)
{
    int i;
    int n = 0;
    
    for (i=0; i<len; i++) {
        if (a[i]!=0) break;
        n++;
    }
    
    return len-n;
}

int main(int argc, char** argv)
{
    int t[SUM_LEN];
    int t1[SUM_LEN];
    int temp[SUM_LEN];
    int n;
    
    memset(t, 0, sizeof(t));
    memset(t1, 0, sizeof(t1));
    
    t[SUM_LEN-1] = 1;
    t1[SUM_LEN-1] = 1;
    
    n = 2;
    
    while (count_digits(t1, SUM_LEN)<1000) {
        sum(t, t1, temp, SUM_LEN);
        memcpy(t, t1, sizeof(t));
        memcpy(t1, temp, sizeof(t));
        n++;
    }
    
    fprintf(stderr, "[Problem 25] %d\n", n);
    
    return 0;
}
