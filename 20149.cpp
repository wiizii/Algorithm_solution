#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;

void print_pos(pdd a, pdd b, pdd c, pdd d) {
    double px =
        (a.first * b.second - b.first * a.second) * (c.first - d.first) -
        (a.first - b.first) * (c.first * d.second - c.second * d.first);
    double py =
        (a.first * b.second - b.first * a.second) * (c.second - d.second) -
        (a.second - b.second) * (c.first * d.second - c.second * d.first);
    double p = (a.first - b.first) * (c.second - d.second) -
               (a.second - b.second) * (c.first - d.first);
    if (p == 0) {
        if (b == c && a <= c)
            cout << b.first << " " << b.second << "\n";
        else if (a == d && c <= a)
            cout << a.first << " " << a.second << "\n";
    } else {
        double x = px / p;
        double y = py / p;
        cout << fixed;
        cout.precision(9);
        cout << x << " " << y << "\n";
    }
}

int ccw(pdd p1, pdd p2, pdd p3) {
    double tmp =
        p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    tmp = tmp - p1.second * p2.first - p2.second * p3.first -
          p3.second * p1.first;
    if (tmp > 0)
        return 1;  //반시계
    else if (tmp == 0)
        return 0;  //일직선
    else
        return -1;  //시계
}

//교차검증
void solve(pdd a, pdd b, pdd c, pdd d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);

    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        if (a <= d && b >= c) {
            cout << 1 << "\n";
            print_pos(a, b, c, d);
        } else
            cout << 0 << "\n";
    } else {
        if (abc * abd <= 0 && cda * cdb <= 0) {
            cout << 1 << "\n";
            print_pos(a, b, c, d);
        } else {
            cout << 0 << "\n";
        }
    }
}

int main() {
    pdd p[4];
    for (int i = 0; i < 4; i++) cin >> p[i].first >> p[i].second;
    solve(p[0], p[1], p[2], p[3]);
}