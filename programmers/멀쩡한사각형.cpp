#include <algorithm>
using namespace std;

long long solution(int w, int h) {
    long long answer = 0;
    if (h > w) swap(h, w);
    double a = (double)h / w;
    for (int i = 1; i < w; i++) answer += (long long)(a * i);
    return answer * 2;
}