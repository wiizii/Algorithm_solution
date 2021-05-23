#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[51];

int solve(int cur) {
    int ret = 0;
    vector<int> v;
    for (auto next : adj[cur]) v.push_back(solve(next));
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++) ret = max(ret, v[i] + i + 1);
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != -1) adj[x].push_back(i);
    }
    cout << solve(0) << "\n";
}