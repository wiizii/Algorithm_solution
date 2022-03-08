#include <bits/stdc++.h>

using namespace std;

map<string, int> id;
set<int> re[1001];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    for(int i=0;i<id_list.size();i++){
        id[id_list[i]] = i;
    }

   	for(int i=0;i<report.size();i++){
        string tmp1 = "";
        string tmp2 = "";
        int idx = 0;
        while(report[i][idx] != ' '){
            tmp1 += report[i][idx++]; 
        }
        for(int j = idx+1;j<report[i].size();j++){
            tmp2 += report[i][j];
        }
        re[id[tmp2]].insert(id[tmp1]);
    }
    
    for(int i=0;i<id_list.size();i++){
        if(re[i].size() >= k){
            for(auto iter = re[i].begin(); iter != re[i].end(); iter++){
                answer[*iter]++;
            }
        }
    }
    return answer;
}
