#include <bits/stdc++.h>
using namespace std;

const int MOD = 20000303;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = (ans * 10 + (s[i] - '0')) % MOD;
    }
    cout << ans << "\n";
}