#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
const int INF = 0x3f3f3f3f;

int arr[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = 0;
    int acc = arr[r];
    int ans = INF;
    while (r < n) {
        if (acc < s) {
            acc += arr[++r];
        } else if (acc == s) {
            ans = min(ans, r - l + 1);
            acc += arr[++r];
        } else {
            ans = min(ans, r - l + 1);
            acc -= arr[l++];
        }
    }
    if (ans == INF)
        cout << 0 << endl;
    else {
        cout << ans << "\n";
    }
}