#include <algorithm>
#include <iostream>
using namespace std;

int map[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, b, under = 0x3f3f3f3f, over = 0;
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            under = min(under, map[i][j]);
            over = max(over, map[i][j]);
        }
    }
    int ans = 0x3f3f3f3f, h = 0;
    while (under <= over) {
        int inven = b;
        int t = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] >= under) {
                    inven += map[i][j] - under;
                    t += 2 * (map[i][j] - under);
                } else {
                    inven -= under - map[i][j];
                    t += under - map[i][j];
                }
            }
        }
        if (inven >= 0) {
            if (ans >= t) {
                ans = t;
                h = under;
            }
        }
        under++;
    }
    cout << ans << " " << h << "\n";
    return 0;
}