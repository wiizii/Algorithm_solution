#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int score[5] = {0, 1, 10, 100, 1000};
int n;
vector<int> v[401];
map<int, pii> m;
int board[21][21];

int getSize(pii p) {
    int ret = 0;
    auto [x, y] = p;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (!board[nx][ny]) ret++;
    }
    return ret;
}

bool cmp(const pii &a, const pii &b) {
    int aSize = getSize(a);
    int bSize = getSize(b);
    if (aSize > bSize)
        return true;
    else if (aSize == bSize)
        if (a.first < b.first)
            return true;
        else if (a.first == b.first)
            return a.second < b.second;
        else
            return false;
    else
        return false;
}

pii findPos(int x) {
    vector<pii> candidate;
    for (int &fre : v[x]) {
        if (m.count(fre)) {
            auto [fx, fy] = m[fre];
            for (int i = 0; i < 4; i++) {
                int nx = fx + dx[i];
                int ny = fy + dy[i];
                if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny])
                    continue;
                candidate.push_back({nx, ny});
            }
        }
    }
    if (candidate.empty()) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j]) continue;
                candidate.push_back({i, j});
            }
        }
    }
    sort(candidate.begin(), candidate.end(), cmp);

    return candidate[0];
}

int getAnswer() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vector<int> fre = v[board[i][j]];
            int tmp = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                for (int l = 0; l < 4; l++)
                    if (fre[l] == board[nx][ny]) tmp++;
            }
            ret += score[tmp];
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 4; j++) {
            int y;
            cin >> y;
            v[x].push_back(y);
        }
        auto [nx, ny] = findPos(x);
        m[x] = {nx, ny};
        board[nx][ny] = x;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << getAnswer() << "\n";
}