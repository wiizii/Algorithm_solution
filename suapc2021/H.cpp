#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n;
vector<pair<ll, ll>> v;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll get_sum(int s, int e) {
    ll ret = 0;
    ll k = e - s;
    ret = (k * (k - 1)) / 2;
    return ret;
}

int main() {
    ll ans = 0;
    cin >> n;
    ans = get_sum(0, n);
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b});
    }
    for (int i = 0; i < v.size(); i++) {
        ll &a = v[i].first;
        ll &b = v[i].second;
        if ((a < 0 && b < 0) || (a < 0 && b > 0)) {
            a = -a;
            b = -b;
        }
        ll g = 0;
        if (a != 0 && b == 0)
            g = gcd(a, abs(b));
        else if (a == 0 && b != 0)
            g = gcd(abs(b), a);
        else
            g = gcd(a, abs(b));

        a /= g;
        b /= g;
    }
    sort(v.begin(), v.end());
    int s = 0, e = 0;
    while (e <= n) {
        if (e == n) {
            ans -= get_sum(s, e);
            break;
        }
        if (v[s].first == v[e].first && v[s].second == v[e].second) {
            e++;
        } else {
            ans -= get_sum(s, e);
            s = e;
        }
    }
    cout << ans << "\n";
}