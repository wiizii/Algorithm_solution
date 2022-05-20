#include <bits/stdc++.h>
using namespace std;

set<string> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 1; j < str.size() - i + 1; j++) {
            s.insert(str.substr(i, j));
        }
    }
    cout << s.size() << "\n";
}