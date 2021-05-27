#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
int arr[101][101];
int trace[101][101];

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    trace[i][j] = k;
                }
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void get_trace(int i, int j, vector<int> &v) {
    if (trace[i][j] != 0) {
        get_trace(i, trace[i][j], v);
        v.push_back(trace[i][j]);
        get_trace(trace[i][j], j, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) arr[i][j] = INF;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u][v] = min(arr[u][v], w);
    }
    floyd();
    print();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || arr[i][j] == INF)
                cout << 0 << "\n";
            else {
                vector<int> v;
                v.push_back(i);
                get_trace(i, j, v);
                v.push_back(j);
                cout << v.size() << " ";
                for (auto i : v) cout << i << " ";
                cout << "\n";
            }
        }
    }
}