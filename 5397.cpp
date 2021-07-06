#include <bits/stdc++.h>
using namespace std;

void showPasswd(string s) {
    list<char> l;
    auto iter = l.end();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') {
            if (iter != l.begin()) iter--;
        } else if (s[i] == '>') {
            if (iter != l.end()) iter++;
        } else if (s[i] == '-') {
            if (iter != l.begin()) iter = l.erase(--iter);
        } else
            l.insert(iter, s[i]);
    }
    for (auto it = l.begin(); it != l.end(); it++) cout << *it;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        showPasswd(s);
    }
}