#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;

int ccw(pdd p1, pdd p2, pdd p3) {
    double tmp =
        p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    tmp = tmp - p1.second * p2.first - p2.second * p3.first -
          p3.second * p1.first;
    if (tmp > 0)
        return 1;  //반시계
    else if (tmp == 0)
        return 0;  //일직선
    else if (tmp < 0)
        return -1;  //시계
}

bool check(pdd a, pdd b, pdd c, pdd d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);

    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0;
}
