#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> f{'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

bool isCorrect(const vector<string> &data) {
    for (int i = 0; i < data.size(); i++) {
        auto a = find(f.begin(), f.end(), data[i][0]);
        auto b = find(f.begin(), f.end(), data[i][2]);
        int num = data[i][4] - 48;
        int diff = abs(a - b) - 1;
        char cmp = data[i][3];
        if (cmp == '=' && diff != num) return false;
        if (cmp == '<' && diff >= num) return false;
        if (cmp == '>' && diff <= num) return false;
    }
    return true;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    do {
        if (isCorrect(data)) answer++;
    } while (next_permutation(f.begin(), f.end()));
    return answer;
}