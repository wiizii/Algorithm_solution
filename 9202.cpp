#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

set<string> word;
set<string> found;
char board[4][4];
bool check[4][4];
const int score[8] = {0,0,1,1,2,3,5,11};
const int dx[8] = {-1,-1,-1,1,1,1,0,0};
const int dy[8] = {-1,0,1,-1,0,1,-1,1};

struct Ans{
    int a;
    string s;
    int b;
};

bool cmp(const string &a, const string &b){
    if(a.size() < b.size())
        return true;
    else if(a.size() == b.size()){
        for(int i=0;i<a.size();i++){
            if(a[i] == b[i])
                continue;
            else if(a[i] > b[i])
                return true;
            else
                return false;
        }
        return false;
    }
    else
        return false;
}

Ans ans;

void solve(int x, int y, string w, int cnt){
    w += board[x][y];
    if(word.count(w) && !found.count(w)){
        ans.a += score[cnt];
        if(cmp(ans.s,w))
            ans.s = w;
        ans.b++;
        found.insert(w);
    }
    if(cnt == 8)
        return;
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
            continue;
        if(!check[nx][ny]){
            check[x][y] = true;
            solve(nx,ny,w,cnt+1);
            check[x][y] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string tmp;
    int w;
    cin >> w;
    while(w--){
        string s;
        cin >> s;
        word.insert(s);
    }
    int b;
    cin >> b;
    while(b--){
        ans = {0,"",0};
        found.clear();
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                cin >> board[i][j];
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                check[i][j] = true;
                solve(i,j,"",0);
                check[i][j] = false;
            }
        cout << ans.a << " " << ans.s << " " << ans.b << "\n";
    }
    return 0;
}

