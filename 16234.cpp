#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,L,R;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int map[51][51];
int check[51][51];
int flag = 1;
vector<pair<int,int>> v;

int abs(int a){
    return a >= 0 ? a : -a;
}

void dfs(int x,int y){
    check[x][y] = 1;
    v.push_back({x,y});
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if(!check[nx][ny]){
            int diff = abs(map[nx][ny]-map[x][y]);
            if(diff >= L && diff <= R)
               dfs(nx,ny);
        }
    }
}

void move(){
    if(v.size() != 1)
        flag = 1;
    int sum = 0;
    for(int i=0;i<v.size();i++){
        int x = v[i].first; int y = v[i].second;
        sum+=map[x][y];
    }
    int population = sum/v.size();
    for(int i=0;i<v.size();i++){
        int x = v[i].first; int y = v[i].second;
        map[x][y] = population;
    }
    v.clear();
}

int main(){
    int ans;
    cin >> N >> L >> R;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> map[i][j];

    for(ans = -1;flag;ans++){
        flag = 0;
        memset(check,0,sizeof(check));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!check[i][j]){
                    dfs(i,j);
                    move();
                }
            }
        }
    }
    cout << ans << "\n";
}

