#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1e18; 
vector<pair<int, int>> adj[100001]; 
vector<long long> dist;            
void dijkstra(int start, int n) {
    dist.assign(n + 1, INF); 
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();

        long long current_dist = top.first;
        int u = top.second;

        if (current_dist > dist[u])
            continue; 
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    int s, t; cin >> s >> t;
    dijkstra(s, n);

    if (dist[t] == INF)
        cout << -1 << endl; 
    else
        cout << dist[t] << endl;

    return 0;
}
