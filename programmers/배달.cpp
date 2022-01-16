#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int, int>> adj[51];

vector<int> dijkstra(int n, int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        int cur = pq.top().first;
        int cur_dist = -pq.top().second;
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

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    for (int i = 0; i < road.size(); i++) {
        int u = road[i][0];
        int v = road[i][1];
        int d = road[i][2];
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    vector<int> dist = dijkstra(N, 1);
    for (int i = 1; i <= N; i++) {
        cout << dist[i] << " ";
        if (dist[i] <= K) answer++;
    }
    return answer;
}