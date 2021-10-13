#include <bits/stdc++.h>
using namespace std;

string bfs(string s, int k) {
    queue<string> q;
    int m = s.size();
    int cnt = 0;
    string ret = "-1";
    q.push(s);

    while (!q.empty() && cnt < k) {
        int size = q.size();
        set<string> visited;
        for (int t = 0; t < size; t++) {
            string cur = q.front();
            q.pop();
            for (int i = 0; i < m - 1; i++) {
                for (int j = i + 1; j < m; j++) {
                    if (i == 0 && cur[j] == '0') continue;
                    swap(cur[i], cur[j]);
                    if (!visited.count(cur)) {
                        if (cnt == k - 1) ret = max(ret, cur);
                        q.push(cur);
                        visited.insert(cur);
                    }
                    swap(cur[i], cur[j]);
                }
            }
        }
        cnt++;
    }
    if (cnt != k)
        return "-1";
    else
        return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int k;
    cin >> s >> k;

    cout << bfs(s, k) << "\n";
    return 0;
}