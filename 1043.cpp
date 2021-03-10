#include <iostream>
#include <vector>
using namespace std;
vector<int> know;
vector<int> party[51];
int parent[51];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    parent[v] = u;
}

int main() {
    int answer = 0;
    int n, m, k;
    cin >> n >> m;
    cin >> k;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        know.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            party[i].push_back(x);
            merge(party[i][0], x);
        }
    }
    for (int i = 0; i < m; i++) {
        int flag = true;
        for (int j = 0; j < know.size(); j++) {
            if (find(party[i][0]) == find(know[j])) flag = false;
        }
        if (flag) answer++;
    }
    cout << answer << "\n";
}