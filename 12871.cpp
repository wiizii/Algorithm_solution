#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int lcm = s1.size() * s2.size();
    string tmp1, tmp2;
    while (tmp1.size() < lcm) {
        tmp1 += s1;
    }
    while (tmp2.size() < lcm) {
        tmp2 += s2;
    }
    if (tmp1 == tmp2)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}
