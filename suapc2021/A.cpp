#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

vector<ll> v;
vector<char> op;

void parse(string s) {
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '*' && s[i] != '/' && s[i] != '-' && s[i] != '+') {
            tmp += s[i];
        } else {
            v.push_back(stol(tmp));
            tmp = "";
            op.push_back(s[i]);
        }
    }
    v.push_back(stol(tmp));
}

ll cal(ll a, ll b, char op) {
    ll ret = 0;
    if (op == '*')
        ret = a * b;
    else if (op == '/')
        ret = a / b;
    else if (op == '+')
        ret = a + b;
    else if (op == '-')
        ret = a - b;
    return ret;
}

int find_max_idx(vector<pair<ll, char>> t) {
    int ret = 0;
    ll max_num = t[0].first;
    char o = t[0].second;
    for (int i = 0; i < t.size(); i++) {
        if (max_num < t[i].first) {
            max_num = t[i].first;
            o = t[i].second;
            ret = i;
        } else if (max_num == t[i].first) {
            char no = t[i].second;
            if ((o == '+' || o == '-') && (no == '*' || no == '/')) {
                o = no;
                ret = i;
            }
        }
    }
    return ret;
}

int main() {
    string s;
    cin >> s;
    parse(s);
    while (!op.empty()) {
        vector<pair<ll, char>> tmp;
        for (int i = 0; i < op.size(); i++) {
            ll a = v[i], b = v[i + 1];
            char o = op[i];
            tmp.push_back({cal(a, b, o), o});
        }
        int idx = find_max_idx(tmp);
        int max = tmp[idx].first;
        op.erase(op.begin() + idx);
        v.erase(v.begin() + idx);
        v[idx] = max;
    }
    cout << v[0] << "\n";
}