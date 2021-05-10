#include <bits/stdc++.h>
#define ll long long
using namespace std;
using tllll = tuple<ll, ll, ll, ll>;

const ll INF = 0x3f3f3f3f3f3f3f3f;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

ll dist[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> solution(int n, int m, int s, vector<vector<int>> time_map) {
    vector<int> answer(2, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) dist[i][j] = INF;
    priority_queue<tllll, vector<tllll>, greater<tllll>> pq;
    pq.push({0, 0, 0, 0});
    dist[0][0] = 0;
    while (!pq.empty()) {
        auto [q, w, e, r] = pq.top();
        pq.pop();
        if (e == n - 1 && r == m - 1) return {(int)q, (int)w};
        for (int i = 0; i < 4; i++) {
            int nx = (int)e + dx[i];
            int ny = (int)r + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m ||
                time_map[nx][ny] == -1)
                continue;
            ll next_dist = w + time_map[nx][ny];
            if (next_dist < dist[nx][ny] && next_dist <= s) {
                dist[nx][ny] = next_dist;
                pq.push({q + 1, next_dist, nx, ny});
            }
        }
    }
}