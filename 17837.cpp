#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Piece{
    int r,c,dir;
};

int map[22][22];
Piece p[11];
vector<int> order[21][21];
int n,k;
int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};

void pieveMove(int nr, int nc, int i){
    while(1){
        order[nr][nc].push_back(order[p[i].r][p[i].c].back());
        order[p[i].r][p[i].c].pop_back();
        p[order[nr][nc].back()].r = nr;
        p[order[nr][nc].back()].c = nc;
        if(order[nr][nc].back() == i)
            break;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> map[i][j];
    for(int i=1;i<=k;i++){
        cin >> p[i].r >> p[i].c >> p[i].dir;
        order[p[i].r][p[i].c].push_back(i);
    }
    int ans = 1;
    while(ans <= 1000){
        for(int i=1;i<=k;i++){
            int nr = p[i].r + dr[p[i].dir];
            int nc = p[i].c + dc[p[i].dir];
            if(map[nr][nc] == 2 || nr <= 0 || nc <= 0|| nr > n || nc > n){
                if(p[i].dir == 1)
                    p[i].dir = 2;
                else if(p[i].dir == 2)
                    p[i].dir = 1;
                else if(p[i].dir == 3)
                    p[i].dir = 4;
                else if(p[i].dir == 4)
                    p[i].dir = 3;
                nr = p[i].r + dr[p[i].dir];
                nc = p[i].c + dc[p[i].dir];
                if(map[nr][nc] == 1 && nr > 0 && nc > 0 && nr <= n && nc <= n){
                    pieveMove(nr,nc,i);
                }
                else if(map[nr][nc] == 0 && nr > 0 && nc > 0 && nr <= n && nc <= n){
                    int size = (int)order[nr][nc].size();
                    pieveMove(nr,nc,i);
                    reverse(order[nr][nc].begin()+size,order[nr][nc].end());
                }
            }
            else if(map[nr][nc] == 1){
                pieveMove(nr,nc,i);
            }
            else if(map[nr][nc] == 0){
                int size = (int)order[nr][nc].size();
                pieveMove(nr,nc,i);
                reverse(order[nr][nc].begin()+size,order[nr][nc].end());
            }
            if(order[nr][nc].size()>=4){
                cout << ans << "\n";
                return 0;
            }
        }
        ans++;
    }
    cout << -1 << "\n";
    return 0;
}

