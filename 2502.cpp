#include <iostream>
using namespace std;

int solve(int a, int b, int n){
  if(n == 1)
    return a;
  if(n == 2)
    return b;
  return solve(a,b,n-1) + solve(a,b,n-2);
}

int main(){
  int d,k;
  cin >> d >> k;
  for(int i=0;i<4000;i++){
    for(int j=i;j<4000;j++){
      if(solve(i,j,d) == k){
        cout << i << "\n" << j << "\n";
        break;
      }
    }
  }
}