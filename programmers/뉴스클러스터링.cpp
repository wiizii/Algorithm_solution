#include <bits/stdc++.h>

using namespace std;

string toLowerCase(string s) {
    string ret;
    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z')
            ret.push_back(s[i] - 'A' + 'a');
        else
            ret.push_back(s[i]);
    }
    return ret;
}

vector<string> parse(string s) {
    vector<string> ret;
    s = toLowerCase(s);
    for (int i = 0; i < s.size() - 1; i++) {
        string sub = s.substr(i, 2);
        if (islower(sub[0]) && islower(sub[1])) ret.push_back(s.substr(i, 2));
    }
    return ret;
}

map<string, int> getUnion(map<string, int> &m1, map<string, int> &m2) {
    map<string, int> ret;
    for (auto iter = m1.begin(); iter != m1.end(); iter++) {
        auto [key, value] = *iter;
        ret[key] = max(value, ret[key]);
    }
    for (auto iter = m2.begin(); iter != m2.end(); iter++) {
        auto [key, value] = *iter;
        ret[key] = max(value, ret[key]);
    }
    return ret;
}

map<string, int> getIntersection(map<string, int> &m1, map<string, int> &m2) {
    map<string, int> ret;
    for (auto iter = m1.begin(); iter != m1.end(); iter++) {
        auto [key1, value1] = *iter;
        for (auto iter = m2.begin(); iter != m2.end(); iter++) {
            auto [key2, value2] = *iter;
            if (key1 == key2) ret[key1] = min(value1, value2);
        }
    }
    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> parsed1 = parse(str1);
    vector<string> parsed2 = parse(str2);

    map<string, int> m1, m2;

    for (auto s : parsed1) {
        m1[s]++;
    }
    for (auto s : parsed2) {
        m2[s]++;
    }

    map<string, int> unionSet = getUnion(m1, m2);
    map<string, int> intersectionSet = getIntersection(m1, m2);

    double tmp;
    if (unionSet.empty())
        tmp = 1;
    else {
        int a = 0, b = 0;
        for (auto iter = unionSet.begin(); iter != unionSet.end(); iter++) {
            auto [key, value] = *iter;
            a += value;
        }
        for (auto iter = intersectionSet.begin(); iter != intersectionSet.end();
             iter++) {
            auto [key, value] = *iter;
            b += value;
        }
        tmp = (double)b / (double)a;
    }

    answer = tmp * 65536;
    return answer;
}