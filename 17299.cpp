#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[1000001];
int cnt[1000001];
int ans[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ans, -1, sizeof(ans));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        if (s.empty() || s.top().second >= cnt[arr[i]])
            s.push({i, cnt[arr[i]]});
        else if (s.top().second < cnt[arr[i]]) {
            while (!s.empty() && s.top().second < cnt[arr[i]]) {
                int idx = s.top().first;
                ans[idx] = arr[i];
                s.pop();
            }
            s.push({i, cnt[arr[i]]});
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
