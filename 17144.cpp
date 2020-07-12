#include <iostream>
using namespace std;

int R,C,T;

int map[51][51];
int diffusion[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int howManyDust(){
    int ans = 0;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(map[i][j] != -1)
                ans+=map[i][j];
    return ans;
}

void DiffuseDust(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j] != -1 && map[i][j] != 0){
                int dust = map[i][j]/5;
                int diffusionCounter = 0;
                for(int k = 0;k < 4;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx < 0 || ny < 0 || nx >= R || ny >= C || map[nx][ny] == -1)
                        continue;
                    diffusionCounter++;
                    diffusion[nx][ny] += dust;
                }
                map[i][j] -= (dust*diffusionCounter);
            }
        }
    }
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            map[i][j] += diffusion[i][j];
            diffusion[i][j] = 0;
        }
}

void freshAir(int up, int down){
    for(int i=up-1;i>0;i--)
        map[i][0] = map[i-1][0];
    for(int i=down+1; i < R-1; i++)
        map[i][0] = map[i+1][0];
    
    for(int j=0;j<C-1;j++){
        map[0][j] = map[0][j+1];
        map[R-1][j] = map[R-1][j+1];
    }
    
    for(int i=0;i<up;i++)
        map[i][C-1] = map[i+1][C-1];
    for(int i=R-1;i > down;i--)
        map[i][C-1] = map[i-1][C-1];
    
    for(int j=C-1;j>1;j--){
        map[up][j] = map[up][j-1];
        map[down][j] = map[down][j-1];
    }
    map[up][1] = map[down][1] = 0;

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int up = 0, down = 0;
    cin >> R >> C >> T;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            cin >> map[i][j];
            if(map[i][j] == -1)
                up == 0 ? up = i : down = i;
        }
    
    for(int i=0;i<T;i++){
        DiffuseDust();
        freshAir(up,down);
    }
    
    cout << howManyDust() << "\n";
    return 0;
}

