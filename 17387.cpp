#include <iostream>
using namespace std;

struct vector2 {
    double x, y;
    vector2(double _x, double _y) { x = _x, y = _y; }
    double cross(const vector2 &other) { return x * other.y - y * other.x; }
};

int main() {
    double x0, x1, x2, x3, y0, y1, y2, y3;
    cin >> x0 >> y0;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    vector2 AB(x1 - x0, y1 - y0);
    vector2 BC(x2 - x1, y2 - y1);
    vector2 BD(x3 - x1, y3 - y1);
    vector2 CD(x3 - x2, y3 - y2);
    vector2 DA(x0 - x3, y0 - y3);
    vector2 DB(x1 - x3, y1 - y3);

    if (AB.cross(BC) * AB.cross(BD) < 0 && CD.cross(DA) * CD.cross(DB) < 0)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}