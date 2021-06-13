#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int map[101][101];
int N, K, L;
struct Command {
    int t;
    char dir;
    Command(int nt, char ndir) {
        t = nt;
        dir = ndir;
    }
};
struct Snake {
    int r, c;
    pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int now = 0;
    deque<pair<int, int>> body;
    Snake() {
        r = 1;
        c = 1;
        body.push_back({r, c});
    }

    bool move() {
        int nr = r + dir[now].first;
        int nc = c + dir[now].second;
        for (int i = 0; i < body.size(); i++)
            if (body[i].first == nr && body[i].second == nc) return 0;
        if (nr < 1 || nc < 1 || nr > N || nc > N) return 0;
        if (map[nr][nc]) {
            body.push_front({nr, nc});
            r = nr;
            c = nc;
            map[nr][nc] = 0;
        } else {
            body.push_front({nr, nc});
            r = nr;
            c = nc;
            body.pop_back();
        }
        return 1;
    }

    void setDir(char c) {
        if (c == 'L') {
            now -= 1;
            if (now < 0) now = 4 + now;
        } else
            now = (now + 1) % 4;
    }
};

queue<Command> command;

int solve() {
    int time = 0;
    Snake snake;
    while (1) {
        time++;
        if (!snake.move()) break;
        if (!command.empty()) {
            if (time == command.front().t) {
                if (command.front().dir == 'L')
                    snake.setDir('L');
                else
                    snake.setDir('R');
                command.pop();
            }
        }
    }
    return time;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int t;
        char dir;
        cin >> t >> dir;
        Command c(t, dir);
        command.push(c);
    }
    cout << solve() << "\n";

    return 0;
}
