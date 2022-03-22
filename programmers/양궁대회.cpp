#include <bits/stdc++.h>

using namespace std;

const int MAX = 11;

vector<int> info;
vector<int> answer;
int diff = -1;
bool check[MAX];
int n;

bool cmp(const vector<int> &v) {
    for (int i = MAX - 1; i >= 0; i--) {
        if (answer[i] < v[i]) {
            return false;
        }
        if (answer[i] > v[i]) {
            return true;
        }
    }
}

void solve(int cnt, int idx) {
    int tmp = 0;
    vector<int> v;
    int a = 0, b = 0;
    for (int i = 0; i < MAX; i++) {
        if (check[i]) {
            if (tmp + info[i] + 1 <= n) {
                tmp += info[i] + 1;
                b += 10 - i;
                v.push_back(info[i] + 1);
            } else {
                v.push_back(0);
                if (info[i] != 0) {
                    a += 10 - i;
                }
            }
        } else {
            v.push_back(0);
            if (info[i] != 0) {
                a += 10 - i;
            }
        }
    }
    if (tmp < n) {
        v[10] += n - tmp;
    }
    if (a < b) {
        if (diff < b - a) {
            diff = b - a;
            answer = v;
        } else if (diff == b - a && !answer.empty() && !cmp(v)) {
            answer = v;
        }
    }
    if (cnt == MAX) {
        return;
    }
    for (int i = idx; i < MAX; i++) {
        check[i] = true;
        solve(cnt + 1, i + 1);
        check[i] = false;
    }
}

vector<int> solution(int _n, vector<int> _info) {
    info = _info;
    n = _n;
    solve(0, 0);
    if (diff == -1) {
        answer.push_back(-1);
    }
    return answer;
}