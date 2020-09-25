#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int mod = 10000;
int dp[10000];
char trace[10000];
queue<int> q;
stack<char> s;

int D(int n) { return (n * 2) % mod; }
int S(int n) { return n == 0 ? 9999 : n - 1; }
int L(int n) { return (n * 10 + n / 1000) % mod; }
int R(int n) { return (n + n % 10 * 10000) / 10; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, to;
        memset(dp, -1, sizeof(dp));
        memset(trace, 0, sizeof(trace));
        cin >> n >> to;
        q.push(n);
        dp[n] = -2;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int d = D(x), s = S(x), l = L(x), r = R(x);
            if (dp[d] == -1) {
                dp[d] = x;
                trace[d] = 'D';
                q.push(d);
            }
            if (dp[s] == -1) {
                dp[s] = x;
                trace[s] = 'S';
                q.push(s);
            }
            if (dp[l] == -1) {
                dp[l] = x;
                trace[l] = 'L';
                q.push(l);
            }
            if (dp[r] == -1) {
                dp[r] = x;
                trace[r] = 'R';
                q.push(r);
            }
        }
        int last = to;
        while (dp[last] != -2) {
            s.push(trace[last]);
            last = dp[last];
        }
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << '\n';
    }
    return 0;
}