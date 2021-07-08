#include <bits/stdc++.h>
using namespace std;

int arr[1001];
bool visited[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        int ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                int cur = i;
                while (!visited[cur]) {
                    visited[cur] = true;
                    cur = arr[cur];
                }
                ans++;
            }
        }
        cout << ans << "\n";
    }
}