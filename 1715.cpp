#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(-x);
    }
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    while (1) {
        int x = -pq.top();
        pq.pop();
        int y = -pq.top();
        pq.pop();
        sum += x + y;
        if (pq.empty()) break;
        pq.push(-(x + y));
    }
    cout << sum << "\n";
}