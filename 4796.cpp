#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    while (++t) {
        int a, b, c;
        int ans = 0;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        ans += (c / b) * a;
        if ((c % b) > a)
            ans += a;
        else
            ans += c % b;
        cout << "Case " << t << ": " << ans << "\n";
    }
}