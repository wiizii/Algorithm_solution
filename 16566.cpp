#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[4000001];
bool check[4000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    int x;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) cin >> arr[i];
    sort(arr, arr + m);
    for (int i = 0; i < k; i++) {
        cin >> x;
        int idx = lower_bound(arr, arr + m, x) - arr;
        while (arr[idx] == x || check[idx]) idx++;
        check[idx] = true;
        cout << arr[idx] << "\n";
    }
}