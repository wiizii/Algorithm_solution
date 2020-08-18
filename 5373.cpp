#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Color { w, y, r, o, g, b };

struct Cube {
    Color U[3][3] = { {w,w,w},
                      {w,w,w},
                      {w,w,w} };
    Color D[3][3] = { {y,y,y},
                      {y,y,y},
                      {y,y,y} };
    Color F[3][3] = { {r,r,r},
                      {r,r,r},
                      {r,r,r} };
    Color B[3][3] = { {o,o,o},
                      {o,o,o},
                      {o,o,o} };
    Color L[3][3] = { {g,g,g},
                      {g,g,g},
                      {g,g,g} };
    Color R[3][3] = { {b,b,b},
                      {b,b,b},
                      {b,b,b} };
    void clk(Color a[3][3]) {
        Color tmp = a[0][0];
        a[0][0] = a[2][0];
        a[2][0] = a[2][2];
        a[2][2] = a[0][2];
        a[0][2] = tmp;
        tmp = a[0][1];
        a[0][1] = a[1][0];
        a[1][0] = a[2][1];
        a[2][1] = a[1][2];
        a[1][2] = tmp;
    }
    void go(string ins) {
        if (ins[0] == 'U') {
            int turn = (ins[1] == '+' ? 1 : 3);
            for (int i = 0; i < turn; i++) {
                clk(U);
                Color t1 = F[0][0], t2 = F[0][1], t3 = F[0][2];
                F[0][0] = R[0][0]; F[0][1] = R[0][1]; F[0][2] = R[0][2];
                R[0][0] = B[0][0]; R[0][1] = B[0][1]; R[0][2] = B[0][2];
                B[0][0] = L[0][0]; B[0][1] = L[0][1]; B[0][2] = L[0][2];
                L[0][0] = t1; L[0][1] = t2; L[0][2] = t3;
            }
        }
        else if (ins[0] == 'D') {
            int turn = (ins[1] == '+' ? 1 : 3);
            for (int i = 0; i < turn; i++) {
                clk(D);
                Color t1 = F[2][0], t2 = F[2][1], t3 = F[2][2];
                F[2][0] = L[2][0]; F[2][1] = L[2][1]; F[2][2] = L[2][2];
                L[2][0] = B[2][0]; L[2][1] = B[2][1]; L[2][2] = B[2][2];
                B[2][0] = R[2][0]; B[2][1] = R[2][1]; B[2][2] = R[2][2];
                R[2][0] = t1; R[2][1] = t2; R[2][2] = t3;
            }
        }
        else if (ins[0] == 'F') {
            int turn = (ins[1] == '+' ? 1 : 3);
            for (int i = 0; i < turn; i++) {
                clk(F);
                Color t1 = U[2][0], t2 = U[2][1], t3 = U[2][2];
                U[2][0] = L[2][2]; U[2][1] = L[1][2]; U[2][2] = L[0][2];
                L[2][2] = D[2][0]; L[1][2] = D[2][1]; L[0][2] = D[2][2];
                D[2][0] = R[0][0]; D[2][1] = R[1][0]; D[2][2] = R[2][0];
                R[0][0] = t1; R[1][0] = t2; R[2][0] = t3;
            }
        }
        else if (ins[0] == 'B') {
            int turn = (ins[1] == '+' ? 1 : 3);
            for (int i = 0; i < turn; i++) {
                clk(B);
                Color t1 = U[0][0], t2 = U[0][1], t3 = U[0][2];
                U[0][0] = R[0][2]; U[0][1] = R[1][2]; U[0][2] = R[2][2];
                R[0][2] = D[0][0]; R[1][2] = D[0][1]; R[2][2] = D[0][2];
                D[0][0] = L[2][0]; D[0][1] = L[1][0]; D[0][2] = L[0][0];
                L[2][0] = t1; L[1][0] = t2; L[0][0] = t3;
            }
        }
        else if (ins[0] == 'L') {
            int turn = (ins[1] == '+' ? 1 : 3);
            for (int i = 0; i < turn; i++) {
                clk(L);
                Color t1 = U[0][0], t2 = U[1][0], t3 = U[2][0];
                U[0][0] = B[2][2]; U[1][0] = B[1][2]; U[2][0] = B[0][2];
                B[2][2] = D[2][2]; B[1][2] = D[1][2]; B[0][2] = D[0][2];
                D[2][2] = F[0][0]; D[1][2] = F[1][0]; D[0][2] = F[2][0];
                F[0][0] = t1; F[1][0] = t2; F[2][0] = t3;
            }
        }
        else if (ins[0] == 'R') {
            int turn = (ins[1] == '+' ? 1 : 3);
            for (int i = 0; i < turn; i++) {
                clk(R);
                Color t1 = U[0][2], t2 = U[1][2], t3 = U[2][2];
                U[0][2] = F[0][2]; U[1][2] = F[1][2]; U[2][2] = F[2][2];
                F[0][2] = D[2][0]; F[1][2] = D[1][0]; F[2][2] = D[0][0];
                D[2][0] = B[2][0]; D[1][0] = B[1][0]; D[0][0] = B[0][0];
                B[2][0] = t1; B[1][0] = t2; B[0][0] = t3;
            }
        }
    }
};

void print(Cube c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (c.U[i][j] == w)
                cout << 'w';
            else if (c.U[i][j] == y)
                cout << 'y';
            else if (c.U[i][j] == r)
                cout << 'r';
            else if (c.U[i][j] == o)
                cout << 'o';
            else if (c.U[i][j] == g)
                cout << 'g';
            else if (c.U[i][j] == b)
                cout << 'b';
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> ins(n);
        for (int i = 0; i < n; i++)
            cin >> ins[i];
        Cube cube;
        for (int i = 0; i < n; i++)
            cube.go(ins[i]);
        print(cube);
    }
    return 0;
}