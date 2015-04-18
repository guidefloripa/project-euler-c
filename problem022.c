/*
 
 Created on 03/2014
 
 Author: guidefloripa
 
 
 Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
 begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value
 by its alphabetical position in the list to obtain a name score.
 
 For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
 So, COLIN would obtain a score of 938 × 53 = 49714.
 
 What is the total of all the name scores in the file?
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMES_LEN 5200

static int score(const char* name)
{
    int score = 0;
    int len = (int)strlen(name);
    int i;
    
    for (i=0; i<len; i++) {
        score += (name[i] - 'A' + 1);
    }
    
    return score;
}

static int compare_function(const void* a, const void*b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

int main(int argc, char** argv)
{
    FILE *f;
    char c;
    int i;
    int word_open = 0;
    int nwords = 0;
    int buffer_ptr = 0;
    char buffer[1024];
    char* names[NAMES_LEN];
    unsigned long long acc = 0;
    
    f = fopen("names.txt", "r");
    if (!f) {
        fprintf(stderr, "Missing File 'names.txt'\n");
        return 1;
    }
    
    memset(names, 0, sizeof(names));
    while ((c=fgetc(f))!=EOF) {
        if (c=='\"') {
            if (word_open) {
                buffer[buffer_ptr] = 0;
                buffer_ptr = 0;
                names[nwords] = (char*)malloc(strlen(buffer)+1);
                sprintf(names[nwords], "%s", buffer);
                nwords++;
                word_open = 0;
            }
            else {
            	word_open = 1;
            }
        }
        else if (word_open) {
            buffer[buffer_ptr++] = c;
        }
    }
    
    fclose(f);
    
    qsort(names, nwords, sizeof(char*), compare_function);
    
    for (i=0; i<nwords; i++) {
        if (names[i]) acc += ((i+1) * score(names[i]));
    }
    
    for (i=0; i<NAMES_LEN; i++) {
        if (names[i]) free(names[i]);
    }
    
    fprintf(stderr, "[Problem 22] %llu\n", acc);
    
    return 0;
}
