#include <string>
#include <vector>

using namespace std;

struct pos {
    int x, y;
};

pos dir[3] = {1, 0, 0, 1, -1, -1};

vector<int> solution(int n) {
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    vector<int> answer;
    int size = n;
    pos p = {-1, 0};
    int d = 0;
    int cnt = 1;
    while (size > 0) {
        for (int i = 0; i < size; i++) {
            p.x += dir[d].x;
            p.y += dir[d].y;
            v[p.x][p.y] = cnt;
            cnt++;
        }
        d = (d + 1) % 3;
        size--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}