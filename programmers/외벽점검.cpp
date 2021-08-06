#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INF;
    sort(dist.begin(), dist.end());
    for (int k = 0; k < weak.size(); k++) {
        int d = 0;
        int i = 0, j = 0;
        do {
            while (j < weak.size() && d < dist.size()) {
                if (weak[j] >= weak[i] && dist[d] >= weak[j] - weak[i])
                    j++;
                else if (weak[j] < weak[i] && dist[d] >= n - weak[i] + weak[j])
                    j++;
                else {
                    i = j;
                    d++;
                }
            }
            if (d != dist.size()) answer = min(answer, d);
            d = 0;
            i = weak.size() - 1, j = weak.size() - 1;
            while (d < dist.size() && j >= 0) {
                if (weak[i] >= weak[j] && dist[d] >= weak[i] - weak[j])
                    j--;
                else if (weak[i] < weak[j] && dist[d] >= n - weak[j] + weak[i])
                    j--;
                else {
                    i = j;
                    d++;
                }
            }
            if (d != dist.size()) answer = min(answer, d);
        } while (next_permutation(dist.begin(), dist.end()));
        weak.push_back(weak.front());
        weak.erase(weak.begin());
    }
    return answer == INF ? -1 : answer + 1;
}