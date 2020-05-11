#include <iostream>
#include <cstdio>
using namespace std;

int k=0;

void number(int from, int to){
    k++;
}

void move(int from, int to){
    printf("%d %d\n",from, to);
}

void hanoi(int n,int from,int by,int to){
    if(n == 1)
        move(from,to);
    else{
        hanoi(n-1,from,to,by);
        move(from, to);
        hanoi(n-1, by,from,to);
    }
}


void hanoinum(int n,int from,int by,int to){
    if(n == 1)
        number(from,to);
    else{
        hanoinum(n-1,from,to,by);
        number(from, to);
        hanoinum(n-1, by,from,to);
    }
}

int main(){
    int N;
    cin >> N;
    hanoinum(N,1,2,3);
    printf("%d\n",k);
    hanoi(N,1,2,3);
}


