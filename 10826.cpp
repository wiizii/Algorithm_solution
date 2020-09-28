#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string dp[10001];

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

string fibo(int n) {
  if(dp[n] != "")
  return dp[n];
  return dp[n] = bigInteger(fibo(n-1), fibo(n-2));
}

int main() {
    int n;
    cin >> n;
    dp[0] = '0';
    dp[1] = '1';
    dp[2] = '1';
    for (int i = 3; i <= n; i++) {
        dp[i] = "";
    }
    cout << fibo(n) << '\n';
    return 0;
}