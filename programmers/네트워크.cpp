#include <string>
#include <vector>

using namespace std;

void dfs(int start, vector<vector<int>> computers, bool check[200]) {
    check[start] = true;
    for (int i = 1; i < computers[start].size(); i++) {
        bool connected = computers[start][i];
        if (connected && !check[i]) dfs(i, computers, check);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool check[200] = {
        false,
    };
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            dfs(i, computers, check);
            answer++;
        }
    }
    return answer;
}