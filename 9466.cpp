#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int cnt;
int arr[100001];
bool visit[100001];
bool done[100001];

stack<int> s;

void find_cycle(int start) {
    visit[start] = true;
    int next = arr[start];
    if (!visit[next])
        find_cycle(next);
    else if (!done[next]) {
        while (next != start) {
            cnt++;
            next = arr[next];
        }
        cnt++;
    }
    done[start] = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(visit, 0, sizeof(visit));
        memset(done, 0, sizeof(done));
        cnt = 0;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++)
            if (!visit[i]) find_cycle(i);
        cout << n - cnt << "\n";
    }
}