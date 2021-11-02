#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 123460;

int n;
vector<int> adj[MAX];
ll arr[MAX];
bool kinds[MAX];

ll solve(int start) {
    ll ret = 0;
    for (int i = 0; i < adj[start].size(); i++) {
        ret += solve(adj[start][i]);
    }
    if (!kinds[start])
        return ret + arr[start];
    else {
        if (arr[start] < ret)
            return ret - arr[start];
        else
            return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i < n + 1; i++) {
        char a;
        ll b;
        int c;
        cin >> a >> b >> c;
        if (a == 'W') kinds[i] = true;
        arr[i] = b;
        adj[c].push_back(i);
    }

    cout << solve(1) << "\n";
}