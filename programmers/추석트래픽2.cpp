#include <bits/stdc++.h>

using namespace std;

struct info {
    int start;
    int end;
};

vector<info> traffic;

info dateToMillisec(string s) {
    info ret;
    int hour = stoi(s.substr(11, 2)) * 3600000;
    int min = stoi(s.substr(14, 2)) * 60000;
    int sec = stoi(s.substr(17, 2)) * 1000;
    int millisec = stoi(s.substr(20, 3));
    int during = (stod(s.substr(24)) * 1000);
    ret.end = hour + min + sec + millisec;
    ret.start = ret.end - during + 1;
    return ret;
}

int solution(vector<string> lines) {
    int answer = 0;
    for (string line : lines) traffic.push_back(dateToMillisec(line));

    for (int i = 0; i < traffic.size(); i++) {
        int cnt = 0;
        int section = traffic[i].start + 999;
        for (int j = i; j < traffic.size(); j++)
            if (traffic[j].start <= section &&
                traffic[i].start <= traffic[j].end)
                cnt++;
        answer = max(answer, cnt);
    }

    for (int i = 0; i < traffic.size(); i++) {
        int cnt = 0;
        int section = traffic[i].end + 999;
        for (int j = i; j < traffic.size(); j++)
            if (traffic[j].start <= section && traffic[i].end <= traffic[j].end)
                cnt++;
        answer = max(answer, cnt);
    }

    return answer;
}