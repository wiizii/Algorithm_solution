#include <bits/stdc++.h>
using namespace std;

int n, k;

priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int minValue = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        minValue = min(minValue, x);
        pq.push(x);
    }

    int cnt = 0;
    int ans = 0;

    while (!pq.empty() && pq.top() != minValue) {
        int diff = pq.top() - minValue;
        ans += diff;
        pq.pop();
        cnt++;
        pq.push(minValue);
    }
    cout << ans << " " << cnt << endl;
}