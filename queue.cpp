#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<int> q;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s == "push") {
            int n;
            cin >> n;
            q.push(n);
        } else if (s == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (s == "size") {
            cout << q.size() << "\n";
        } else if (s == "empty") {
            if (q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        } else if (s == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (s == "back") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << "\n";
            }
        }
    }
    return 0;
}
