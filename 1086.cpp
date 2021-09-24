#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s[15];

ll arr[15][2];
ll dp[1 << 15][101];
int n, k;
ll tenPowMod[55];

ll solve(int visited, int x) {
    if (visited == (1 << n) - 1) return (x == 0);
    ll &ret = dp[visited][x];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i)) continue;
        int next = (x * tenPowMod[arr[i][1]] + arr[i][0]) % k;
        ret += solve(visited | (1 << i), next);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        arr[i][1] = s[i].size();
        for (int j = 0; j < s[i].size(); j++) {
            arr[i][0] = (arr[i][0] * 10 + (s[i][j] - '0')) % k;
        }
    }
    tenPowMod[0] = 1;
    for (int i = 1; i < 55; i++) {
        tenPowMod[i] = (tenPowMod[i - 1] * 10) % k;
    }

    ll a = 1;
    for (int i = 1; i <= n; i++) a *= i;
    ll b = solve(0, 0);
    ll g = gcd(a, b);
    cout << b / g << "/" << a / g << "\n";
}