#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int max(const int &a, const int &b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        queue<int> q;
        cin >> n >> k;
        vector<int> adj[n + 1];
        vector<int> idx(n + 1);
        vector<int> T(n + 1);
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            T[i] = ans[i] = a;
        }
        for (int i = 0; i < k; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            idx[v]++;
        }
        for (int i = 1; i <= n; i++)
            if (idx[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y : adj[x])
            {
                if (ans[y] < ans[x] + T[y])
                    ans[y] = ans[x] + T[y];
                idx[y]--;
                if (idx[y] == 0)
                    q.push(y);
            }
        }
        int w;
        cin >> w;
        cout << ans[w] << "\n";
    }
    return 0;
}
