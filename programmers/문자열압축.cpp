#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0x3f3f3f3f;
    for (int i = 1; i <= s.size(); i++) {
        vector<pair<string, int>> v;
        for (int j = 0; j <= s.size() - i; j += i) {
            if (!v.empty() && v.back().first == s.substr(j, i))
                v.back().second++;
            else
                v.push_back({s.substr(j, i), 1});
        }
        string tmp = "";
        for (int j = 0; j < v.size(); j++) {
            if (v[j].second == 1)
                tmp += v[j].first;
            else
                tmp += to_string(v[j].second) + v[j].first;
        }
        int cnt = tmp.size();
        if (s.size() % i != 0) cnt += s.size() % i;
        answer = min(answer, cnt);
    }
    return answer;
}