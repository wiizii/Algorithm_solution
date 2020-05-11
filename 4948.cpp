#include <iostream>
using namespace std;
bool arr[246913];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
    int n;
    cin >> n;
    if(n == 0)
        return 0;
    for (int i = 2; i <= 2*n; i++)
        arr[i] = true;
    
    for (int i = 2; i*i <= 2*n; i++) {
        if (arr[i])
            for (int j = i * i; j <= 2*n; j += i)
                arr[j] = false;
    }
    int count = 0;
    for(int i=n+1;i<=2*n;i++){
        if(arr[i])
            count++;
    }
    cout << count <<"\n";
    }
}
