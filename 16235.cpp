#include <iostream>
#include <deque>
using namespace std;

int N, M, K;
int A[11][11];
int food[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

struct Tree {
    int x, y, z;
    Tree(int x, int y, int z) :x(x), y(y), z(z) {}
};

deque<Tree> tree;
deque<Tree> dead;

void spring() {
    deque<Tree> tmp;
    for (auto &t : tree) {
        if (food[t.x][t.y] >= t.z) {
            food[t.x][t.y] -= t.z;
            t.z++;
            tmp.push_back(t);
        }
        else
            dead.push_back(t);
    }
    tree = tmp;
}

void summer() {
    for(auto &d : dead)
        food[d.x][d.y] += d.z / 2;
    dead.clear();
}

void autumm() {
    for (int i = 0; i < tree.size(); i++) {
        if (tree[i].z % 5 == 0) {
            for (int j = 0; j < 8; j++) {
                int nx = tree[i].x + dx[j];
                int ny = tree[i].y + dy[j];
                if (nx <= 0 || nx > N || ny <= 0 || ny > N)
                    continue;
                tree.push_front({ nx,ny,1 });
                i++;
            }
        }
    }   
}

void winter() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            food[i][j] += A[i][j];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            food[i][j] = 5;
        }
    }

    int x, y, z;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        tree.push_back({ x,y,z });
    }

    while (K--) {
        spring();
        summer();
        autumm();
        winter();
    }
    cout << tree.size() << "\n";
    return 0;
}

