#include <bits/stdc++.h>
using namespace std;

bool isPrime[1001];

int main() {
    int n, k;
    cin >> n >> k;
    int ans = -1;
    int cnt = 0;
    for (int i = 2; i <= n; i++) isPrime[i] = true;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i; j <= n; j += i) {
            if (!isPrime[j]) continue;
            isPrime[j] = false;
            cnt++;
            if (cnt == k) ans = j;
        }
    }
    cout << ans << "\n";
}