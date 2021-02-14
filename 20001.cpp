#include <string>
#include <iostream>
using namespace std;

int main(){
  int p = 0;
  while(1){
    string s;
    getline(cin, s);
    if(s == "문제")
      p++;
    else if(p == 0 && s == "고무오리")
      p+=2;
    else if(p != 0 && s == "고무오리")
      p--;
    else if(s == "고무오리 디버깅 끝")
      break;
  }
  if(p == 0)
  cout << "고무오리야 사랑해\n";
  else
  cout << "힝구\n";
}