//
//  main.c
//  QuickSort
//
//  Created by 위지원 on 25/11/2019.
//  Copyright © 2019 위지원. All rights reserved.
//

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
// According to K&R, rand() produces 16 bit random numbers.
// Luckily, the current version seem to produce 32 bit ones!
#include <time.h>

#define N 1000000 // one million.
#define K 1000
int data[N];

int depth; // Global variable

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int arr[], int l, int r)
{
    int x=arr[l];
    int i=l+1;
    int j=r;
    while (1) {
        while (arr[i] <= x && i<=r) i++;
        while (arr[j] > x && j>=l) j--;
        if (i<j) swap(&arr[i],&arr[j]);
        else break;
    }
    swap(&arr[l],&arr[j]);
    return j;
    
}

void myQuicksort(int arr[], int l, int r, int d)
{
    int p;
    if (depth < d) depth = d; // depth updated
    if (l < r) {
        p = partition(arr, l, r);
        myQuicksort(arr, l, p-1, d+1);
        myQuicksort(arr, p+1, r, d+1);
    }
}

int main()
{
    time_t t;
    int i, j;
    srand((unsigned) time(&t)); // Intializes random number generator
    for(j=0; j<K; j++){
        for(i=0; i<N; i++){
            data[i]=rand();
        }
        depth=0; // set the global variable depth = 0 before calling quicksort
        myQuicksort(data,j*N,(j+1)*N-1,0); // the first call with d=0
        printf("Recursion depth = %d\n", depth);
    }
}
