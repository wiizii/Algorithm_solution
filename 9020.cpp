#include <iostream>
using namespace std;
#define max 10001
bool arr[max];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= max; i++)
        arr[i] = true;
    for (int i = 2; i*i <= max; i++) {
        if (arr[i])
            for (int j = i * i; j <= max; j += i)
                arr[j] = false;
    }
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=n/2,j=n/2; j <= n; i--,j++)
            if(arr[i] && arr[j]){
                cout << i << " " << j << "\n";
                break;
            }
    }
}
