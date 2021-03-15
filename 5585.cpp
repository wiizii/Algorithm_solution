#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    int n;
    cin >> n;
    n = 1000 - n;
    if (n >= 500) {
        n -= 500;
        ans++;
    }
    if (n >= 100) {
        int cnt = n / 100;
        n -= cnt * 100;
        ans += cnt;
    }
    if (n >= 50) {
        n -= 50;
        ans++;
    }
    if (n >= 10) {
        int cnt = n / 10;
        n -= cnt * 10;
        ans += cnt;
    }
    if (n >= 5) {
        n -= 5;
        ans++;
    }
    ans += n;
    cout << ans << "\n";
}