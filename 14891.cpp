#include <iostream>
#include <cstdio>
using namespace std;

int gear[5][8];

void turnClockwise(int n){
    int tmp = gear[n][7];
    for(int i=7;i>0;i--)
        gear[n][i] = gear[n][i-1];
    gear[n][0] = tmp;
}
void turnAntiClockwise(int n){
    int tmp = gear[n][0];
    for(int i=0;i<7;i++)
        gear[n][i] = gear[n][i+1];
    gear[n][7] = tmp;
}

bool checkLeft(int n){
    if(gear[n][6] != gear[n-1][2])
        return 1;
    return 0;
}

bool checkRight(int n){
    if(gear[n][2] != gear[n+1][6])
        return 1;
    return 0;
}

void TURN(int start,int n,int d){
    if(checkLeft(n) && n != 1 && n <= start)
        TURN(start,n-1,-d);
    if(checkRight(n) && n != 4 && n >= start)
        TURN(start,n+1,-d);
    if(d == 1)
        turnClockwise(n);
    else
        turnAntiClockwise(n);
}

int getScore(){
    int sum = 0;
    for(int i=1;i<5;i++)
        if(gear[i][0])
            sum += 1 << (i-1);
    return sum;
}

int main(){
    for(int i=1;i<5;i++)
        for(int j=0;j<8;j++)
            scanf("%1d",&gear[i][j]);
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
        int num, dir;
        cin >> num >> dir;
        TURN(num,num,dir);
    }
    cout << getScore() << "\n";
    return 0;
}

