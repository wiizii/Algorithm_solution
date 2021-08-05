#include <queue>
#include <string>
#include <vector>

using namespace std;

int diff(const string &a, const string &b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i]) cnt++;
    return cnt;
}

int bfs(string begin, int target, vector<int> adj[50], vector<string> words) {
    queue<pair<int, int>> q;
    bool check[50] = {
        0,
    };
    for (int i = 0; i < words.size(); i++) {
        if (diff(begin, words[i]) == 1) {
            q.push({i, 1});
            check[i] = true;
        }
    }
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == target) {
            return cnt;
        }
        for (int i = 0; i < adj[cur].size(); i++) {
            int nword_idx = adj[cur][i];
            if (!check[nword_idx]) {
                check[nword_idx] = true;
                q.push({nword_idx, cnt + 1});
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0, target_idx = -1;
    for (int i = 0; i < words.size(); i++)
        if (target == words[i]) target_idx = i;
    if (target_idx == -1) return 0;
    vector<int> adj[50];
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (i == j) continue;
            if (diff(words[i], words[j]) == 1) adj[i].push_back(j);
        }
    }
    answer = bfs(begin, target_idx, adj, words);
    return answer;
}