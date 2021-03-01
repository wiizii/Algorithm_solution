#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define MAX 10001
using namespace std;

int v, e;
int id, d[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCC;
stack<int> s;

// dfs는 총 정점 갯수만큼 실행
int dfs(int x) {
    d[x] = ++id;  //노드마다 고유 번호 할당.
    s.push(x);

    int parent = d[x];
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i];
        if (d[y] == 0)
            parent = min(parent, dfs(y));
        else if (!finished[y])
            parent = min(parent, d[y]);
    }
    if (parent == d[x]) {
        vector<int> scc;
        while (1) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t == x) break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }
    return parent;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= v; i++)
        if (!d[i]) dfs(i);
    sort(SCC.begin(), SCC.end());
    cout << SCC.size() << "\n";
    for (int i = 0; i < SCC.size(); i++) {
        for (int j = 0; j < SCC[i].size(); j++) {
            cout << SCC[i][j] << " ";
        }
        cout << "-1\n";
    }
}
