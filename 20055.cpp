#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, k;
deque<pii> dq;

void one() {
    dq.push_front(dq.back());
    dq.pop_back();
    if (dq[n - 1].first == 1) dq[n - 1].first = 0;
}
void two() {
    for (int i = n - 1; i >= 1; i--) {
        if (dq[i].first == 0 && dq[i].second != 0 && dq[i - 1].first == 1) {
            dq[i].first = 1;
            dq[i].second--;
            dq[i - 1].first = 0;
        }
    }
    if (dq[n - 1].first == 1) dq[n - 1].first = 0;
}
void three() {
    if (dq[0].first != 1 && dq[0].second != 0) {
        dq[0].first = 1;
        dq[0].second--;
    }
}
bool four() {
    int tmp = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (dq[i].second == 0) tmp++;
    }
    return tmp >= k ? true : false;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i++) {
        int d;
        cin >> d;
        dq.push_back({0, d});
    }
    int answer = 0;
    while (1) {
        answer++;
        one();
        two();
        three();
        if (four()) break;
    }
    cout << answer << "\n";
}