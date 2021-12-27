#include <bits/stdc++.h>
using namespace std;

int arr[120];
bool check[11][11];
int n, m, k;
int ans = -0x3f3f3f3f;

bool isValid(int v) {
    if (v % m != 0 && check[v / n][(v % m) - 1]) return false;
    if (v / n != 0 && check[(v / n) - 1][v % m]) return false;
    if (v % m != m - 1 && check[v / n][(v % m) + 1]) return false;
    if (v / n != n - 1 && check[(v / n) + 1][v % m]) return false;
    return true;
}

void solve(int cnt, int idx, int acc) {
    if (cnt == k) {
        ans = max(ans, acc);
        return;
    }

    for (int i = idx; i < n * m; i++) {
        if (isValid(i)) {
            check[i / n][i % m] = true;
            solve(cnt + 1, i + 1, acc + arr[i]);
            check[i / n][i % m] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n * m; i++) cin >> arr[i];

    solve(0, 0, 0);
    cout << ans << "\n";
}