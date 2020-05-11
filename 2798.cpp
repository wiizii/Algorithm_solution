#include <iostream>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int arr[N];
    int temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        arr[i] = temp;
    }
    int sum=0;
    temp = 0;
    int i,j,k;
    
    for(i=0;i<N-2;i++){
        for(j=i+1;j<N-1;j++){
            for(k=j+1;k<N;k++){
                temp = arr[i]+arr[j]+arr[k];
                if(temp > M)
                    continue;
                if(temp > sum)
                    sum = temp;
            }
        }
    }
    cout << sum << endl;
}
