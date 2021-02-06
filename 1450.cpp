#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

int arr[31];

int main() {
    int ans = 1;
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int r = i + 1;
        ll sum = arr[i];
        if (sum <= c) ans++;
        while (r < n) {
            sum += arr[r++];
            if (sum <= c) ans++;
        }
    }

    cout << ans << "\n";
}