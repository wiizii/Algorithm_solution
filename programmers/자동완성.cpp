#include <bits/stdc++.h>

using namespace std;
const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'a'; }

struct TrieNode {
    TrieNode* children[ALPHABETS];

    int child;
    bool terminal;
    TrieNode() : child(0), terminal(false) {
        memset(children, 0, sizeof(children));
    }

    void insert(const char* key) {
        child++;
        if (*key == 0)
            terminal = true;
        else {
            int next = toNumber(*key);
            if (children[next] == NULL) children[next] = new TrieNode();
            children[next]->insert(key + 1);
        }
    }

    int find(const char* key, int cnt) {
        if (child == 1 || *key == 0) return cnt;
        int next = toNumber(*key);
        if (children[next] == NULL) return NULL;
        return children[next]->find(key + 1, cnt + 1);
    }
};

TrieNode trie;

int solution(vector<string> words) {
    int answer = 0;
    for (string& str : words) {
        trie.insert(str.c_str());
    }
    for (string& str : words) {
        answer += trie.find(str.c_str(), 0);
    }

    return answer;
}