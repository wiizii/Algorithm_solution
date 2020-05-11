#include <iostream>
using namespace std;

int isSix(int n){
    int six = 0;
    while(n>=1){
        if(n%10 == 6){
            six++;
            n/=10;
            if(six == 3)
                return 1;
        }
        else{
            six = 0;
            n/=10;
        }
    }
    return 0;
}

int main(){
    int N;
    cin >> N;
    int i = 666;
    int cnt = 0;
    while(1){
        if(isSix(i))
            cnt++;
        if(cnt == N)
            break;
        i++;
    }
    cout << i << "\n";
    
}
