#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long

using namespace std; 

struct log{
    int date, hour, min;
    double sec, during;
    log(string s){
        date = stoi(s.substr(8,2));
        hour = stoi(s.substr(11,2));
        min = stoi(s.substr(14,2));
        sec = stod(s.substr(17,6));
        during = stod(s.substr(24));
    }
};

log getStartLog(log &t){
    log ret = t;
    ret.sec -= t.during - 0.001;
    if(ret.sec < 0){
    	ret.sec += 60;
        ret.min--;
    }
    if(ret.min < 0){
        ret.min += 60;
        ret.hour--;
    }
    if(ret.hour < 0){
        ret.hour += 24;
        ret.date--;
    }
    return ret;
}
log getOneMinLater(log &t){
    log ret = t;
    ret.sec += 0.999;
    if(ret.sec >= 60){
        ret.sec -= 60;
        ret.min++;
    }
    if(ret.min >= 60){
        ret.min -=60;
        ret.hour++;
    }
    if(ret.hour >= 24){
        ret.hour -= 24;
        ret.date++;
    }
    return ret;
}

bool isMin(log &a, log &b){
    if(a.date < b.date)
        return true;
    else if(a.date == b.date){
        if(a.hour < b.hour)
            return true;
        else if(a.hour == b.hour){
            if(a.min < b.min)
                return true;
            else if(a.min == b.min){
               	if(a.sec <= b.sec)
                    return true;
                else return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

vector<pair<log,log>> v;

int solution(vector<string> lines) {
    int answer = 0;
    for(int i=0;i<lines.size();i++){
        log end(lines[i]);
        log start = getStartLog(end);
        v.push_back({start, end});
    }
    for(int i=0;i<v.size();i++){
        int cnt = 0;
        log start = v[i].first;
        log end = getOneMinLater(v[i].first);
        for(int j=0;j<v.size();j++)
            if(isMin(start,v[j].second) && isMin(v[j].first,end))
                cnt++;
        answer = max(answer, cnt);
        cnt = 0;
        start = v[i].second;
        end = getOneMinLater(v[i].second);
        for(int j=0;j<v.size();j++){
            if(isMin(start,v[j].second) && isMin(v[j].first,end))
                cnt++;
        }
        answer = max(answer, cnt);
    }
    return answer;
}