#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int R,C,M;
int map[102][102];
int ans=0;

struct Shark{
    int r,c,s,d,z;
    void move(){
        if(d == 1 || d == 2){
            for(int i=0;i<s;i++){
                if(r == 1)
                    d = 2;
                else if(r == R)
                    d = 1;
                d == 1 ? r-- : r++;
            }
        }
        else if(d == 3 || d == 4){
            for(int i=0;i<s;i++){
                if(c == 1)
                    d = 3;
                else if(c == C)
                    d = 4;
                d == 3 ? c++ : c--;
            }
        }
    }
};

bool cmp(const Shark &a, const Shark &b){
    return a.z > b.z;
}

void catch_shark(int pos,vector<Shark> &s){
    for(int i=1;i<=R;i++){
        if(map[i][pos]){
            int tmp = map[i][pos]-1;
            ans += s[tmp].z;
            s.erase(s.begin()+tmp);
            return;
        }
    }
}

void shark_move(vector<Shark> &s){
    vector<Shark> tmp;
    memset(map,0,sizeof(map));
    sort(s.begin(),s.end(),cmp);
    for(auto it=s.begin();it < s.end();it++){
        auto now = *it;
        now.move();
        int &p = map[now.r][now.c];
        if(!p){
            tmp.push_back(now);
            p = true;
        }
    }
    s = tmp;
    memset(map,0,sizeof(map));
    for(int i=0;i<s.size();i++)
        map[s[i].r][s[i].c] = i+1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> R >> C >> M;
    vector<Shark> s(M);
    for(int i=0;i<M;i++){
        cin >> s[i].r >> s[i].c >> s[i].s >> s[i].d >> s[i].z;
        map[s[i].r][s[i].c] = i+1;
    }
    int fisher_pos = 0;
    while(fisher_pos <= C){
        fisher_pos++;
        catch_shark(fisher_pos,s);
        shark_move(s);
    }
    cout << ans << "\n";
}

