#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push({-x, i});
        while (pq.top().second < i - l + 1) {
            pq.pop();
        }
        cout << -pq.top().first << " ";
    }
}