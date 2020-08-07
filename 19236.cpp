#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{
    int r,c;
};
struct Fish{
    int n,d;
    bool isAlive;
    Pos p;
};

Fish map[4][4];
Pos dir[9] = {0,0,-1,0,-1,-1,0,-1,1,-1,1,0,1,1,0,1,-1,1};
int ans = 0;

vector<Fish> doMove(int sr,int sc){
    vector<Fish> f(17);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            f[map[i][j].n] = map[i][j];
    for(int i=1;i<=16;i++){
        if(f[i].isAlive){
            int cnt = 8;
            while(cnt--){
                int nr = f[i].p.r + dir[f[i].d].r;
                int nc = f[i].p.c + dir[f[i].d].c;
                if(nr < 0 || nc < 0 || nr >= 4 || nc >= 4 || (nr == sr && nc == sc)){
                    f[i].d = (f[i].d == 8) ? 1 : f[i].d+1;
                    continue;
                }
                int nn = map[nr][nc].n;
                swap(f[i].p,f[nn].p);
                map[f[i].p.r][f[i].p.c] = f[i];
                map[f[nn].p.r][f[nn].p.c] = f[nn];
                break;
            }
        }
    }
    return f;
}

void undoMove(vector<Fish> &f){
    for(int i=1;i<=16;i++)
        map[f[i].p.r][f[i].p.c] = f[i];
}

void solve(int r, int c, int sum, int d,int cnt){
    ans = max(ans,sum);
    vector<Fish> fish(17);
    fish = doMove(r,c);
    for(int i=1;i<=3;i++){
        int nr = r + (i*dir[d].r);
        int nc = c + (i*dir[d].c);
        if(nr < 0 || nc < 0 || nr >= 4 || nc >= 4)
            break;
        if(map[nr][nc].isAlive){
            map[nr][nc].isAlive = false;
            solve(nr,nc,sum+map[nr][nc].n,map[nr][nc].d,cnt+1);
            undoMove(fish);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> map[i][j].n >> map[i][j].d;
            map[i][j].isAlive = true;
            map[i][j].p = {i,j};
        }
    }
    map[0][0].isAlive = false;
    solve(0,0,map[0][0].n,map[0][0].d,0);
    cout << ans << "\n";
    return 0;
}

