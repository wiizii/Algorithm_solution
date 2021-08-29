#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<ll, ll> parent;

ll find(ll x) {
    if (parent[x] == 0L) {
        parent[x] = x;
        return x;
    } else if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

void merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x < y) swap(x, y);
    if (x != y) parent[y] = x;
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (ll room : room_number) {
        ll curRoom = find(room);
        ll nextRoom = find(curRoom + 1);
        merge(curRoom, nextRoom);
        answer.push_back(curRoom);
    }

    return answer;
}