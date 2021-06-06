#include <bits/stdc++.h>
using namespace std;

int na, nb, nc;
char ans[51];
int dp[51][51][51];

int solve(int n, int a, int b, int c) {
    int &ret = dp[a][b][c];
    if (ret != -1) return ret;
    if (a == 0 && b == 0 && c == 0) return ret = 1;
    if (a > 0) {
        ans[n] = 'A';
        if (solve(n + 1, a - 1, b, c) == 1) return ret = 1;
    }
    if ((b > 0 && n > 0 && ans[n - 1] != 'B') || n == 0) {
        ans[n] = 'B';
        if (solve(n + 1, a, b - 1, c) == 1) return ret = 1;
    }
    if ((c > 0 && n > 1 && ans[n - 1] != 'C' && ans[n - 2] != 'C') || n == 0 ||
        (n == 1 && ans[0] != 'C')) {
        ans[n] = 'C';
        if (solve(n + 1, a, b, c - 1) == 1) return ret = 1;
    }
    return 0;
}

int main() {
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') na++;
        if (s[i] == 'B') nb++;
        if (s[i] == 'C') nc++;
    }
    if (solve(0, na, nb, nc) == 1)
        for (int i = 0; i < s.size(); i++) cout << ans[i];
    else
        cout << -1 << "\n";
}