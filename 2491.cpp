#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int n;
int arr[MAX];
int dp[MAX][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[i - 1]) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = 1;
        } else if (arr[i] == arr[i - 1]) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        } else {
            dp[i][0] = 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans << "\n";
}