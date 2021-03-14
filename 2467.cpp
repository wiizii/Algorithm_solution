#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int l = 0, r = n - 1;
    int ans_l = arr[l], ans_r = arr[r];
    int sum = abs(arr[l] + arr[r]);
    while (l < r) {
        if (sum > abs(arr[l] + arr[r])) {
            sum = abs(arr[l] + arr[r]);
            ans_l = arr[l], ans_r = arr[r];
        }
        if (arr[l] + arr[r] <= 0)
            l++;
        else
            r--;
    }
    cout << ans_l << " " << ans_r << "\n";
}