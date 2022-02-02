#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for (int i = 3; i * i <= sum; i++) {
        if (sum % i == 0) {
            int row = sum / i;
            int col = i;
            if ((row - 2) * (col - 2) == yellow) {
                answer.push_back(row);
                answer.push_back(col);
                break;
            }
        }
    }
    return answer;
}