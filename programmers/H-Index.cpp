#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for (int mid = citations.back(); mid >= 0; mid--) {
        int low = 0, high = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] < mid)
                low++;
            else if (citations[i] == mid) {
                low++;
                high++;
            } else
                high++;
        }
        if (low <= mid && high >= mid) {
            answer = mid;
            break;
        }
    }
    return answer;
}