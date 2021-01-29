#include <iostream>
#define ll long long
using namespace std;

int arr[10001];

int main() {
    int ans = 0;
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == m) ans++;
        }
    }
    cout << ans << "\n";
}