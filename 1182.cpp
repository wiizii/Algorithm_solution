#include <iostream>
using namespace std;

int arr[20];
int n, s;
int ans = 0;

void solve(int cnt, int sum, int start) {
    if (cnt != 0 && sum == s) ans++;
    if (cnt == n) return;
    for (int i = start; i < n; i++) {
        solve(cnt + 1, sum + arr[i], i + 1);
    }
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];
    solve(0, 0, 0);
    cout << ans << "\n";
    return 0;
}