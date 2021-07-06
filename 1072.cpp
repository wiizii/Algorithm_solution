#include <iostream>
#define ll long long
using namespace std;

const ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ll x, y;
    ll ans = INF;
    cin >> x >> y;
    int z = (y * 100) / x;
    if (z >= 99) {
        cout << "-1\n";
        return 0;
    }
    int l = 0, r = 1000000000;
    while (l <= r) {
        ll mid = (l + r) / 2;
        int nextZ = ((y + mid) * 100) / (x + mid);
        if (nextZ > z) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << "\n";
}