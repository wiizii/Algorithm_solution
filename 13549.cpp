#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int path[MAX + 1];

int solve(int n, int k) {
    priority_queue<pair<int, int>> q;
    path[n] = 0;
    q.push({0, -n});
    while (!q.empty()) {
        int t = -q.top().first;
        int cur = -q.top().second;
        q.pop();
        if (cur * 2 <= MAX && path[cur * 2] == -1) {
            path[cur * 2] = t;
            q.push({-t, -(cur * 2)});
        }
        if (cur - 1 >= 0 && path[cur - 1] == -1) {
            path[cur - 1] = t + 1;
            q.push({-(t + 1), -(cur - 1)});
        }
        if (cur + 1 <= MAX && path[cur + 1] == -1) {
            path[cur + 1] = t + 1;
            q.push({-(t + 1), -(cur + 1)});
        }
    }
    return path[k];
}

int main() {
    int n, k;
    cin >> n >> k;
    memset(path, -1, sizeof(path));
    cout << solve(n, k) << '\n';
    return 0;
}