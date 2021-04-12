#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

pii arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int ans = 1;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
        sort(arr, arr + n);
        int last = arr[0].second;
        for (int i = 1; i < n; i++) {
            if (arr[i].second < last) {
                ans++;
                last = arr[i].second;
            }
        }
        cout << ans << "\n";
    }
}