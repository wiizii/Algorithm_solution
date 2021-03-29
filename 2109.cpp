#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    int n;
    int max_day = -1;
    cin >> n;
    vector<pii> v(n);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
        max_day = max(max_day, v[i].first);
    }
    sort(v.begin(), v.end(), [&](pii a, pii b) { return a.first > b.first; });
    int idx = 0;
    for (int i = max_day; i >= 1; i--) {
        while (idx < n && i <= v[idx].first) pq.push(v[idx++].second);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
}