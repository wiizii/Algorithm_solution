#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string k;
        cin >> k;
        s.insert(k);
    }
    for (int i = 0; i < m; i++) {
        string k;
        cin >> k;
        if (s.count(k)) ans++;
    }
    cout << ans << "\n";
}