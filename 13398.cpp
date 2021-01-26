#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;

int arr[MAX];
int dp[MAX];
int dp2[MAX];

int main(){
  int n;
  int ans = 0;
  cin >> n;
  for(int i=0;i<n;i++)
    cin >> arr[i];
  dp[0] = dp2[0] = arr[0];

  ans = max(dp[0], dp2[0]);
  for(int i=1;i<n;i++){
    dp[i] = max(0,dp[i-1]) + arr[i];
    dp2[i] = max(dp2[i-1] + arr[i], dp[i-1]);
    ans = max(max(dp[i],dp2[i]), ans);
  }
    cout << ans << "\n";
}