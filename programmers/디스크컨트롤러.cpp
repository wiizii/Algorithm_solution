#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; }

vector<vector<int>> wait;

vector<int> sjf() {
    int time = 0x3f3f3f3f;
    vector<int> tmp;
    auto rm = wait.begin();
    for (auto it = wait.begin(); it != wait.end(); it++) {
        if (time > (*it)[1]) {
            time = (*it)[1];
            tmp = *it;
            rm = it;
        }
    }
    wait.erase(rm);
    return tmp;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int runtime = 0;
    int cur = 0;
    vector<int> curJob;
    int jobStart = 0;
    bool stat = false;
    sort(jobs.begin(), jobs.end(), cmp);
    while (stat || !wait.empty() || cur < jobs.size()) {
        while (cur < jobs.size() && jobs[cur][0] == runtime) {
            wait.push_back(jobs[cur]);
            cur++;
        }
        if (stat && (runtime == jobStart + curJob[1])) {
            answer += jobStart + curJob[1] - curJob[0];
            stat = false;
        }
        if (!wait.empty() && !stat) {
            stat = true;
            curJob = sjf();
            jobStart = runtime;
        }
        runtime++;
    }
    return answer / jobs.size();
}