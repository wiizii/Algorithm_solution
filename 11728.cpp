#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 2000001;

int arr[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) cin >> arr[i];
    sort(arr, arr + n + m);
    for (int i = 0; i < n + m; i++) cout << arr[i] << " ";
}