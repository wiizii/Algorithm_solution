#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF = 10000000001;

vector<pll> integerPos;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    int n = line.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll ADBC = (ll)line[i][0] * line[j][1] - (ll)line[i][1] * line[j][0];
            if (ADBC == 0) {
                continue;
            }
            ll BFED = (ll)line[i][1] * line[j][2] - (ll)line[i][2] * line[j][1];
            ll ECAF = (ll)line[i][2] * line[j][0] - (ll)line[i][0] * line[j][2];
            if (BFED % ADBC || ECAF % ADBC) {
                continue;
            }
            integerPos.push_back({BFED / ADBC, ECAF / ADBC});
        }
    }

    ll l = INF, r = -INF, u = -INF, d = INF;
    for (int i = 0; i < integerPos.size(); i++) {
        ll &x = integerPos[i].first;
        ll &y = integerPos[i].second;
        l = min(l, x);
        r = max(r, x);
        u = max(u, y);
        d = min(d, y);
    }

    for (int i = 0; i < integerPos.size(); i++) {
        ll &x = integerPos[i].first;
        ll &y = integerPos[i].second;
        x -= l;
        y -= d;
    }

    for (int i = 0; i <= u - d; i++) {
        string tmp = "";
        for (int j = 0; j <= r - l; j++) {
            tmp += ".";
        }
        answer.push_back(tmp);
    }

    for (int i = 0; i < integerPos.size(); i++) {
        auto [x, y] = integerPos[i];
        answer[u - d - y][x] = '*';
    }

    return answer;
}