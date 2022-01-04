#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<string> s;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    int start = words[0].back();
    s.insert(words[0]);
    for (int i = 1; i < words.size(); i++) {
        if (start == words[i].front() && !s.count(words[i])) {
            start = words[i].back();
            s.insert(words[i]);
        } else {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }
    }

    return answer;
}