#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int start = 1;
    for (int i = 0; i < n; i++) {
        if (start < arr[i]) break;
        start += arr[i];
    }
    cout << start << "\n";
}