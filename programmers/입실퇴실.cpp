#include <bits/stdc++.h>

using namespace std;

set<int> s;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer(enter.size(), 0);
    int j = 0;
    for (int i = 0; i < enter.size(); i++) {
        while (j < leave.size()) {
            if (s.count(leave[j]))
                s.erase(leave[j++]);
            else
                break;
        }
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            answer[*iter - 1]++;
        }
        answer[enter[i] - 1] += s.size();
        s.insert(enter[i]);
    }
    return answer;
}