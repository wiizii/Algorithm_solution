#include <bits/stdc++.h>
using namespace std;

int n, m;

int c[51];
int box[10001];
int idx[51];

int main() {
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
    int answer = 0;
    int size = m;
    for (int i = 0; i < n; i++) idx[i] = i;
    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = idx[i]; j < m; j++) {
                if (box[j] != 0 && c[i] >= box[j]) {
                    box[j] = 0;
                    idx[i]++;
                    size--;
                    break;
                }
            }
        }
        answer++;
        if (size == 0) break;
    }
    cout << answer << "\n";
}