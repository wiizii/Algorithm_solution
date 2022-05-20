#include <bits/stdc++.h>
using namespace std;

set<int> s1, s2;

int differenceCount(set<int> &a, set<int> &b) {
    int cnt = 0;
    for (auto i : a) {
        if (b.find(i) == b.end()) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, x;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> x;
        s1.insert(x);
    }
    for (int i = 0; i < b; i++) {
        cin >> x;
        s2.insert(x);
    }

    int ans = differenceCount(s1, s2) + differenceCount(s2, s1);
    cout << ans << "\n";
}