#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool cmp(const int &a, const int &b) { return a > b; }

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    vector<int> order;
    for (int i = 0; i < priorities.size(); i++) q.push({i, priorities[i]});
    sort(priorities.begin(), priorities.end(), cmp);
    int i = 0;
    while (!q.empty()) {
        if (q.front().second == priorities[i]) {
            order.push_back(q.front().first);
            q.pop();
            i++;
        } else {
            q.push(q.front());
            q.pop();
        }
    }
    for (int i = 0; i < order.size(); i++) {
        if (order[i] == location) answer = i + 1;
    }
    return answer;
}