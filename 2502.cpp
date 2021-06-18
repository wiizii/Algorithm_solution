#include <bits/stdc++.h>
using namespace std;

int dp[31];

int solve(int a, int b, int n) {
    if (dp[n]) return dp[n];
    if (n == 1) return a;
    if (n == 2) return b;
    return dp[n] = solve(a, b, n - 1) + solve(a, b, n - 2);
}

int main() {
    int d, k;
    cin >> d >> k;
    for (int i = 1; i < 100000; i++) {
        for (int j = i; j < 100000; j++) {
            memset(dp, 0, sizeof(dp));
            if (solve(i, j, d) == k) {
                cout << i << "\n" << j << "\n";
                return 0;
            }
        }
    }
}