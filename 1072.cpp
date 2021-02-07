#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y;
    if (x == y) {
        cout << -1 << "\n";
        return 0;
    }
    z = ((double)y / (double)x) * 100;
    int ans = 0;
    int next = z;
    while (next == z) {
        next = ((double)++y / (double)++x) * 100;
        ans++;
    }
    cout << ans << "\n";
}