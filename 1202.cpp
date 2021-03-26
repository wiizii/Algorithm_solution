#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 300001;
struct info {
    int m, v;
};

priority_queue<int> pq;
info j[MAX];
int p[MAX];

bool cmp(const info &a, const info &b) { return a.m < b.m; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> j[i].m >> j[i].v;
    for (int i = 0; i < k; i++) cin >> p[i];
    sort(j, j + n, cmp);
    sort(p, p + k);

    long long ans = 0;
    int js = 0;
    for (int i = 0; i < k; i++) {
        while (js < n && j[js].m <= p[i]) pq.push(j[js++].v);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
}