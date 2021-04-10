#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

pii arr[1500001];
int dp[1500001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < n; i++) {
        auto [t, p] = arr[i];
        if (i + t > n) continue;
        dp[i] = max(dp[i], dp[i - 1]);
        dp[i + t] = max(dp[i + t], dp[i] + p);
        ans = max(ans, dp[i + t]);
    }
    cout << ans << "\n";
}