#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1000001;
int arr[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll ans = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        int cost = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= cost)
                ans += cost - arr[i];
            else
                cost = arr[i];
        }
        cout << ans << "\n";
    }
}