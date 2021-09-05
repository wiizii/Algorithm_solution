#include <bits/stdc++.h>

using namespace std;

vector<int> v;
map<int, vector<int>> info;

string int_to_time(const int &a) {
    string tmp = "";
    string h = to_string(a / 60);
    string m = to_string(a % 60);
    if (h.size() == 1) h = "0" + h;
    if (m.size() == 1) m = "0" + m;
    return h + ":" + m;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    for (auto s : timetable) {
        int hour, min;
        sscanf(s.c_str(), "%d:%d", &hour, &min);
        v.push_back(hour * 60 + min);
    }
    sort(v.begin(), v.end());
    int start = 540;
    for (int i = 0; i < v.size(); i++) {
        while (info[start].size() >= m || start < v[i]) start += t;
        info[start].push_back(v[i]);
    }
    int last = 540 + t * (n - 1);
    vector<int> cur = info[last];
    if (cur.size() < m)
        answer = int_to_time(last);
    else
        answer = int_to_time(cur.back() - 1);

    return answer;
}