#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string bigInteger(string n, string m) {
    string ans = "";
    if (n.length() < m.length()) swap(n, m);
    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());
    int a = 0, b = 0, carry = 0;
    for (int i = 0; i < n.length(); i++) {
        a = n[i] - 48;
        b = i < m.length() ? m[i] - 48 : 0;
        ans += (a + b + carry) % 10 + 48;
        carry = (a + b + carry) / 10;
        if (carry == 1 && i == (n.length() - 1)) {
            ans += '1';
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string n, m;
    cin >> n >> m;
    cout << bigInteger(n, m) << '\n';
    return 0;
}