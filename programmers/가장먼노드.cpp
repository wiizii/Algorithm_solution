#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> adj[20001];
vector<int> dist(20001, -1);

int bfs(int n) {
    int ret = 0;
    int maxDist = 0;
    queue<pair<int, int>> q;
    q.push({n, 0});
    dist[n] = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if (dist[next] == -1) {
                dist[next] = d + 1;
                maxDist = max(maxDist, d + 1);
                q.push({next, d + 1});
            }
        }
    }
    for (int i = 0; i < dist.size(); i++)
        if (dist[i] == maxDist) ret++;
    return ret;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (auto &i : edge) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    answer = bfs(1);
    return answer;
}