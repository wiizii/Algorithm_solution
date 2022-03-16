#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int dp[MAX];
int n;

int solve(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    int &ret = dp[n];
    if (ret != -1) return ret;
    int a = solve(n - 2);
    int b = solve(n - 5);
    if (a != -1 && b != -1) {
        return ret = min(a + 1, b + 1);
    } else if (a != -1 && b == -1) {
        return ret = a + 1;
    } else if (a == -1 && b != -1) {
        return ret = b + 1;
    } else {
        return -1;
    }
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(n) << "\n";
}