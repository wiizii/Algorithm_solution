#include <cstring>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

const int MAX = 20001;
int n;
int trace[MAX];
bool check[MAX];
map<int, char> m;

void bfs() {
    queue<int> q;
    q.push(1);
    trace[1] = -1;
    check[1] = true;
    m[1] = '1';
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int next = (cur * 10 + i) % n;
            if (!check[next]) {
                trace[next] = cur;
                check[next] = true;
                m[next] = '0' + i;
                if (next == 0) return;
                q.push(next);
            }
        }
    }
}

void print(int num) {
    if (num == -1) return;
    print(trace[num]);
    cout << m[num];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(check, 0, sizeof(check));
        memset(trace, 0, sizeof(trace));
        cin >> n;
        bfs();
        print(0);
        cout << "\n";
    }
}