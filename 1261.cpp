#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;

int n,m;
int map[100][100];
int check[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct Pos{
    int x,y,c;
};

void bfs(){
    queue<Pos> q;
    q.push({0,0,0});
    check[0][0] = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int c = q.front().c;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(map[nx][ny]){
                if(check[nx][ny] > c+1){
                    check[nx][ny] = c+1;
                    q.push({nx,ny,c+1});
                }
            }
            else{
                if(check[nx][ny] > c){
                    check[nx][ny] = c;
                    q.push({nx,ny,c});
                }
            }
        }
    }
}

int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf("%1d",&map[i][j]);
            check[i][j] = INF;
        }
    bfs();
    printf("%d\n",check[n-1][m-1]);
    return 0;
}

