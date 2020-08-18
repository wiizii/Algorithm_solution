#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Map {
    int idx, black, point, blue = -1;
};
Map map[100] = {
    {0, 1, 0},
    {1, 2, 2},
    {2, 3, 4},
    {3, 4, 6},
    {4, 5, 8},
    {5, 6, 10, 21},  //5
    {6, 7, 12},
    {7, 8, 14},
    {8, 9, 16},
    {9, 10, 18},
    {10, 11, 20, 25},  //10
    {11, 12, 22},
    {12, 13, 24},
    {13, 14, 26},
    {14, 15, 28},
    {15, 16, 30, 27},  //15
    {16, 17, 32},
    {17, 18, 34},
    {18, 19, 36},
    {19, 20, 38},
    {20, 32, 40},  //20
    {21, 22, 13},
    {22, 23, 16},
    {23, 24, 19},
    {24, 30, 25},  // 24: 25점 짜리 가운데꺼
    {25, 26, 22},
    {26, 24, 24},
    {27, 28, 28},
    {28, 29, 27},
    {29, 24, 26},
    {30, 31, 30},
    {31, 20, 35},
    {32, -1, 0},  // 32: 도착
};

struct Piece{
    int pos, sum;
    void move(int d){
        for(int i=0;i<d;i++){
            if(i == 0 && map[pos].blue != -1){
                pos = map[pos].blue;
                continue;
            }
            if(pos != 32)
                pos = map[pos].black;
            else
                break;
        }
        sum += map[pos].point;
    }
};

Piece p[4];
int dice[10];
int ans = 0;

bool check(int cur){
    for(int i=0;i<4;i++){
        if(i == cur)
            continue;
        if(p[cur].pos != 32 && p[cur].pos == p[i].pos)
            return false;
    }
    return true;
}

void solve(int cnt) {
    if (cnt == 10){
        ans = max(ans,p[0].sum + p[1].sum + p[2].sum + p[3].sum);
        return;
    }
    for(int i=0; i<4;i++){
        if(p[i].pos == 32)
            continue;
        Piece tmp = p[i];
        p[i].move(dice[cnt]);
        if(check(i)){
            solve(cnt+1);
        }
        p[i] = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 10; i++)
        cin >> dice[i];
    for(int i=0;i<4;i++)
        p[i].pos = p[i].sum = 0;
    solve(0);
    cout << ans << "\n";
    return 0;
}

