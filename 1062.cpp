#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n, k;
int ans = 0;
string words[51];
bool check[26];

int getAns(){
  int ret = 0;
  for(int i=0;i<n;i++){
    bool flag = true;
    for(int j=4;j<words[i].size()-4;j++){
      if(!check[words[i][j]-97]){
        flag = false;
        break;
      }
    }
    if(flag)
      ret++;
  }
  return ret;
}

// 97 == a
void solve(int cnt, int start) {
    if (cnt == k - 5) {
        int tmp = getAns();
        ans = max(ans, tmp);
        return;
    }
    for (int i = start; i < 26; i++) {
        if (!check[i]) {
            check[i] = true;
            solve(cnt + 1, i + 1);
            check[i] = false;
        }
    }
}

int main() {
    char init[5] = {'a', 'n', 't', 'i', 'c'};
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    if (k < 5) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        check[init[i] - 97] = true;
    }
    solve(0, 1);
    cout << ans << "\n";
}