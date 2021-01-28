#include <iostream>
#include <string>
using namespace std;

struct piece {
    string pos;
    void setPos(string p) { pos = p; }
    void move(string op) {
        if (op == "R") {
            if (pos[0] + 1 <= 'H') pos[0]++;
        } else if (op == "L") {
            if (pos[0] - 1 >= 'A') pos[0]--;
        } else if (op == "B") {
            if (pos[1] - 1 >= '1') pos[1]--;
        } else if (op == "T") {
            if (pos[1] + 1 <= '8') pos[1]++;
        } else if (op == "RT") {
            if (pos[0] + 1 <= 'H' && pos[1] + 1 <= '8') pos[0]++, pos[1]++;
        } else if (op == "LT") {
            if (pos[0] - 1 >= 'A' && pos[1] + 1 <= '8') pos[0]--, pos[1]++;
        } else if (op == "RB") {
            if (pos[0] + 1 <= 'H' && pos[1] - 1 >= '1') pos[0]++, pos[1]--;
        } else if (op == "LB") {
            if (pos[0] - 1 >= 'A' && pos[1] - 1 >= '1') pos[0]--, pos[1]--;
        }
    }
};

int main() {
    piece king, stone;
    string p;
    int n;
    cin >> p;
    king.setPos(p);
    cin >> p;
    stone.setPos(p);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string op;
        string ktmp, stmp;
        cin >> op;
        ktmp = king.pos;
        stmp = stone.pos;
        king.move(op);
        if (king.pos == stone.pos) {
            stone.move(op);
            if (stone.pos == stmp) king.pos = ktmp;
        }
    }
    cout << king.pos << "\n" << stone.pos << "\n";
}