#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (s.find(x) != s.end())
            cout << "1\n";
        else
            cout << "0\n";
    }
}