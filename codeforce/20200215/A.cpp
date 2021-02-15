#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int arr[101] = {
            0,
        };
        int n;
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}