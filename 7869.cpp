#include <bits/stdc++.h>
using namespace std;

double get_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double get_area(double r, double theta) {
    return (r * r * 2 * theta) / 2 - r * r * sin(2 * theta) / 2;
}

int main() {
    double x1, y1, r1, x2, y2, r2;
    double theta1, theta2;
    double area = 0;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if (r1 < r2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }

    double d = get_dist(x1, y1, x2, y2);

    if (r1 - r2 < d && d < r1 + r2) {
        theta1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        theta2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
        area = get_area(r1, theta1) + get_area(r2, theta2);
    } else if (d <= r1 - r2) {
        area = r2 * r2 * M_PI;
    }
    cout << fixed;
    cout.precision(3);
    cout << area << "\n";
}