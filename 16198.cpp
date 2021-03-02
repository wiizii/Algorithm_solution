#include <algorithm>
#include <iostream>
using namespace std;

int arr[10];
bool check[10];

int solve(int n) {
    int ret = 0;
    for (int i = 1; i < n - 1; i++) {
        if (!check[i]) {
            int l = i - 1;
            int r = i + 1;
            while (check[l]) {
                l--;
            }
            while (check[r]) {
                r++;
            }
            check[i] = true;
            ret = max(ret, solve(n) + arr[l] * arr[r]);
            check[i] = false;
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(n) << "\n";
}