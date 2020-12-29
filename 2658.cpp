#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int arr[12][12];

bool isAngle(int i, int j) {
    int cnt = 0;
    if (!arr[i + 1][j]) cnt++;
    if (!arr[i][j + 1]) cnt++;
    if (!arr[i - 1][j]) cnt++;
    if (!arr[i][j - 1]) cnt++;
    if (cnt == 3)
        return true;
    else
        return false;
}

int main() {
    vector<pair<int, int>> v;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) scanf("%1d", &arr[i][j]);

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (isAngle(i, j)) v.push_back({i, j});

    return 0;
}