#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remain;
    for (int i = 0; i < progresses.size(); i++) {
        int tmp = progresses[i];
        tmp = 100 - tmp;
        if (tmp % speeds[i] == 0)
            tmp /= speeds[i];
        else
            tmp = (tmp / speeds[i]) + 1;
        remain.push_back(tmp);
    }
    int min = remain[0];
    for (int i = 0; i < remain.size(); i++) {
        if (answer.empty())
            answer.push_back(1);
        else {
            if (min < remain[i]) {
                answer.push_back(1);
                min = remain[i];
            } else
                answer.back()++;
        }
    }
    return answer;
}