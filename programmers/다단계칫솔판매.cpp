#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, string> 다단계;
map<string, int> 돈;

vector<int> solution(vector<string> enroll, vector<string> referral,
                     vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++) {
        다단계[enroll[i]] = referral[i];
        돈[enroll[i]] = 0;
    }
    for (int i = 0; i < seller.size(); i++) {
        string 사람 = seller[i];
        int 번돈 = 100 * amount[i];
        while (사람 != "-") {
            int 십퍼 = 번돈 / 10;
            돈[사람] += 번돈 - 십퍼;
            번돈 = 십퍼;
            사람 = 다단계[사람];
        }
    }
    for (int i = 0; i < enroll.size(); i++) answer.push_back(돈[enroll[i]]);
    return answer;
}