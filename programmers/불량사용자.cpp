#include <set>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> ans;
vector<string> user, banned;
vector<string> selected;
bool check[8];

bool isAns() {
    for (int i = 0; i < banned.size(); i++) {
        if (banned[i].size() != selected[i].size()) return false;
        for (int j = 0; j < banned[i].size(); j++) {
            if (banned[i][j] != '*' && banned[i][j] != selected[i][j])
                return false;
        }
    }
    return true;
}

void solve(int cnt) {
    if (cnt == banned.size()) {
        if (isAns()) ans.push_back(selected);
        return;
    }
    for (int i = 0; i < user.size(); i++) {
        if (!check[i]) {
            check[i] = true;
            selected.push_back(user[i]);
            solve(cnt + 1);
            check[i] = false;
            selected.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id;
    banned = banned_id;
    solve(0);
    set<set<string>> s;
    for (int i = 0; i < ans.size(); i++) {
        set<string> tmp;
        for (int j = 0; j < ans[i].size(); j++) tmp.insert(ans[i][j]);
        s.insert(tmp);
    }
    return s.size();
}