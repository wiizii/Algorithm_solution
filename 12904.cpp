#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    while (s.size() < t.size()) {
        if (t.back() == 'A')
            t.pop_back();
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if (s == t)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}