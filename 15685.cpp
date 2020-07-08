#include <iostream>
#include <vector>
using namespace std;

int map[102][102];
int N,ans;
void draw(vector<pair<int,int>> &v, int cnt){
    map[v[0].first][v[0].second] = 1;
    map[v[1].first][v[1].second] = 1;
    vector<pair<int,int>> tmp;
    for(int i=0;i<cnt;i++){
        tmp = v;
        for(int j=int(tmp.size())-2;j >= 0;j--){
            int x = tmp[j].first - tmp.back().first;
            int y = tmp[j].second - tmp.back().second;
            swap(x,y);
            y *= -1;
            x += tmp.back().first;
            y += tmp.back().second;
            v.push_back({x,y});
            map[x][y] = 1;
        }
    }
}

void find(){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(map[i][j]&&map[i+1][j]&&map[i][j+1]&&map[i+1][j+1])
                ans++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        int x,y,d,g;
        vector<pair<int,int>> pos;
        cin >> x >> y >> d >> g;
        pos.push_back({y,x});
        if(d == 0)
            pos.push_back({y,x+1});
        else if(d == 1)
            pos.push_back({y-1,x});
        else if(d == 2)
            pos.push_back({y,x-1});
        else if(d == 3)
            pos.push_back({y+1,x});
        draw(pos,g);
    }
    find();
    cout << ans << "\n";
}

