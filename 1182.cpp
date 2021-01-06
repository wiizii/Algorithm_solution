#include <iostream>
using namespace std;

int num[20];
int ans = 0;
int n, s;

void solve(int cnt, int sum, int start) {
    if (cnt != 0 && sum == s) ans++;
    if (cnt == n) return;
    for (int i = start; i < n; i++) solve(cnt + 1, sum + i, i + 1);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> num[i];
    solve(0, 0, 0);
    cout << ans << "\n";
    return 0;
}