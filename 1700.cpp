#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int arr[101];
int cnt[101];
bool cur[101];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        cnt[x]++;
    }
    int answer = 0;
    for (int i = 0; i < k; i++) {
        if (cur[arr[i]]) continue;
        if (pq.size() != n) {
            cnt[arr[i]]--;
            pq.push({cnt[arr[i]], arr[i]});
            cur[arr[i]] = true;
        } else {
            answer++;
            cur[pq.top().second] = false;
            pq.pop();
            cnt[arr[i]]--;
            pq.push({cnt[arr[i]], arr[i]});
        }
    }
    cout << answer << "\n";
}