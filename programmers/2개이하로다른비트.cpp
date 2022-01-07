#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n) {
    for (int i = 0; i < 64; i++) {
        ll t = 1L << i;
        ll t1 = 1L << i - 1;
        if ((n & t) == 0) {
            n = n | t;
            if (i != 0 && (n & t1) == t1) n = n ^ t1;
            break;
        }
    }
    return n;
}

vector<long long> solution(vector<long long> numbers) {
    vector<ll> answer;
    for (auto n : numbers) answer.push_back(solve(n));
    return answer;
}