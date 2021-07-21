#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    regex re("(100+1+|01)+");
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (regex_match(s, re))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}