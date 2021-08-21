#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s / n == 0)
        answer.push_back(-1);
    else {
        int sum = (s / n) * n;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) pq.push(-(s / n));
        while (sum != s) {
            int x = -pq.top();
            pq.pop();
            x++;
            sum++;
            pq.push(-x);
        }
        while (!pq.empty()) {
            answer.push_back(-pq.top());
            pq.pop();
        }
    }
    return answer;
}