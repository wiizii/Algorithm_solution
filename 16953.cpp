#include <algorithm>
#include <iostream>
#include <queue>
#define ll long long
using namespace std;

queue<pair<ll, ll>> q;

int main() {
    ll a, b;
    ll ans = -1;
    cin >> a >> b;
    q.push({a, 0});
    while (!q.empty()) {
        ll n = q.front().first;
        ll cnt = q.front().second;
        q.pop();
        if (n == b) {
            ans = cnt;
            break;
        }
        if (n * 2 <= b) q.push({n * 2, cnt + 1});
        if (n * 10 + 1 <= b) q.push({n * 10 + 1, cnt + 1});
    }
    if (ans == -1)
        cout << -1 << "\n";
    else
        cout << ans + 1 << "\n";
}
