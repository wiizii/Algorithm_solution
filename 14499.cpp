#include <iostream>
using namespace std;

int map[20][20];
int N,M;
struct DICE{
    int x,y;
    int num[7];
    DICE(int nx,int ny){
        x = nx; y = ny;
        for(int i=0;i<7;i++)
            num[i] = 0;
    }
    void move(int k){
        if(k == 1){
            if(y+1 >= M)
                return;
            y++;
            int tmp = num[1];
            num[1] = num[4];
            num[4] = num[6];
            num[6] = num[3];
            num[3] = tmp;
        }
        if(k == 2){
            if(y-1 < 0)
                return;
            y--;
            int tmp = num[1];
            num[1] = num[3];
            num[3] = num[6];
            num[6] = num[4];
            num[4] = tmp;
        }
        if(k == 3){
            if(x-1 < 0)
                return;
            x--;
            int tmp = num[1];
            num[1] = num[5];
            num[5] = num[6];
            num[6] = num[2];
            num[2] = tmp;
        }
        if(k == 4){
            if(x+1 >= N)
                return;
            x++;
            int tmp = num[1];
            num[1] = num[2];
            num[2] = num[6];
            num[6] = num[5];
            num[5] = tmp;
        }
        if(map[x][y] == 0)
            map[x][y] = num[6];
        else{
            num[6] = map[x][y];
            map[x][y] = 0;
        }
        cout << num[1] << "\n";
    }
};

int main(){
    int x,y,k;
    cin >> N >> M >> x >> y >> k;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> map[i][j];
    DICE dice(x,y);
    for(int i=0;i<k;i++){
        int t;
        cin >> t;
        dice.move(t);
    }
    return 0;
}

