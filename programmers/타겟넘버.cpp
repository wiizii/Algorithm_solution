#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> &a, int sum, int target, int &ans, int cnt) {
    if (cnt == a.size()) {
        if (sum == target) ans++;
        return;
    }
    dfs(a, sum + a[cnt], target, ans, cnt + 1);
    dfs(a, sum - a[cnt], target, ans, cnt + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, target, answer, 0);
    return answer;
}