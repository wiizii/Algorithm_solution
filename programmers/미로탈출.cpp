#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

vector<pii> adj[1001];
vector<pii> adjRev[1001];
vector<int> t;
int check[1001][1 << 10];

bool isTrap(int node) {
    for (int i = 0; i < t.size(); i++)
        if (node == t[i]) return true;
    return false;
}

bool isTrapOn(int node, int mask) {
    int idx = -1;
    for (int i = 0; i < t.size(); i++) {
        if (node == t[i]) {
            idx = i;
            break;
        }
    }
    return mask & (1 << idx);
}

int getNewMask(int node, int mask) {
    for (int i = 0; i < t.size(); i++) {
        if (node == t[i]) {
            mask ^= (1 << i);
            break;
        }
    }
    return mask;
}

void bfs(int start) {
    queue<pii> q;
    q.push({start, 0});
    check[start][0] = 0;
    while (!q.empty()) {
        auto [cur, mask] = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            auto [next, dist] = adj[cur][i];
            if (isTrap(cur) && !isTrap(next) && !isTrapOn(cur, mask)) {
                if (check[cur][mask] + dist < check[next][mask]) {
                    check[next][mask] = check[cur][mask] + dist;
                    q.push({next, mask});
                }
            }
            if (isTrap(cur) && isTrap(next) &&
                !(isTrapOn(cur, mask) ^ isTrapOn(next, mask))) {
                int newMask = getNewMask(next, mask);
                if (check[cur][mask] + dist < check[next][newMask]) {
                    check[next][newMask] = check[cur][mask] + dist;
                    q.push({next, newMask});
                }
            }
            if (!isTrap(cur) && !isTrap(next)) {
                if (check[cur][mask] + dist < check[next][mask]) {
                    check[next][mask] = check[cur][mask] + dist;
                    q.push({next, mask});
                }
            }
            if (!isTrap(cur) && isTrap(next) && !isTrapOn(next, mask)) {
                int newMask = getNewMask(next, mask);
                if (check[cur][mask] + dist < check[next][newMask]) {
                    check[next][newMask] = check[cur][mask] + dist;
                    q.push({next, newMask});
                }
            }
        }
        for (int i = 0; i < adjRev[cur].size(); i++) {
            auto [next, dist] = adjRev[cur][i];
            if (isTrap(cur) && !isTrap(next) && isTrapOn(cur, mask)) {
                if (check[cur][mask] + dist < check[next][mask]) {
                    check[next][mask] = check[cur][mask] + dist;
                    q.push({next, mask});
                }
            }
            if (isTrap(cur) && isTrap(next) &&
                (isTrapOn(cur, mask) ^ isTrapOn(next, mask))) {
                int newMask = getNewMask(next, mask);
                if (check[cur][mask] + dist < check[next][newMask]) {
                    check[next][newMask] = check[cur][mask] + dist;
                    q.push({next, newMask});
                }
            }
            if (!isTrap(cur) && isTrap(next) && isTrapOn(next, mask)) {
                int newMask = getNewMask(next, mask);
                if (check[cur][mask] + dist < check[next][newMask]) {
                    check[next][newMask] = check[cur][mask] + dist;
                    q.push({next, newMask});
                }
            }
        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads,
             vector<int> traps) {
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < (1 << 10); j++) check[i][j] = INF;
    t = traps;
    for (int i = 0; i < roads.size(); i++) {
        adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adjRev[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    bfs(start);
    int answer = INF;
    for (int i = 0; i < (1 << 10); i++) {
        answer = min(answer, check[end][i]);
    }
    return answer;
}