#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long facto(int n) {
    long long ret = 1;
    for (long long i = 2; i <= n; i++) ret *= i;
    return ret;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> number;
    for (int i = 1; i <= n; i++) number.push_back(i);
    while (n > 0) {
        long long tmp = facto(n - 1);
        int i;
        for (i = 1; i * tmp < k; i++)
            ;
        auto it = number.begin();
        for (int j = 1; j < i; j++) it++;
        answer.push_back(*it);
        number.erase(it);
        k -= (i - 1) * tmp;
        n--;
    }
    return answer;
}