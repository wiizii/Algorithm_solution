#include <bits/stdc++.h>

using namespace std;

char c[5] = {'A', 'E', 'I', 'O', 'U'};
string word = "";
string str = "";
int cnt = 0;
int answer = 0;

void solve() {
    if (str == word) {
        answer = cnt;
        return;
    }
    cnt++;
    if (str.size() == 5) return;
    for (int i = 0; i < 5; i++) {
        str.push_back(c[i]);
        solve();
        str.pop_back();
    }
}

int solution(string w) {
    word = w;
    solve();
    return answer;
}