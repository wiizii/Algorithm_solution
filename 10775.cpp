#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100000 + 1;

int parent[MAX];

int Find(int x){
    if(x == parent[x])
        return x;
    else{
        int p = Find(parent[x]);
        parent[x] = p;
        return p;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int G,P;
    cin >> G >> P;
    for(int i=1;i<=G;i++)
        parent[i] = i;

    int ans, tmp,val;

    for(ans = 0; ans < P ; ans++){
        cin >> val;
        tmp = Find(val);
        if(!tmp)
            break;
        parent[tmp] = tmp - 1;
    }
    cout << ans << "\n";
    return 0;
}
