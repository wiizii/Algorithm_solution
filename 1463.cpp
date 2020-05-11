#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001];

int go(int n){
    if(n==1)
        return d[n];
    d[n] = d[n-1] + 1;
    if(n%2 == 0)
        d[n] = min(d[n/2] + 1,d[n]);
    if(n%3 == 0)
        d[n] = min(d[n/3] + 1,d[n]);
    return d[n];
}

int main(){
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
        go(i);
    cout << d[N] << endl;
}
