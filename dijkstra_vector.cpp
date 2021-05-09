#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int, int>> adj[201];

vector<int> dijkstra(int n, int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cur_dist) continue;
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int next_dist = cur_dist + adj[cur][i].second;
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next, -next_dist});
            }
        }
    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for (int i = 0; i < fares.size(); i++) {
        adj[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        adj[fares[i][1]].push_back({fares[i][2], fares[i][2]});
    }
    vector<int> dist = dijkstra(n, s);
    for (int i = 1; i <= n; i++) {
        int co = dist[i];
        vector<int> dist_bye = dijkstra(n, i);
        int bye = dist_bye[a] + dist_bye[b];
        answer = min(answer, co + bye);
    }
    return answer;
}