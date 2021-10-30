#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x >> y;
    int ratio = (n * x) / 100;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= y) {
            cnt++;
        }
    }
    cout << ratio << " " << cnt << "\n";
}