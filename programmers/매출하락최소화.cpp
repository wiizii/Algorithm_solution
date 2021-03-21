#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 300001;
const int INF = 0x3f3f3f3f;

vector<int> adj[MAX];
int cost[MAX];
int dp[MAX][2];

int solve(int node, bool sel){
    int &ret = dp[node][sel];
    int diff = INF;
    bool flag = false;
    if(ret)
        return ret;
    if(adj[node].empty())
        return dp[node][sel] = sel ? cost[node] : 0;
	for(int i=0;i<adj[node].size();i++){
        int next = adj[node][i];
        int next_sel = solve(next,true);
        int next_no_sel = solve(next,false);
 		ret += min(next_sel, next_no_sel);
        if(next_no_sel > next_sel)
            flag = true;
        diff = min(diff,next_sel-next_no_sel);
    }
    if(sel)
        ret += cost[node];
    else{
        if(!flag)
          ret += diff;
    }
    return ret;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    for(int i=0;i<sales.size();i++)
   		cost[i+1] = sales[i];
    for(int i=0;i<links.size();i++)
        adj[links[i][0]].push_back(links[i][1]);
    answer = min(solve(1,0),solve(1,1));
    return answer;
}