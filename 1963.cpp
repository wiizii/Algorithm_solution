#include <iostream>
#include <queue>
using namespace std;

int isPrime[10001];

void Eratos(int n) {
    if (n <= 1) return;
    for (int i = 2; i <= n; i++) isPrime[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
    }
}

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    bool check[10001] = {
        0,
    };
    q.push({a, 0});
    check[a] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == b) {
            cout << cnt << "\n";
            return;
        }
        for (int i = 0; i < 10; i++) {
            int nx = (cur / 10) * 10 + i;
            if (!check[nx] && isPrime[nx]) {
                check[nx] = true;
                q.push({nx, cnt + 1});
            }
        }
        for (int i = 0; i < 10; i++) {
            int k = (cur % 10);
            int nx = ((cur / 100) * 100) + (10 * i) + k;
            if (!check[nx] && isPrime[nx]) {
                check[nx] = true;
                q.push({nx, cnt + 1});
            }
        }
        for (int i = 0; i < 10; i++) {
            int k = (cur % 100);
            int nx = ((cur / 1000) * 1000) + (100 * i) + k;
            if (!check[nx] && isPrime[nx]) {
                check[nx] = true;
                q.push({nx, cnt + 1});
            }
        }
        for (int i = 1; i < 10; i++) {
            int k = (cur % 1000);
            int nx = ((cur / 10000) * 10000) + (1000 * i) + k;
            if (!check[nx] && isPrime[nx]) {
                check[nx] = true;
                q.push({nx, cnt + 1});
            }
        }
    }
    cout << "Impossible\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Eratos(10000);
    int t;
    cin >> t;
    while (t--) {
        int p1, p2;
        cin >> p1 >> p2;
        bfs(p1, p2);
    }
}