#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0x3f3f3f3f;
int arr[21][21];
vector<int> sel_a, sel_b;

void solve(int cnt, int a, int b) {
    if (cnt == n) {
        if (!sel_a.empty() && !sel_b.empty()) {
            ans = min(ans, abs(a - b));
        }
        return;
    }
    int diff_a = 0, diff_b = 0;
    for (int i = 0; i < sel_a.size(); i++)
        diff_a += arr[cnt][sel_a[i]] + arr[sel_a[i]][cnt];
    for (int i = 0; i < sel_b.size(); i++)
        diff_b += arr[cnt][sel_b[i]] + arr[sel_b[i]][cnt];
    sel_a.push_back(cnt);
    solve(cnt + 1, a + diff_a, b);
    sel_a.pop_back();
    sel_b.push_back(cnt);
    solve(cnt + 1, a, b + diff_b);
    sel_b.pop_back();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    solve(0, 0, 0);
    cout << ans << "\n";
}