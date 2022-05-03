#include <bits/stdc++.h>
using namespace std;
using tiiii = tuple<int, int, int, int>;

const int MAX = 20;
vector<int> adj[20];
bool check[MAX][1 << MAX];

int solve(vector<int> &info) {
    int ret = 0;
    queue<tiiii> q;
    q.push({0, 1, 1, 0});
    check[0][1] = true;
    while (!q.empty()) {
        auto [cur, mask, sheep, wolf] = q.front();
        ret = max(ret, sheep);
        q.pop();
        for (int next : adj[cur]) {
            int nSheep = sheep;
            int nWolf = wolf;
            if (!(mask & (1 << next))) {
                if (info[next]) {
                    nWolf++;
                } else {
                    nSheep++;
                }
            }
            if (!check[next][mask | (1 << next)] && nSheep > nWolf) {
                check[next][mask | (1 << next)] = true;
                q.push({next, mask | (1 << next), nSheep, nWolf});
            }
        }
    }

    return ret;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    answer = solve(info);

    return answer;
}