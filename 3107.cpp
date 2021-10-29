#include <bits/stdc++.h>
using namespace std;

int getDoubleColon(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == ':' && s[i + 1] == ':') {
            return i;
        }
    }
    return -1;
}

vector<string> getToken(string s) {
    vector<string> token;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ':') {
            token.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    token.push_back(tmp);
    return token;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    vector<string> token = getToken(s);
    int size = 8 - token.size() + 1;
    for (int i = 0; i < token.size(); i++) {
        if (token[i] == "" && token[i + 1] == "") {
            size++;
        }
        if (token[i] == "") {
            string tmp = "";
            for (int i = 0; i < size; i++) {
                tmp += "0000:";
            }
            tmp.pop_back();
            token[i] = tmp;
            if (token[i + 1] == "") {
                i++;
            }
        } else {
            while (token[i].size() < 4) {
                token[i] = "0" + token[i];
            }
        }
    }
    string answer = "";
    for (int i = 0; i < token.size(); i++) {
        if (token[i] == "") continue;
        answer += token[i] + ':';
    }
    answer.pop_back();
    cout << answer << '\n';
    return 0;
}
