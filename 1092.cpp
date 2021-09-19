#include <bits/stdc++.h>
using namespace std;

int n, m;

int c[51];
int box[10001];
bool check[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> box[i];
    sort(c, c + n, greater<int>());
    sort(box, box + m, greater<int>());
    if (c[0] < box[0]) {
        cout << "-1\n";
        return 0;
    }

    int cnt = m;
    int idx = 0;

    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = idx; j < m; j++) {
                if (c[i] >= box[j] && !check[j]) {
                    check[j] = true;
                    if (i == 0) {
                        idx = j + 1;
                    }
                    cnt--;
                    break;
                }
            }
        }
        answer++;
        if (cnt == 0) break;
    }

    cout << answer << "\n";
}