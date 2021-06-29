#include <bits/stdc++.h>
using namespace std;

double heron(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double getArea(double r, double theta) {
    return pow(r, 2) * theta - pow(r, 2) * sin(theta) * cos(theta);
}

int main() {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double r3 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double size = heron(r1, r2, r3);

    double theta1 = asin((2 * size) / (r1 * r3));
    double theta2 = asin((2 * size) / (r2 * r3));

    double area1 = getArea(r1, theta1);
    double area2 = getArea(r2, theta2);

    cout << fixed;
    cout.precision(3);
    cout << area1 + area2 << "\n";
}