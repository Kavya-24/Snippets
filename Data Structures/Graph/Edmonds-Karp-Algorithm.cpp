#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// BFS to find augmenting path
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int n = rGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                
                if (v == t) return true;
            }
        }
    }return false;
}

// Edmonds-Karp algorithm
int edmondsKarp(vector<vector<int>>& graph, int s, int t) {
    int n = graph.size();
    vector<vector<int>> rGraph = graph;
    vector<int> parent(n);
    int maxFlow = 0;
    
    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = INF;
        
        // Find minimum residual capacity along the path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }
        
        // Update residual capacities and reverse edges
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    int n = 6; // Number of nodes
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    // Add edges (from, to, capacity)
    graph[0][1] = 16; graph[0][2] = 13;
    graph[1][2] = 10; graph[1][3] = 12;
    graph[2][1] = 4;  graph[2][4] = 14;
    graph[3][2] = 9;  graph[3][5] = 20;
    graph[4][3] = 7;  graph[4][5] = 4;
    
    int s = 0, t = 5; // source and sink
    
    int maxFlow = edmondsKarp(graph, s, t);
    cout << "Maximum flow: " << maxFlow << endl;
    
    return 0;
}