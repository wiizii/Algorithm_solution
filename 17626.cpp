#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int dp[50001];

int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if ((int)sqrt(i) * (int)sqrt(i) == i)
            dp[i] = 1;
        else
            dp[i] = INF;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (int)sqrt(i); j++) {
            dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }
    cout << dp[n] << "\n";
}