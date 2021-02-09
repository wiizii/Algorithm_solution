#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[100001];

int main() {
    int n, k;
    int minSec = 0;
    int cnt = 0;
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push({n, 0});
    check[n] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int t = q.front().second;
        q.pop();
        check[cur] = true;
        if (minSec && minSec == t && cur == k) cnt++;
        if (!minSec && cur == k) {
            minSec = t;
            cnt++;
        }
        if (cur + 1 <= 100000 && !check[cur + 1]) q.push({cur + 1, t + 1});
        if (0 <= cur - 1 && !check[cur - 1]) q.push({cur - 1, t + 1});
        if (cur * 2 <= 100000 && !check[cur * 2]) q.push({cur * 2, t + 1});
    }
    cout << minSec << "\n" << cnt << "\n";
}