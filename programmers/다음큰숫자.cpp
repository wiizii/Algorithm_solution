#include <iostream>
#include <string>
#include <vector>

using namespace std;

int binaryCounter(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n & 1) cnt++;
        n = n >> 1;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int size = binaryCounter(n);
    while (1) {
        n++;
        if (binaryCounter(n) == size) {
            answer = n;
            break;
        }
    }
    return answer;
}