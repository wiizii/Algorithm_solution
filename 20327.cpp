#include <bits/stdc++.h>
using namespace std;

const int MAX = (1 << 7) + 1;
int arr[MAX][MAX];
int n, r, s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r;
    s = 1 << n;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            cin >> arr[i][j];
        }
    }

    while (r--) {
        int k, l;
        cin >> k >> l;
        l = 1 << l;
        if (k == 1) {
            for (int i = 0; i < s; i += l) {
                for (int j = 0; j < s; j += l) {
                    for (int x = i; x < i + (l / 2); x++) {
                        for (int y = j; y < j + l; y++) {
                            swap(arr[x][y], arr[i + l - 1 - x + i][y]);
                        }
                    }
                }
            }
        }
        if (k == 2) {
            for (int i = 0; i < s; i += l) {
                for (int j = 0; j < s; j += l) {
                    for (int x = i; x < i + l; x++) {
                        for (int y = j; y < j + (l / 2); y++) {
                            swap(arr[x][y], arr[x][j + l - 1 - y + j]);
                        }
                    }
                }
            }
        }
        if (k == 3) {
            for (int i = 0; i < s; i += l) {
                for (int j = 0; j < s; j += l) {
                    int tmp[l][l];
                    for (int x = i; x < i + l; x++) {
                        for (int y = j; y < j + l; y++) {
                            tmp[y - j][l - 1 - x + i] = arr[x][y];
                        }
                    }
                    for (int x = i; x < i + l; x++) {
                        for (int y = j; y < j + l; y++) {
                            arr[x][y] = tmp[x - i][y - j];
                        }
                    }
                }
            }
        }
        if (k == 4) {
            for (int i = 0; i < s; i += l) {
                for (int j = 0; j < s; j += l) {
                    int tmp[l][l];
                    for (int x = i; x < i + l; x++) {
                        for (int y = j + l - 1; y >= j; y--) {
                            tmp[l - 1 - y + j][x - i] = arr[x][y];
                        }
                    }
                    for (int x = i; x < i + l; x++) {
                        for (int y = j; y < j + l; y++) {
                            arr[x][y] = tmp[x - i][y - j];
                        }
                    }
                }
            }
        }
        if (k == 5) {
        }
        if (k == 6) {
        }
        if (k == 7) {
        }
        if (k == 8) {
        }

        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
}