#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int> > num(n);
    for(int i=0;i<n;i++)
        cin >> num[i].second >> num[i].first;
    sort(num.begin(),num.end());
    for(int i=0;i<n;i++)
        cout << num[i].second <<" "<< num[i].first<<"\n";
}
