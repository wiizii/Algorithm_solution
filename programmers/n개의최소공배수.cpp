#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCM(int a, int b) { return a * b / GCD(a, b); }

int solution(vector<int> arr) {
    int answer = 1;
    for (int i = 0; i < arr.size(); i++) answer = LCM(answer, arr[i]);
    return answer;
}