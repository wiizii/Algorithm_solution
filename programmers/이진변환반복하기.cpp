#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int n = 0;
    if (s == "1") return answer;
    for (int i = 0; i < s.size(); i++) s[i] == '0' ? answer[1]++ : n++;
    answer[0]++;
    while (n != 1) {
        int size = 0;
        while (n > 0) {
            n & 1 ? size++ : answer[1]++;
            n >>= 1;
        }
        n = size;
        answer[0]++;
    }
    return answer;
}