#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
    int n, l;
    int ans = 0;
    cin >> n >> l;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    arr[n] = 1000000;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (arr[j] - arr[i] >= l) {
                ans++;
                i = j - 1;
                break;
            }
        }
    }
    cout << ans << "\n";
}