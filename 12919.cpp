#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool solve(string s, string t) {
    if (s.size() == t.size()) return s == t;
    bool ret1 = false, ret2 = false;
    if (t.back() == 'A') {
        t.pop_back();
        ret1 = solve(s, t);
        t.push_back('A');
    }
    if (t.front() == 'B') {
        reverse(t.begin(), t.end());
        t.pop_back();
        ret2 = solve(s, t);
    }
    return ret1 || ret2;
}

int main() {
    string s, t;
    cin >> s >> t;
    if (solve(s, t))
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}