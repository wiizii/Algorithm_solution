#include <string>
#include <vector>
using namespace std;

int arr[102][102];

int rotate(int x1, int y1, int x2, int y2) {
    int ret = arr[x1][y1];
    int tmp = ret;
    for (int i = x1; i < x2; i++) {
        arr[i][y1] = arr[i + 1][y1];
        ret = min(ret, arr[i][y1]);
    }
    for (int i = y1; i < y2; i++) {
        arr[x2][i] = arr[x2][i + 1];
        ret = min(ret, arr[x2][i]);
    }
    for (int i = x2; i > x1; i--) {
        arr[i][y2] = arr[i - 1][y2];
        ret = min(ret, arr[i][y2]);
    }
    for (int i = y2; i > y1; i--) {
        arr[x1][i] = arr[x1][i - 1];
        ret = min(ret, arr[x1][i]);
    }
    arr[x1][y1 + 1] = tmp;
    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int k = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = k;
            k++;
        }
    }
    for (int i = 0; i < queries.size(); i++) {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        int t = rotate(x1, y1, x2, y2);
        answer.push_back(t);
    }
    return answer;
}