#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char arr[50][50];
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> arr[i][j];
    int result = 64;
    for(int i=0;i<N-7;i++){
        for(int j=0;j<M-7;j++){
            int cnt = 0;
            for(int k=0;k<8;k++)
                for(int l=0;l<8;l++)
                    cnt += (k%2 == l%2?'W':'B') == arr[i+k][j+l];
            result = min(result,cnt);
            result = min(result, 64-cnt);
        }
    }
    cout << result << "\n";
}
