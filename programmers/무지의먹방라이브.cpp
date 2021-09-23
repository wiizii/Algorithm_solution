#include <bits/stdc++.h>
#define ll long long

using namespace std;
using pll = pair<ll, ll>;

priority_queue<pll, vector<pll>, greater<pll>> pq;

int solution(vector<int> food_times, ll k) {
    ll acc = 0;
    for (int i = 0; i < food_times.size(); i++) {
        acc += food_times[i];
        pq.push({food_times[i], i + 1});
    }

    if (acc <= k) return -1;
    ll prev = 0;
    while ((pq.top().first - prev) * pq.size() <= k) {
        k -= (pq.top().first - prev) * pq.size();
        prev = pq.top().first;
        pq.pop();
    }
    vector<pll> tmp;
    while (!pq.empty()) {
        tmp.push_back({pq.top().second, pq.top().first});
        pq.pop();
    }

    sort(tmp.begin(), tmp.end());
    return tmp[k % tmp.size()].first;
}