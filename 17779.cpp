#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 0x3f3f3f3f;
int A[20][20];
int N;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

void fill(int x, int y, int n, int arr[20][20]){
    queue<pair<int,int>> q;
    arr[x][y] = n;
    q.push({x,y});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;
            if(!arr[nr][nc]){
                arr[nr][nc] = n;
                q.push({nr,nc});
            }
        }
    }
}

bool makeBoundary(int x, int y, int d1, int d2, int arr[20][20]){
    for(int i=x,j=y;i<=x+d1 && j>=y-d1;i++,j--){
        if(i < 0 || j < 0 || i>=N || j >= N)
            return false;
        arr[i][j] = 5;
    }
    for(int i=x,j=y;i<=x+d2 && j<=y+d2;i++,j++){
        if(i < 0 || j < 0 || i>=N || j >= N)
            return false;
        arr[i][j] = 5;
    }
    for(int i=x+d1,j=y-d1;i<=x+d1+d2 && j<=y-d1+d2;i++,j++){
        if(i < 0 || j < 0 || i>=N || j >= N)
            return false;
        arr[i][j] = 5;
    }
    for(int i=x+d2,j=y+d2;i<=x+d2+d1 && j>=y+d2-d1;i++,j--){
        if(i < 0 || j < 0 || i>=N || j >= N)
            return false;
        arr[i][j] = 5;
    }
    for(int i=x-1;i>=0;i--)
        arr[i][y] = 1;
    for(int i=y+d2+1;i<N;i++)
        arr[x+d2][i] = 2;
    for(int i=y-d1-1;i>=0;i--)
        arr[x+d1][i] = 3;
    for(int i=x+d1+d2+1;i<N;i++)
        arr[i][y+d2-d1] = 4;
    fill(0,0,1,arr);
    fill(0,N-1,2,arr);
    fill(N-1,0,3,arr);
    fill(N-1,N-1,4,arr);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(!arr[i][j])
                arr[i][j] = 5;
    return true;
}

int findAns(int arr[20][20]){
    int p[6] = {0,};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j] == 1)
                p[1] += A[i][j];
            else if(arr[i][j] == 2)
                p[2] += A[i][j];
            else if(arr[i][j] == 3)
                p[3] += A[i][j];
            else if(arr[i][j] == 4)
                p[4] += A[i][j];
            else
                p[5] += A[i][j];
        }
    }
    sort(p,p+6);
    return p[5]-p[1];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int ans = MAX;
    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> A[i][j];
    for(int i=0;i<N-2;i++){
        for(int j=1; j<N-1; j++){
            for(int d1 = 1; d1<=j+1;d1++){
                for(int d2=1;d2<=N-j+1;d2++){
                    int arr[20][20] = {0,};
                    if(makeBoundary(i, j, d1, d2, arr)){
                        ans = min(ans,findAns(arr));
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

