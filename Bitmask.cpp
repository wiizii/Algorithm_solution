#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int b = 0;
    int M;
    cin >> M;
    while(M--){
        string s;
        int n;
        cin >> s;
        if(s == "add"){
            cin >> n;
            b |=(1<<n);
        }
        else if(s == "remove"){
            cin >> n;
            b &= ~(1<<n);
        }
        else if(s == "check"){
            cin >> n;
            if(b & (1 << n))
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(s == "toggle"){
            cin >> n;
            b ^= (1 << n);
        }
        else if(s == "all"){
            b = (1 << 21) -1;
        }
        else if(s == "empty"){
            b = 0;
        }
    }
}
