#include <iostream>
using namespace std;

int n;
int chu[31];
bool check[31][15001] = {0,};

void solve(int chuNum, int curWeight){
  if(chuNum > n)
    return;
  bool &cur = check[chuNum][curWeight];
  if(cur)
    return;
  cur = true;
  solve(chuNum + 1, curWeight + chu[chuNum]);
  solve(chuNum + 1, curWeight);
  solve(chuNum + 1, abs(curWeight - chu[chuNum]));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> chu[i];

    solve(0,0);

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        if(k <= 15000 && check[n][k])
          cout << "Y ";
        else
          cout << "N ";
    }
}