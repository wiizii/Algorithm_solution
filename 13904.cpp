#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, d;
vector<pii> v;
priority_queue<pii> pq;

bool cmp(const pii& a, const pii& b) { return a.second < b.second; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int D = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int d, w;
        cin >> d >> w;
        v.push_back({w, d});
        D = max(D, d);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = D; i >= 1; i--) {
        while (!v.empty() && v.back().second == i) {
            pq.push(v.back());
            v.pop_back();
        }
        if (!pq.empty()) {
            answer += pq.top().first;
            pq.pop();
        }
    }

    cout << answer << "\n";
}
