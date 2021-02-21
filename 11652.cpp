#include <iostream>
#include <map>
#define ll long long
using namespace std;

ll n, x;
map<ll, ll> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
    }
    ll ans = 0;
    ll cnt = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > cnt) {
            ans = it->first;
            cnt = it->second;
        }
    }
    cout << ans << "\n";
}