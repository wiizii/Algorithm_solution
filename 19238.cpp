#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int map[21][21];
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };


struct Guest {
    int sr, sc, dr, dc;
    int dist;
};
bool cmp(Guest& a, Guest& b);
int bfs(int r, int c, int gr, int gc);
struct Taxi {
    int r, c;
    int fuel;
    bool drive(vector<Guest>& g) {
        for (int i = 0; i < g.size(); i++){
            g[i].dist = bfs(r, c, g[i].sr, g[i].sc);
            if(g[i].dist == -1)
                return false;
        }
        sort(g.begin(), g.end(), cmp);
        Guest cur = g.back();
        g.pop_back();
        int tmp =bfs(cur.sr,cur.sc,cur.dr,cur.dc);
        fuel -= (cur.dist + tmp);
        if(fuel < 0)
            return false;
        fuel += tmp*2;
        r = cur.dr; c = cur.dc;
        return true;
    }
};

int bfs(int tr, int tc, int gr, int gc) {
    queue<pair<int, int>> q;
    int check[21][21] = { 0, };
    check[tr][tc] = 0;
    q.push({ tr,tc });
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (r == gr && c == gc)
            return check[r][c];
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 1 || nc < 1 || nr > n || nc > n)
                continue;
            if (!check[nr][nc] && !map[nr][nc]) {
                check[nr][nc] = check[r][c] + 1;
                q.push({ nr,nc });
            }
        }
    }
    return -1;
}

bool cmp(Guest& a, Guest& b) {
    if (a.dist > b.dist)
        return true;
    else if (a.dist == b.dist) {
        if (a.sr > b.sr)
            return true;
        else if (a.sr == b.sr) {
            return a.sc > b.sc;
        }
        else
            return false;
    }
    else
        return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    Taxi taxi;
    vector<Guest> guest;
    cin >> n >> m >> taxi.fuel;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    cin >> taxi.r >> taxi.c;
    for (int i = 0; i < m; i++) {
        int sr, sc, dr, dc;
        cin >> sr >> sc >> dr >> dc;
        guest.push_back({ sr,sc,dr,dc });
    }
    while (guest.size() != 0) {
        if(!taxi.drive(guest)){
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << taxi.fuel << "\n";
    return 0;
}

