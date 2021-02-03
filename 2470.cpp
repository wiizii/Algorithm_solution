#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];

int main() {
    int a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int left = 0, right = n - 1;
    int sum = 2000000001;
    while (left < right) {
        int tmp = arr[left] + arr[right];
        if (abs(tmp) < abs(sum)) {
            sum = tmp;
            a = arr[left];
            b = arr[right];
        }
        if (tmp < 0)
            left++;
        else
            right--;
    }
    cout << a << " " << b << "\n";
}