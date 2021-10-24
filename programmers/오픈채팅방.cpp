#include <bits/stdc++.h>

using namespace std;

vector<string> parse(string s) {
    vector<string> ret;
    string a = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            a += s[i];
        } else {
            ret.push_back(a);
            a = "";
        }
    }
    ret.push_back(a);
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> info;
    map<string, string> id;
    for (int i = 0; i < record.size(); i++) {
        vector<string> cmd = parse(record[i]);
        if (cmd[0] == "Enter") {
            info.push_back({cmd[0], cmd[1]});
            id[cmd[1]] = cmd[2];
        } else if (cmd[0] == "Leave") {
            info.push_back({cmd[0], cmd[1]});
        } else {
            id[cmd[1]] = cmd[2];
        }
    }
    for (auto aInfo : info) {
        auto [type, uid] = aInfo;
        if (type == "Enter")
            answer.push_back(id[uid] + "님이 들어왔습니다.");
        else
            answer.push_back(id[uid] + "님이 나갔습니다.");
    }
    return answer;
}