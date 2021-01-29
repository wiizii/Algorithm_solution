#include <iostream>
using namespace std;

int sqr(int a) { return a * a; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int sx, sy, ex, ey;
        int n;
        cin >> sx >> sy >> ex >> ey;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y, r, d;
            bool a, b;
            cin >> x >> y >> r;
            d = sqr(x - sx) + sqr(y - sy);
            a = d < sqr(r) ? true : false;
            d = sqr(x - ex) + sqr(y - ey);
            b = d < sqr(r) ? true : false;
            if (a ^ b) ans++;
        }
        cout << ans << "\n";
    }
}