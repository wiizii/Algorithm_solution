#include <iostream>
#define ll long long
using namespace std;

const int MOD = 1000000007;

ll arr[8][8] = {{0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0},
                {0, 0, 1, 1, 0, 1, 1, 0}, {0, 0, 0, 1, 1, 0, 1, 1},
                {0, 0, 0, 0, 1, 1, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0}};
ll ans[8][8];

void solve(ll (*a)[8], ll (*b)[8]) {
    ll tmp[8][8] = {
        0,
    };
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                tmp[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            a[i][j] = tmp[i][j] % MOD;
        }
    }
}

int main() {
    int d;
    cin >> d;
    for (int i = 0; i < 8; i++) ans[i][i] = 1;
    while (d > 0) {
        if (d & 1) {
            solve(ans, arr);
        }
        solve(arr, arr);
        d /= 2;
    }
    cout << ans[7][7] << "\n";
}