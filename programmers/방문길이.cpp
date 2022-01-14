#include <string>
#include <unordered_set>
using namespace std;

bool check[11][11][11][11];

struct pos {
    int x, y;
};

int solution(string dirs) {
    int answer = 0;
    pos cur = {0, 0};
    for (int i = 0; i < dirs.size(); i++) {
        pos next;
        if (dirs[i] == 'U')
            next = {cur.x, cur.y + 1};
        else if (dirs[i] == 'D')
            next = {cur.x, cur.y - 1};
        else if (dirs[i] == 'R')
            next = {cur.x + 1, cur.y};
        else if (dirs[i] == 'L')
            next = {cur.x - 1, cur.y};
        if (next.x > 5 || next.x < -5 || next.y > 5 || next.y < -5) continue;
        if (!check[cur.x + 5][cur.y + 5][next.x + 5][next.y + 5] &&
            !check[next.x + 5][next.y + 5][cur.x + 5][cur.y + 5])
            answer++;
        check[cur.x + 5][cur.y + 5][next.x + 5][next.y + 5] = true;
        check[next.x + 5][next.y + 5][cur.x + 5][cur.y + 5] = true;
        cur = next;
    }

    return answer;
}