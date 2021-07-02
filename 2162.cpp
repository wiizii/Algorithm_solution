#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;

const int MAX = 3001;
pair<pdd, pdd> line[MAX];
int parent[MAX];
int cnt[MAX];

int ccw(pdd p1, pdd p2, pdd p3) {
    double tmp =
        p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    tmp = tmp - p1.second * p2.first - p2.second * p3.first -
          p3.second * p1.first;
    if (tmp > 0)
        return 1;  //반시계
    else if (tmp == 0)
        return 0;  //일직선
    else
        return -1;  //시계
}

//교차검증
bool isOverlap(pdd a, pdd b, pdd c, pdd d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);

    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0;
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (cnt[u] < cnt[v]) swap(u, v);
    parent[v] = u;
    cnt[u] += cnt[v];
    cnt[v] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }
    for (int i = 0; i < n; i++)
        cin >> line[i].first.first >> line[i].first.second >>
            line[i].second.first >> line[i].second.second;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isOverlap(line[i].first, line[i].second, line[j].first,
                          line[j].second)) {
                merge(i, j);
            }
        }
    }
    int answer = 0;
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == i) {
            answer++;
            max_num = max(max_num, cnt[i]);
        }
    }

    cout << answer << "\n" << max_num << "\n";
}