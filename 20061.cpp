#include <iostream>
using namespace std;

int blue[4][6], green[6][4];

void make_block(int t, int x, int y, int n) {
    if (t == 1) {
        for (int i = 0; i < 6; i++) {
            if (blue[x][i]) {
                blue[x][i - 1] = n;
                break;
            }
            if (i == 5) blue[x][i] = n;
        }
        for (int i = 0; i < 6; i++) {
            if (green[i][y]) {
                green[i - 1][y] = n;
                break;
            }
            if (i == 5) green[i][y] = n;
        }
    } else if (t == 2) {
        for (int i = 0; i < 6; i++) {
            if (blue[x][i]) {
                blue[x][i - 1] = n;
                blue[x][i - 2] = n;
                break;
            }
            if (i == 5) {
                blue[x][i] = n;
                blue[x][i - 1] = n;
            }
        }
        for (int i = 0; i < 6; i++) {
            if (green[i][y] || green[i][y + 1]) {
                green[i - 1][y] = n;
                green[i - 1][y + 1] = n;
                break;
            }
            if (i == 5) {
                green[i][y] = n;
                green[i][y + 1] = n;
            }
        }
    } else {
        for (int i = 0; i < 6; i++) {
            if (blue[x][i] || blue[x + 1][i]) {
                blue[x][i - 1] = n;
                blue[x + 1][i - 1] = n;
                break;
            }
            if (i == 5) {
                blue[x][i] = n;
                blue[x + 1][i] = n;
            }
        }
        for (int i = 0; i < 6; i++) {
            if (green[i][y]) {
                green[i - 1][y] = n;
                green[i - 2][y] = n;
                break;
            }
            if (i == 5) {
                green[i][y] = n;
                green[i - 1][y] = n;
            }
        }
    }
}

int remove_line() {
    int line = 0;
    for (int j = 5; j > 1; j--) {
        for (int i = 0; i < 4; i++) {
            if (blue[i][j] == 0) break;
            if (i == 3) {
                line++;
                for (int k = j; k >= 0; k--)
                    for (int l = 0; l < 4; l++) blue[l][k] = blue[l][k - 1];
                for (int k = 0; k < 4; k++) blue[k][0] = 0;
                j++;
            }
        }
    }
    for (int i = 5; i > 1; i--) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j] == 0) break;
            if (j == 3) {
                line++;
                for (int k = i; k >= 0; k--)
                    for (int l = 0; l < 4; l++) green[k][l] = green[k - 1][l];
                for (int k = 0; k < 4; k++) green[0][k] = 0;
                i++;
            }
        }
    }
    return line;
}

void move_line() {
    int cnt = 0;
    for (int j = 1; j >= 0; j--) {
        for (int i = 0; i < 4; i++) {
            if (blue[i][j]) {
                cnt++;
                break;
            }
        }
    }
    if (cnt == 1) {
        for (int j = 4; j >= 1; j--) {
            for (int i = 0; i < 4; i++) {
                blue[i][j + 1] = blue[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            blue[i][1] = 0;
        }
    } else if (cnt == 2) {
        for (int j = 3; j >= 0; j--) {
            for (int i = 0; i < 4; i++) {
                blue[i][j + 2] = blue[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            blue[i][0] = blue[i][1] = 0;
        }
    }
    cnt = 0;
    for (int i = 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j]) {
                cnt++;
                break;
            }
        }
    }
    if (cnt == 1) {
        for (int i = 4; i >= 1; i--) {
            for (int j = 0; j < 4; j++) {
                green[i + 1][j] = green[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            green[1][i] = 0;
        }
    } else if (cnt == 2) {
        for (int i = 3; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                green[i + 2][j] = green[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            green[0][i] = green[1][i] = 0;
        }
    }
}

int find_ans2() {
    int num = 0;
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (blue[j][i]) num++;
            if (green[i][j]) num++;
        }
    }
    return num;
}

int main() {
    int n, ans1 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        make_block(t, x, y, i);
        ans1 += remove_line();
        move_line();
    }
    cout << ans1 << "\n" << find_ans2() << "\n";
    return 0;
}
