#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[100001];

int main() {
    vector<int> ans;
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << 1 << "\n" << 0 << "\n";
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({n, 0});
    check[n] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int t = q.front().second;
        int next;
        q.pop();
        next = cur + 1;
        if (next == k) ans.push_back(t + 1);
        if (next <= 100000 && !check[next]) {
            check[next] = true;
            q.push({next, t + 1});
        }
        next = cur - 1;
        if (next == k) ans.push_back(t + 1);
        if (0 <= next && !check[next]) {
            check[next] = true;
            q.push({next, t + 1});
        }
        next = cur * 2;
        if (next <= 100000 && !check[next]) {
            check[next] = true;
            q.push({next, t + 1});
        }
        if (next == k) ans.push_back(t + 1);
    }
    int tmp = ans.front();
    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == tmp) sum++;
    }
    cout << tmp << "\n" << sum << "\n";
}