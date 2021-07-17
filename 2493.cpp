#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;

int arr[MAX];
int ans[MAX];
stack<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = n; i >= 1; i--) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}