#include <cstdio>
#include <iostream>

using namespace std;

int arr[51][51];

int main() {
    int ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%1d", &arr[i][j]);

    int limit = n >= m ? m : n;

    for (int k = 0; k < limit; k++) {
        for (int i = 0; i < n - k; i++) {
            for (int j = 0; j < m - k; j++) {
                if (arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i][j + k] &&
                    arr[i][j] == arr[i + k][j + k])
                    ans = k + 1;
            }
        }
    }
    cout << ans * ans << "\n";
}