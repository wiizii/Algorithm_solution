#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q, w, e;
        cin >> q >> w >> e;
        v.push_back({w, e});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (pq.empty()) {
            pq.push(v[i].second);
            continue;
        }
        if (pq.top() <= v[i].first) {
            pq.pop();
            pq.push(v[i].second);
        } else {
            pq.push(v[i].second);
        }
    }
    cout << pq.size() << '\n';
}