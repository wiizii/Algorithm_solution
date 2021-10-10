#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 101;

vector<int> adj[MAX];
bool check[MAX];

int bfs(int a, int b) {
    memset(check, 0, sizeof(check));
    int ret = 1;
    queue<int> q;
    q.push(a);
    check[a] = true;
    check[b] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int next : adj[x]) {
            if (!check[next]) {
                check[next] = true;
                ret++;
                q.push(next);
            }
        }
    }

    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;
    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        int q = bfs(a, b);
        int w = bfs(b, a);
        answer = min(answer, abs(q - w));
    }

    return answer;
}