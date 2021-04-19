#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[1000001];
ll mod[1001];

int main() {
    int n, m;
    ll ans = 0;
    scanf("%d %d", &n, &m);
    mod[0] = 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    ll acc = 0;
    for (int i = 0; i < n; i++) {
        acc += arr[i];
        acc %= m;
        mod[acc]++;
    }
    for (int i = 0; i < m; i++) ans += mod[i] * (mod[i] - 1) / 2;
    cout << ans << "\n";
}