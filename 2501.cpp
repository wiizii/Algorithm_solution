#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> ans;
  int n;
  int k;
  cin >> n >> k;
  for(int i=1;i*i<=n;i++){
    if(n%i == 0){
      ans.push_back(i);
      if(i != n/i)
        ans.push_back(n/i);
    }
  }
  sort(ans.begin(), ans.end());
  if(ans.size() >= k)
    cout << ans[k-1] << "\n";
  else
    cout << 0 << "\n";
}