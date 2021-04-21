#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n;
pii c[200001];
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i].first >> c[i].second;
    sort(c, c + n);
    pq.push(-c[0].second);
    for (int i = 1; i < n; i++) {
        if (-pq.top() <= c[i].first) pq.pop();
        pq.push(-c[i].second);
    }
    cout << pq.size() << "\n";
}