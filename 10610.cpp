#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool cmp(const char &a, const char &b) { return a > b; }
string s;

int main() {
    cin >> s;
    sort(s.begin(), s.end(), cmp);
    int acc = 0;
    for (int i = 0; i < s.size(); i++) acc += s[i] - '0';
    if (acc % 3 == 0 && s.back() == '0') {
        cout << s << "\n";
    } else {
        cout << -1 << "\n";
    }
}