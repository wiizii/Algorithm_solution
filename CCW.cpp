#include <iostream>
using namespace std;

struct vector2 {
    double x, y;
    vector2(double _x, double _y) { x = _x, y = _y; }
    double cross(const vector2 &other) { return x * other.y - y * other.x; }
};

int main() {
    double x0, x1, x2, y0, y1, y2;
    cin >> x0 >> y0;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    vector2 a(x1 - x0, y1 - y0);
    vector2 b(x2 - x1, y2 - y1);
    if (a.cross(b) > 0) cout << 1 << "\n";
    if (a.cross(b) == 0) cout << 0 << "\n";
    if (a.cross(b) < 0) cout << -1 << "\n";
}