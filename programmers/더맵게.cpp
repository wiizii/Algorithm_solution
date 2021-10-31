#include <queue>
#include <string>
#include <vector>

using namespace std;

priority_queue<long long> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++) pq.push(-(long long)scoville[i]);
    while (-pq.top() < K && pq.size() > 1) {
        long long first = -pq.top();
        pq.pop();
        long long second = -pq.top();
        pq.pop();
        long long mix = first + (second * 2);
        pq.push(-mix);
        answer++;
    }
    if (pq.size() == 1 && -pq.top() < K) answer = -1;
    return answer;
}