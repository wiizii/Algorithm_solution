#include <iostream>
#include <deque>
#include <cstring>
#include <vector>
using namespace std;

int N,M,T;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
deque<int> dq[51];
int check[51][51];
vector<int*> change;
bool state = false;

void rotation(int select, bool dir, int cnt){
    while(cnt--){
        if(dir){
            int tmp = dq[select].front();
            dq[select].pop_front();
            dq[select].push_back(tmp);
        }
        else{
            int tmp = dq[select].back();
            dq[select].pop_back();
            dq[select].push_front(tmp);
        }
    }
}

void find(int x, int y){
    check[x][y] = 1;
    change.push_back(&dq[x][y]);
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || nx > N)
            continue;
        if(ny < 0)
            ny = M-1;
        else if(ny >= M)
            ny = 0;
        if(!check[nx][ny] && dq[nx][ny] == dq[x][y])
            find(nx,ny);
    }
}

void modify(){
    if(change.size() > 1){
        for(int i=0;i<change.size();i++)
            *change[i] = 0;
        state |= true;
    }
    change.clear();
}

void arg_modify(){
    double arg = 0;
    int cnt = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            if(dq[i][j]){
                arg+=dq[i][j];
                cnt++;
            }
        }
    }
    arg /= cnt;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            if(dq[i][j]){
                if(arg < dq[i][j])
                    dq[i][j]--;
                else if(arg > dq[i][j])
                    dq[i][j]++;
            }
        }
    }
}

int ans(){
    int sum = 0;
    for(int i=1;i<=N;i++)
        for(int j=0;j<M;j++)
            sum+=dq[i][j];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> T;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int x;
            cin >> x;
            dq[i].push_back(x);
        }
    }
    while(T--){
        int x,d,k;
        cin >> x >> d >> k;
        for(int i=1;i<=N;i++)
            if(i % x == 0)
                rotation(i,d,k);
        memset(check,0,sizeof(check));
        for(int i=1;i<=N;i++)
            for(int j=0;j<M;j++)
                if(!check[i][j] && dq[i][j]){
                    find(i,j);
                    modify();
                }
        if(!state)
            arg_modify();
        state = false;
    }
    cout << ans() << "\n";
}

