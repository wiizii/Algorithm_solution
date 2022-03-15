#include <bits/stdc++.h>
using namespace std;

const int MAX = 610;

int arr[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    for (int i = 0; i < h + x; i++) {
        for (int j = 0; j < w + y; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = x; i < h + x; i++) {
        for (int j = y; j < w + y; j++) {
            arr[i][j] -= arr[i - x][j - y];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}