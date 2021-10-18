#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;
ll n, s;

ll solve(ll a, ll b) {
    if (b == 1) return a;
    if (b % 2) return (a * solve(a, b - 1)) % MOD;
    ll c = solve(a, b / 2) % MOD;
    return (c * c) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ans = 0;
    int m;
    cin >> m;

    while (m--) {
        cin >> n >> s;
        ll g = gcd(n, s);
        s /= g;
        n /= g;
        ans += (s * solve(n, MOD - 2)) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
}