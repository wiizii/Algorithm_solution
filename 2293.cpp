#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int price[10001];
int cost[101];

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    price[0] = 1;
    for(int i=1;i<=n;i++)
        scanf("%d",&cost[i]);
    for(int i=1;i<=n;i++){
        for(int j=cost[i];j<=k;j++)
            price[j] += price[j-cost[i]];
    }
    
    printf("%d\n",price[k]);
}
