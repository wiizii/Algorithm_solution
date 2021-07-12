#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

struct Node {
    int idx;
    bool isDeleted = false;
    bool isFirst = false;
    bool isLast = false;
    Node *prev = NULL;
    Node *next = NULL;
};

Node table[MAX];
Node *cursor;
stack<Node *> deleted;

void upNode(int x) {
    while (x--) cursor = cursor->prev;
}

void downNode(int x) {
    while (x--) cursor = cursor->next;
}

void deleteNode() {
    deleted.push(cursor);
    cursor->isDeleted = true;
    if (cursor->isFirst) {
        cursor = cursor->next;
        cursor->isFirst = true;
    } else if (cursor->isLast) {
        cursor = cursor->prev;
        cursor->isLast = true;
    } else {
        cursor->prev->next = cursor->next;
        cursor->next->prev = cursor->prev;
        cursor = cursor->next;
    }
}

void undoNode() {
    Node *tmp = deleted.top();
    deleted.pop();
    if (tmp->isFirst) {
        tmp->next->prev = tmp;
        tmp->next->isFirst = false;
    } else if (tmp->isLast) {
        tmp->prev->next = tmp;
        tmp->prev->isLast = false;
    } else {
        tmp->prev->next = tmp;
        tmp->next->prev = tmp;
    }
    tmp->isDeleted = false;
}

void tableInit(int n, int k) {
    for (int i = 0; i < n; i++) {
        table[i].idx = i;
        if (i != 0) table[i].prev = &table[i - 1];
        if (i != n - 1) table[i].next = &table[i + 1];
    }
    table[0].isFirst = true;
    table[n - 1].isLast = true;
    cursor = &table[k];
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    tableInit(n, k);
    for (auto s : cmd) {
        char c = s.front();
        if (c == 'U')
            upNode(stoi(s.substr(2)));
        else if (c == 'D')
            downNode(stoi(s.substr(2)));
        else if (c == 'C')
            deleteNode();
        else if (c == 'Z')
            undoNode();
    }
    for (int i = 0; i < n; i++) {
        if (table[i].isDeleted)
            answer.push_back('X');
        else
            answer.push_back('O');
    }
    return answer;
}