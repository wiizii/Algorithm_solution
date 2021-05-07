#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int key[200001];
int check[200001];
bool isPossible[200001];

void solve(int n) {
    check[n] = 1;
    for (int i = 0; i < adj[n].size(); i++) {
        int next = adj[n][i];
        if (check[next] == 0 && isPossible[next]) {
            if (key[next] != -1) {
                isPossible[key[next]] = true;
                if (check[key[next]] == -1) solve(key[next]);
            }
            solve(next);
        }
        if (check[next] == 0 && !isPossible[next]) {
            check[next] = -1;
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for (int i = 0; i < n; i++) {
        isPossible[i] = true;
        check[i] = 0;
        key[i] = -1;
    }
    for (int i = 0; i < order.size(); i++) {
        key[order[i][0]] = order[i][1];
        isPossible[order[i][1]] = false;
        if (order[i][0] == 0) isPossible[order[i][1]] = true;
        if (order[i][1] == 0) return false;
    }
    for (int i = 0; i < path.size(); i++) {
        adj[path[i][0]].push_back(path[i][1]);
        adj[path[i][1]].push_back(path[i][0]);
    }
    solve(0);
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            answer = false;
            break;
        }
    }
    return answer;
}