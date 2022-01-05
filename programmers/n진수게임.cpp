#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

stack<int> st;

void modifyN(int number, int n) {
    while (number > 0) {
        st.push(number % n);
        number /= n;
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    st.push(0);
    int number = 1;
    int order = 1;
    while (answer.size() != t) {
        if (st.empty()) {
            modifyN(number, n);
            number++;
        }
        if (order == p) {
            if (st.top() < 10)
                answer += to_string(st.top());
            else if (st.top() == 10)
                answer += "A";
            else if (st.top() == 11)
                answer += "B";
            else if (st.top() == 12)
                answer += "C";
            else if (st.top() == 13)
                answer += "D";
            else if (st.top() == 14)
                answer += "E";
            else if (st.top() == 15)
                answer += "F";
            p += m;
        }
        st.pop();
        order++;
    }
    return answer;
}