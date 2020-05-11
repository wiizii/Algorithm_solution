#include <iostream>
#include <cstdio>
using namespace std;

int list[1000000];
int sorted[1000000];

void merge(int list[], int left,int mid,int right){
    int i,j,k,l;
    i = left;
    j = mid+1;
    k = left;
    while(i <= mid && j <= right){
        if(list[i] <=list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if(i>mid)
        for(l=j;l<=right;l++)
            sorted[k++] = list[l];
    else
        for(l=i;l<=mid;l++)
            sorted[k++] = list[l];
    for(l=left;l<=right;l++)
        list[l] = sorted[l];
}

void merge_sort(int list[],int left,int right){
    int mid;
    
    if(left < right){
        mid = (left+right)/2;
        merge_sort(list, left,mid);
        merge_sort(list, mid+1,right);
        merge(list, left,mid,right);
    }
}

int main(){
    int N;
    
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &list[i]);
    merge_sort(list,0,N-1);
    for(int i=0;i<N;i++)
        printf("%d\n",list[i]);
}
