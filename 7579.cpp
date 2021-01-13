#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans = 0x3f3f3f3f;
int arr[10001];
int memo[101];
int cost[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> memo[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n; i++) {
        for (int j = 10000; j >= 0; j--) {
            if (j >= cost[i]) {
                arr[j] = max(arr[j], arr[j - cost[i]] + memo[i]);
                if (arr[j] >= m)
                    ans = min(j, ans);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
