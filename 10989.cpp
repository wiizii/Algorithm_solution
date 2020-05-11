#include <iostream>
using namespace std;
int arr[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        arr[tmp]++;
    }
    for(int i=1;i<=10000;i++){
        if(arr[i])
            for(int j=0;j<arr[i];j++)
                cout << i << "\n";
    }
}
