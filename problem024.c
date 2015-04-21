/*
 
 Created on 04/2015
 
 Author: guidefloripa
 
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
 The lexicographic permutations of 0, 1 and 2 are:
 
 012   021   102   120   201   210
 
 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 
 */

#include <stdio.h>
#include <string.h>

int next_permutation(int* arr, int len)
{
    int i, j, temp;
    
    i = len - 1;
    while (i>0 && arr[i-1]>arr[i]) {
        i--;
    }
    if (i==0) return 0;
    
    j = len - 1;
    while (arr[j] <= arr[i-1]) {
        j--;
    }
    
    temp = arr[i-1];
    arr[i-1] = arr[j];
    arr[j] = temp;
    
    j = len -1;
    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return 1;
}

int main(int argc, char** argv)
{
    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = sizeof(numbers)/sizeof(numbers[0]);
    int i = 0;
    do {
        i++;
        if (i == 1000000) break;
        
    } while (next_permutation(numbers, s));
    
    fprintf(stderr, "[Problem 24] ");
    for (i = 0; i<s; i++) {
        fprintf(stderr, "%d", numbers[i]);
    }
    fprintf(stderr, "\n");
    
    return 0;
}
