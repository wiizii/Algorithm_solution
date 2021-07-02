#include <bits/stdc++.h>
using namespace std;

int main() {
    double x, y, d, t;
    cin >> x >> y >> d >> t;
    double dist = sqrt(x * x + y * y);

    double ans = dist;
    int cnt = dist / d;
    dist -= cnt * d;

    if (cnt == 0) {
        ans = min(ans, t + d - dist);
        ans = min(ans, 2.0 * t);
    } else {
        ans = min(ans, cnt * t + dist);
        ans = min(ans, (cnt + 1) * t);
    }
    cout << fixed;
    cout.precision(13);
    cout << ans << "\n";
}