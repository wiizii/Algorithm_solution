#include <algorithm>
#include <iostream>
using namespace std;

int arr[51];
bool check[1001];

int main() {
    int l;
    cin >> l;
    for (int i = 1; i <= l; i++) {
        cin >> arr[i];
        check[arr[i]] = true;
    }
    int n;
    cin >> n;
    if (check[n]) {
        cout << 0 << "\n";
        return 0;
    }
    sort(arr, arr + l + 1);
    int left = 0, right = 0;
    for (int i = 0; i < l; i++) {
        int A = arr[i];
        int B = arr[i + 1];
        if (A <= n && n < B) {
            left = A;
            right = B;
            break;
        }
    }
    cout << (n - left) * (right - n) - 1 << "\n";
}