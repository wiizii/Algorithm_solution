#include <bits/stdc++.h>
using namespace std;

int n, m;
bool check[201][201];

int main() {
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        check[a][b] = true;
        check[b][a] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (!check[i][j] && !check[i][k] && !check[j][k]) ans++;
            }
        }
    }
    cout << ans << "\n";
}