#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        if (pq.size() < n)
            pq.push(x);
        else {
            if (pq.top() < x) {
                pq.pop();
                pq.push(x);
            }
        }
    }
    cout << pq.top() << "\n";
}