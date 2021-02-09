#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int ans = 0;
int n, m;
int arr[16];
bool check[16];

int getAns() {
    int ret = 0;
    bool used[16];
    for (int i = 0; i < n * m; i++) used[i] = false;
    for (int i = 0; i < n * m; i++) {
        if (used[i]) continue;
        int sum = 0;
        if (check[i] == 0) {
            int j = i;
            int r = i / m;
            while (j / m == r && check[j] == 0) {
                sum = 10 * sum + arr[j];
                used[j++] = true;
            }
        } else {
            int j = i;
            while (j < n * m && check[j] == 1) {
                sum = 10 * sum + arr[j];
                used[j] = true;
                j += m;
            }
        }
        ret += sum;
    }
    return ret;
}

void solve(int cnt) {
    if (cnt == n * m) {
        int tmp = getAns();
        ans = max(ans, tmp);
        return;
    }
    check[cnt] = false;
    solve(cnt + 1);
    check[cnt] = true;
    solve(cnt + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) scanf("%1d", &arr[i]);
    solve(0);
    cout << ans << "\n";
}