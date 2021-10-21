#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;
int n;
pii p[22];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cout.precision(7);
    cout << fixed;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
        vector<int> mask;
        for (int i = 0; i < n / 2; i++) mask.push_back(0);
        for (int i = 0; i < n / 2; i++) mask.push_back(1);
        ll ans = INF;
        do {
            ll x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                auto [_x, _y] = p[i];
                if (mask[i]) {
                    x += _x;
                    y += _y;
                } else {
                    x -= _x;
                    y -= _y;
                }
            }
            ans = min(ans, x * x + y * y);
        } while (next_permutation(mask.begin(), mask.end()));
        cout << sqrt(ans) << "\n";
    }
}