#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];

int find(int first, int last, int cmp) {
    int mid = (first+last)/2;
    while(last-first >= 0){
        if(a[mid] == cmp)
            return 1;
        else if(a[mid] <= cmp)
            first = mid+1;
        else
            last = mid-1;
        mid = (first + last) / 2;
    }
    return 0;
}


int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d",&a[i]);
    sort(a, a+N);
    int M;
    int cmp;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &cmp);
        printf("%d\n", find(0,N,cmp));
    }
    return 0;
}
