#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

pii arr[1500111];
int dp[1500111];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 1; i <= n; i++) {
        auto [t, p] = arr[i];
        dp[i] = max(dp[i], dp[i - 1]);
        dp[i + t] = max(dp[i + t], dp[i] + p);
    }
    for (int i = 1; i <= n + 1; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}