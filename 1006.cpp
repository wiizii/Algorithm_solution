#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 20010;

int n, w;
int arr[MAX][2];
int dp[MAX][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        cin >> n >> w;
        for (int i = 0; i < n; i++) cin >> arr[i][0];
        for (int i = 0; i < n; i++) cin >> arr[i][1];
        arr[n][0] = arr[0][0];
        arr[n][1] = arr[0][1];
    
    }
}