#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
int a[51][51];
int b[51][51];

bool check_ans() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != b[i][j]) return false;
    return true;
}

void modify(int x, int y) {
    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++) a[i][j] = !a[i][j];
}

int main() {
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%1d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%1d", &b[i][j]);
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (a[i][j] ^ b[i][j]) {
                modify(i, j);
                ans++;
            }
        }
    }
    if (check_ans()) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }
}