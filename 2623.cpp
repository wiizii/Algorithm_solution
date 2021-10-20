#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int n, m;
int ind[MAX];
vector<int> adj[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int k;
            cin >> k;
            v.push_back(k);
        }
        for (int j = 1; j < x; j++) {
            adj[v[j - 1]].push_back(v[j]);
            ind[v[j]]++;
        }
    }
    vector<int> answer;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (ind[i] == 0) q.push(i);

    for (int i = 1; i <= n; i++) {
        if (q.empty()) {
            cout << "0\n";
            return 0;
        }

        int x = q.front();
        q.pop();
        answer.push_back(x);
        for (int next : adj[x]) {
            if (--ind[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i : answer) {
        cout << i << "\n";
    }
}