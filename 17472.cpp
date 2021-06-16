#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MAX = 11;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int arr[MAX][MAX];
bool check[MAX][MAX];
vector<tiii> edge;
int n, m;
int parent[MAX];

void setIsland(int _x, int _y, int k) {
    queue<pii> q;
    q.push({_x, _y});
    check[_x][_y] = true;
    arr[_x][_y] = k;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || !arr[nx][ny])
                continue;
            if (!check[nx][ny]) {
                check[nx][ny] = true;
                arr[nx][ny] = k;
                q.push({nx, ny});
            }
        }
    }
}

void findPath(int _x, int _y) {
    int k = arr[_x][_y];
    for (int i = 0; i < 4; i++) {
        int x = _x + dx[i], y = _y + dy[i];
        int t = 0;
        bool flag = false;
        while (x >= 0 && x < n && y >= 0 && y < m) {
            if (arr[x][y] == k) break;
            if (arr[x][y] != 0 && arr[x][y] != k) {
                flag = true;
                break;
            }
            t++;
            x += dx[i], y += dy[i];
        }
        if (flag && t >= 2) edge.push_back({t, k, arr[x][y]});
    }
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[u] = v;
}

int kruskal() {
    int ret = 0;
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        auto [cost, u, v] = edge[i];
        if (find(u) == find(v)) continue;
        merge(u, v);
        ret += cost;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    for (int i = 0; i < MAX; i++) parent[i] = i;
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j] || check[i][j]) continue;
            setIsland(i, j, k++);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) findPath(i, j);
        }
    }

    int ans = kruskal();
    bool flag = true;
    for (int i = 1; i < k; i++) {
        for (int j = 1; j < k; j++) {
            if (i == j) continue;
            if (find(i) != find(j)) flag = false;
        }
    }
    if (flag)
        cout << ans << "\n";
    else
        cout << -1 << "\n";
}