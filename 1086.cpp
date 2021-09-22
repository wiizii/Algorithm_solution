#include <bits/stdc++.h>
#define ll long long
using namespace std;

string arr[15];

int dp[101][1 << 15];
int n, k;
int tenPowMod[51];

int solve(int x, int visited) {
    if (visited == (1 << n) - 1) return 0;
    int &ret = dp[x][visited];
    if (ret != -1) return ret;
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i)) continue;
        ret = (solve(x + 1, visited | (1 << i)) + arr[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    tenPowMod[0] = 1;
    for (int i = 1; i < 51; i++) {
        tenPowMod[i] = (tenPowMod[i - 1] * 10) % k;
    }

    ll a = 1;
    for (int i = 1; i <= n; i++) a *= i;
    ll b = solve(0, 0);
    ll g = gcd(a, b);
    cout << b / g << "/" << a / g << "\n";
}