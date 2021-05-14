#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;

int n, m, k;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<tiii> v[51][51];

void move() {
    vector<tiii> tmp[51][51];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) tmp[i][j].clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j].empty()) {
                for (tiii t : v[i][j]) {
                    auto [q, w, e] = t;
                    int ns = w % n;
                    int nx = i + dx[e] * ns;
                    int ny = j + dy[e] * ns;
                    if (nx < 0) nx += n;
                    if (ny < 0) ny += n;
                    if (nx >= n) nx -= n;
                    if (ny >= n) ny -= n;
                    tmp[nx][ny].push_back({q, w, e});
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) v[i][j] = tmp[i][j];
}

void merge() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j].size() > 1) {
                vector<tiii> tmp;
                bool flag = true;
                for (tiii t : v[i][j]) {
                    tmp.push_back(t);
                }
                v[i][j].clear();
                int _m = 0, _s = 0;
                int cmp = get<2>(tmp[0]) % 2;
                for (tiii t : tmp) {
                    auto [q, w, e] = t;
                    _m += q;
                    _s += w;
                    if (cmp != e % 2) flag = false;
                }
                _m /= 5;
                _s /= tmp.size();
                if (_m == 0) continue;
                if (flag) {
                    for (int k = 0; k < 4; k++) {
                        v[i][j].push_back({_m, _s, 2 * k});
                    }
                } else {
                    for (int k = 0; k < 4; k++) {
                        v[i][j].push_back({_m, _s, 2 * k + 1});
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        v[r - 1][c - 1].push_back({m, s, d});
    }
    while (k--) {
        move();
        merge();
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto t : v[i][j]) answer += get<0>(t);
        }
    }

    cout << answer << "\n";
}