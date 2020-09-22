#include <algorithm>
#include <iostream>
using namespace std;
int dp[1001] = {0, 1};

int solve(int s) {
    if (s == 1) return 1;
    if (dp[s]) return dp[s];
    if (!(s & 1)) {
        dp[s] = min(solve(s / 2) + 2, solve(s - 1) + 1);
    } else {
        dp[s] = solve(s - 1) + 1;
    }
    return dp[s];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s;
    cin >> s;
    cout << solve(s) << "\n";
    return 0;
}