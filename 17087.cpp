#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int arr[100001];

int main() {
    int n, s;
    int input;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr[i] = abs(input - s);
    }
    sort(arr, arr + n);
    int ans = 1;
    int k = arr[0];
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            int big = k / i;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (arr[j] % i != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans = max(ans, i);
            flag = true;
            for (int j = 0; j < n; j++) {
                if (arr[j] % big != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans = max(ans, big);
        }
    }
    cout << ans << "\n";
}