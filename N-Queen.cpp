#include <iostream>
#include <cstdlib>
using namespace std;
int check[15];
int N;
int cnt_Queen = 0;

bool isSameline(int x){
    for(int i=0;i<x;i++)
        if(check[i] == check[x] || abs(check[i]-check[x]) == x-i)
            return 1;
    return 0;
}

void bt(int cnt){
    if(cnt==N){
        cnt_Queen++;
        return;
    }
    for(int i=0;i<N;i++){
        check[cnt] = i;
        if(!isSameline(cnt))
            bt(cnt+1);
    }
}

int main(){
    cin >> N;
    bt(0);
    cout << cnt_Queen << "\n";
    return 0;
}
