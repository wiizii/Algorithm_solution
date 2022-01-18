#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> cache;

void makeSmallCase(string &str) {
    for (int i = 0; i < str.size(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') str[i] += 32;
    }
}

int solution(int cacheSize, vector<string> cities) {
    int runningTime = 0;
    if (cacheSize == 0) return 5 * cities.size();
    for (int i = 0; i < cities.size(); i++) {
        makeSmallCase(cities[i]);
        auto iter = find(cache.begin(), cache.end(), cities[i]);
        if (iter != cache.end()) {
            cache.erase(iter);
            cache.push_back(cities[i]);
            runningTime += 1;
        } else {
            if (cache.size() < cacheSize)
                cache.push_back(cities[i]);
            else {
                cache.erase(cache.begin());
                cache.push_back(cities[i]);
            }
            runningTime += 5;
        }
    }
    return runningTime;
}