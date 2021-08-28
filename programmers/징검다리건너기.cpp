#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<int> &s, int k, int mid) {
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < mid) {
            tmp++;
            if (tmp >= k) return false;
        } else
            tmp = 0;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (check(stones, k, mid)) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}