#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int len = b.size() - a.size();

    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= len; i++) {
        int cnt = 0;
        for (int j = i; j < i + a.size(); j++)
            if (b[j] != a[j - i]) cnt++;
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}