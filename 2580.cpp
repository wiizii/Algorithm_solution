#include <iostream>
#include <cstdlib>
using namespace std;

int arr[9][9];

bool check_v(int x, int num){
    for(int i=0;i<9;i++)
        if(arr[x][i] == num)
            return true;
    return false;
}

bool check_h(int y, int num){
    for(int i=0;i<9;i++)
        if(arr[i][y] == num)
            return true;
    return false;
}

bool check_sq(int x, int y, int num){
    x = (x/3)*3;
    y = (y/3)*3;
    for(int i=x;i<x+3;i++)
        for(int j=y;j<y+3;j++)
            if(arr[i][j] == num)
                return true;
    return false;
}

int check_all(int x, int y, int num){
    if(check_v(x,num)||check_h(y,num)||check_sq(x,y,num))
        return true;
    return false;
}

void solve(int cnt){
    if(cnt == 81){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    int x = cnt/9;
    int y = cnt%9;
    if(!arr[x][y]){
        for(int k=1;k<=9;k++){
            if(!check_all(x, y, k)){
                arr[x][y] = k;
                solve(cnt+1);
                arr[x][y] = 0;
            }
        }
    }
    else
        solve(cnt+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin >> arr[i][j];
    solve(0);
}
