#include <bits/stdc++.h>
using namespace std;

int n;
int arr[101];

int main() {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = n - 1; i > 0; i--) {
        if (arr[i] <= arr[i - 1]) {
            int tmp = arr[i - 1] - arr[i] + 1;
            ans += tmp;
            arr[i - 1] -= tmp;
        }
    }
    cout << ans << "\n";
}