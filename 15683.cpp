#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map(8,vector<int>(8,0));
vector<pair<int,int>> posOfCCTV;
vector<vector<int>> state(8,vector<int>(8,0));
int N, M;
int ans = 100;
int numOfCCTV = 0;


void RIGHT(int x, int y){
    for(int i = y + 1;i < M; i++){
        if(state[x][i] == 6)
            return;
        else if(!state[x][i])
            state[x][i] = -1;
    }
}

void UP(int x, int y){
    for(int i = x - 1;i >= 0; i--){
        if(state[i][y] == 6)
            return;
        else if(!state[i][y])
            state[i][y] = -1;
    }
}
void LEFT(int x, int y){
    for(int i = y - 1;i >= 0; i--){
        if(state[x][i] == 6)
            return;
        else if(!state[x][i])
            state[x][i] = -1;
    }
}

void DOWN(int x, int y){
    for(int i = x + 1;i < N; i++){
        if(state[i][y] == 6)
            return;
        else if(!state[i][y])
            state[i][y] = -1;
    }
}

int COUNT(vector<vector<int>> v){
    int cnt = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(v[i][j] == 0)
                cnt++;
    return cnt;
}

void solve(int cnt, vector<vector<int>> cur){
    if(cnt == numOfCCTV){
        ans = min(ans,COUNT(cur));
        return;
    }
    int x = posOfCCTV[cnt].first;
    int y = posOfCCTV[cnt].second;
    int CCTV = map[x][y];
    if(CCTV == 1){
        state = cur;
        RIGHT(x,y);
        solve(cnt+1,state);
        state = cur;
        UP(x,y);
        solve(cnt+1,state);
        state = cur;
        LEFT(x,y);
        solve(cnt+1,state);
        state = cur;
        DOWN(x,y);
        solve(cnt+1,state);
    }
    else if(CCTV == 2){
        state = cur;
        RIGHT(x,y);
        LEFT(x,y);
        solve(cnt+1,state);
        state = cur;
        UP(x,y);
        DOWN(x,y);
        solve(cnt+1,state);
    }
    else if(CCTV == 3){
        state = cur;
        RIGHT(x,y);
        UP(x,y);
        solve(cnt+1,state);
        state = cur;
        UP(x,y);
        LEFT(x,y);
        solve(cnt+1,state);
        state = cur;
        LEFT(x,y);
        DOWN(x,y);
        solve(cnt+1,state);
        state = cur;
        DOWN(x,y);
        RIGHT(x,y);
        solve(cnt+1,state);
    }
    else if(CCTV == 4){
        state = cur;
        RIGHT(x,y);
        UP(x,y);
        LEFT(x,y);
        solve(cnt+1,state);
        state = cur;
        UP(x,y);
        LEFT(x,y);
        DOWN(x,y);
        solve(cnt+1,state);
        state = cur;
        LEFT(x,y);
        DOWN(x,y);
        RIGHT(x,y);
        solve(cnt+1,state);
        state = cur;
        DOWN(x,y);
        RIGHT(x,y);
        UP(x,y);
        solve(cnt+1,state);
    }
    else if(CCTV == 5){
        state = cur;
        RIGHT(x,y);
        UP(x,y);
        LEFT(x,y);
        DOWN(x,y);
        solve(cnt+1,state);
    }
    
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int x;
            cin >> x;
            map[i][j] = x;
            if(x == 1 || x == 2 || x == 3 || x == 4 || x == 5){
                numOfCCTV++;
                posOfCCTV.push_back({i,j});
            }
        }
    }

    solve(0,map);
    cout << ans << "\n";
    return 0;
}

