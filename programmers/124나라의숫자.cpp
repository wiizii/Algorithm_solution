#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n > 0) {
        if (n % 3 == 0) {
            answer += "4";
            n = n / 3 - 1;
        } else {
            answer += to_string(n % 3);
            n /= 3;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}