#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int weight[101];
int value[101];
int DP[101][100001];

void solve(){
    for(int i=1;i<=N;i++){
        for(int j=0;j<=K;j++){
            DP[i][j] = DP[i-1][j];
            if(j-weight[i]>=0)
                DP[i][j] = max(DP[i][j],DP[i-1][j-weight[i]]+value[i]);
        }
    }
}
int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++)
        cin >> weight[i] >> value[i];
    solve();
    cout << DP[N][K] << "\n";
}
