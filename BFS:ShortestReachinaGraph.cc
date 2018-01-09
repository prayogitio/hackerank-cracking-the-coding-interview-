#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> distances;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    distances[src] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (distances[v] < 0) {
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int queries;
    cin >> queries;
    for (int t = 0; t < queries; t++) {
        int n, m;
        cin >> n;
        cin >> m;
        adj.clear();
        adj.resize(max(n,m));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int startId;
        cin >> startId;
        startId--;
        distances.assign(n, -1);
        bfs(startId);
        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                if (distances[i] != -1) {
                    distances[i] = distances[i] * 6;
                }
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
