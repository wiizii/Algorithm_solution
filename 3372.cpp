#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int arr[101][101];
string dp[101][101];
int n;

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

string solve(int r, int c) {
    if (r == n - 1 && c == n - 1) return "1";
    if (r >= n || c >= n || !arr[r][c]) return "0";
    if (dp[r][c] != "0") return dp[r][c];
    return dp[r][c] =
               bigInteger(solve(r + arr[r][c], c), solve(r, c + arr[r][c]));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) dp[i][j] = "0";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    cout << solve(0, 0) << "\n";
}