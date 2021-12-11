#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

bool check[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int bfs(int x, int y, int m, int n, const vector<vector<int>> &picture) {
    int size = 1;
    queue<pair<int, int>> q;
    check[x][y] = true;
    q.push({x, y});
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (!check[nx][ny]) {
                if (picture[cx][cy] == picture[nx][ny]) {
                    check[nx][ny] = true;
                    q.push({nx, ny});
                    size++;
                }
            }
        }
    }
    return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    memset(check, 0, sizeof(check));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!check[i][j] && picture[i][j]) {
                number_of_area++;
                int size = bfs(i, j, m, n, picture);
                max_size_of_one_area = max(max_size_of_one_area, size);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}