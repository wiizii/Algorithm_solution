#include <bits/stdc++.h>
using namespace std;

int n, budget;
int arr[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> budget;

    int sum = 0;
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        max_num = max(max_num, arr[i]);
    }
    if (sum <= budget) {
        cout << max_num << "\n";
        return 0;
    }

    int ans = 0;
    int l = 1;
    int r = 1000000000;
    while (l <= r) {
        int mid = (l + r) / 2;
        int acc = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid)
                acc += mid;
            else
                acc += arr[i];
        }
        if (acc <= budget) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}