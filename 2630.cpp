#include <cstdio>
using namespace std;
int a[128][128];
int white = 0;
int blue = 0;

int check(int x, int y, int l){
    int tmp=a[x][y];
    if(l == 1)
        return tmp;
    for(int i=x; i<x+l;i++)
        for(int j=y; j<y+l; j++){
            if(tmp != a[i][j])
                return -1;
        }
    if(tmp == 1)
        return 1;
    else
        return 0;
}

void cut(int x, int y, int l){
    int c = check(x,y,l);
    if(c == 0){
        white++;
        return;
    }
    else if(c == 1){
        blue++;
        return;
    }
    else
        cut(x,y,l/2);
        cut(x+(l/2),y,l/2);
        cut(x,y+(l/2),l/2);
        cut(x+(l/2),y+(l/2),l/2);
}

int main(){
    int N;
    int num;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &num);
            a[i][j] = num;
        }
    }
    cut(0,0,N);
    printf("%d\n%d\n", white, blue);
    
}
