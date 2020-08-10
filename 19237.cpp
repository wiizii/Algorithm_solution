#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int DEAD = 0x3f3f3f3f;
int N,M,K;

struct Trace{
    int n,t;
};
struct Pos{
    int r,c;
};

Pos pos[5] = {0,0,-1,0,1,0,0,-1,0,1};
Trace map[20][20];

struct Shark{
    int n,r,c,d;
    int dir[5][5];
    void move(){
        for(int i=1;i<=4;i++){
            int cd = dir[d][i];
            int nr = r + pos[cd].r;
            int nc = c + pos[cd].c;
            if(nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;
            if(!map[nr][nc].n){
                r = nr; c = nc; d = cd;
                return;
            }
        }
        for(int i=1;i<=4;i++){
            int cd = dir[d][i];
            int nr = r + pos[cd].r;
            int nc = c + pos[cd].c;
            if(nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;
            if(map[nr][nc].n == n){
                r = nr; c = nc; d = cd;
                return;
            }
        }
    }
};

vector<Shark> shark;

bool cmp(const Shark &a, const Shark &b){
    return a.n < b.n;
}

void smell_module(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j].n != 0){
                map[i][j].t--;
                if(map[i][j].t == 0)
                    map[i][j].n = 0;
            }
        }
    }
    for(int i=0;i<shark.size();i++){
        map[shark[i].r][shark[i].c].t = K;
    }
}

void shark_move(){
    bool flag = false;
    for(int i=0;i<shark.size();i++)
        shark[i].move();
    for(int i=0;i<shark.size();i++){
        int r = shark[i].r;
        int c = shark[i].c;
        if(map[r][c].n == 0 || map[r][c].n == shark[i].n){
            map[r][c].n = shark[i].n;
            map[r][c].t = K;
        }
        else if(map[r][c].n != 0){
            flag = true;
            shark[i].n = DEAD;
        }
    }
    if(flag){
        sort(shark.begin(),shark.end(),cmp);
        while(1){
            if(shark.back().n == DEAD)
                shark.pop_back();
            else
                break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j].n;
            if(map[i][j].n){
                map[i][j].t = K;
                shark.push_back({map[i][j].n,i,j});
            }
        }
    }
    
    sort(shark.begin(),shark.end(),cmp);
    
    for(int i=0;i<M;i++)
        cin >> shark[i].d;

    for(int k=0;k<M;k++)
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
                cin >> shark[k].dir[i][j];
    
    int ans = 1;
    while(ans <= 1000){
        shark_move();
        smell_module();
        if(shark.size() == 1){
            cout << ans << "\n";
            return 0;
        }
        ans++;
    }
    cout << -1 << "\n";
    return 0;
}

