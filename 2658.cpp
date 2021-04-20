#include <bits/stdc++.h>
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
            if (arr[i][j] == 1 && isAngle(i, j)) v.push_back({i, j});
    cout << v.size() << endl;
    if (v.size() != 3) {
        cout << 0 << "\n";
        return 0;
    }
    int side[3];
    side[0] =
        pow((v[0].first - v[1].first), 2) + pow((v[0].second - v[1].second), 2);
    side[1] =
        pow((v[1].first - v[2].first), 2) + pow((v[1].second - v[2].second), 2);
    side[2] =
        pow((v[0].first - v[2].first), 2) + pow((v[0].second - v[2].second), 2);

    sort(side, side + 3);
    if (side[0] != side[1] || side[0] == side[2]) {
        cout << 0 << "\n";
        return 0;
    }

    return 0;
}