#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

vector<pair<int,int>> chicken,home;
bool check[14];
int map[51][14];
int N,M;
int ans = 0x3f3f3f3f;

int getAns(){
    int dist = 0;
    for(int i=0;i<home.size();i++){
        int tmp = 0x3f3f3f3f;
        for(int j=0;j<chicken.size();j++){
            if(check[j]){
                int x = abs(home[i].first - chicken[j].first);
                int y = abs(home[i].second - chicken[j].second);
                tmp = min(tmp, x+y);
            }
        }
        if(tmp != 0x3f3f3f3f)
            dist += tmp;
    }
    return dist;
}

void solve(int cnt, int istart){
    if(cnt != 0)
        ans = min(ans,getAns());
    if(cnt == M)
        return;
    
    for(int i = istart; i<chicken.size();i++){
        check[i] = true;
        solve(cnt+1,i+1);
        check[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int x;
            cin >> x;
            if(x == 1)
                home.push_back({i,j});
            else if(x == 2)
                chicken.push_back({i,j});
        }
    }
    solve(0,0);
    cout << ans << "\n";
    return 0;
}

