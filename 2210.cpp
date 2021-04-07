#include <iostream>
#include <set>
#include <string>
using namespace std;

char arr[5][5];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
set<string> st;

void solve(int x, int y, string s, int cnt) {
    if (cnt == 6) {
        st.insert(s);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        solve(nx, ny, s + arr[nx][ny], cnt + 1);
    }
}

int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) cin >> arr[i][j];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) solve(i, j, "", 0);
    cout << st.size() << "\n";
}
