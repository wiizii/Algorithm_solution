#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int dist[101][101];
int n,m;

void floydWarshall(){
    for(int k=1; k <= n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)
                dist[i][j] = INF;
        }
    }
    
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v],w);
    }
    
    floydWarshall();
    
    for(int i=1;i<=n;i++){
        for(int j=1; j<=n;j++){
            if(dist[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
