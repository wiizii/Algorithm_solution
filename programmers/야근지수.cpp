#include <string>
#include <queue>
#include <vector>

using namespace std;

priority_queue<long long> pq;

long long sqr(long long x){
    return x*x;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(auto i : works)
        pq.push((long long)i);
    for(int i=0;i<n;i++){
    	long long top = pq.top();
        pq.pop();
        top--;
        pq.push(top);
    }
    while(!pq.empty()){
        long long top = pq.top();
        pq.pop();
        if(top > 0)
            answer += sqr(top);
    }
    return answer;
}