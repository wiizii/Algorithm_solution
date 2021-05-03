#include <bits/stdc++.h>
using namespace std;

int arr[302][302];

void rotate(int x1, int y1, int x2, int y2) {
    int tmp = arr[x1][y1];
    for (int i = y1; i < y2; i++) arr[x1][i] = arr[x1][i + 1];
    for (int i = x1; i < x2; i++) arr[i][y2] = arr[i + 1][y2];
    for (int i = y2; i > y1; i--) arr[x2][i] = arr[x2][i - 1];
    for (int i = x2; i > x1; i--) arr[i][y1] = arr[i - 1][y1];
    arr[x1 + 1][y1] = tmp;
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> arr[i][j];
    while (r--) {
        int x1 = 1, y1 = 1;
        int x2 = n, y2 = m;
        while (x1 < x2 && y1 < y2) {
            rotate(x1, y1, x2, y2);
            x1++, y1++;
            x2--, y2--;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}