#include <algorithm>
#include <iostream>
#define MAX 100000
using namespace std;

int arr[MAX];

int main() {
    int n, x;
    int answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;

    sort(arr, arr + n);

    int left = 0, right = n - 1;
    while (left != right) {
        int sum = arr[left] + arr[right];
        if (sum == x) answer++;
        if (sum >= x)
            right--;
        else
            left++;
    }

    cout << answer << "\n";

    return 0;
}